/**
 * KnoKan
 * Graph Library.
 * Tarjan Algorithm Tools
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */
#ifndef _KNOKAN_ALGORITHMTOOLS_TARJAN_HPP
#define _KNOKAN_ALGORITHMTOOLS_TARJAN_HPP

#include "../graphs/ProtoGraph.hpp"
#include "../misc/Edge.hpp"
#include "../misc/concepts.hpp"
#include <cstdint>

/*=========================================================================
 * Declaration
 */
namespace KnoKan
{

namespace Algorithm
{

namespace Tarjan
{
/**
 * Executes Tarjan's Algorithm in a `graph` to find all bridges.
 * Scales linearly [O(V+E)]
 * It is not defined which direction of the edge the Algorithm finds in case of
 * a bidirectional edge, but it finds one of the two possible directions each.
 * If both directions are absolutely needed, call bidirectionalize() on the
 * output.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
std::vector<Edge<NodeID_T>> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph);
namespace _util
{
/**
 * Helper core for Trajan's algorithm. Should not be called in userspace.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
void find_bridges(ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
                  NodeID_T u,
                  NodeID_T parent,
                  std::unordered_map<NodeID_T, std::uint64_t> &disc,
                  std::unordered_map<NodeID_T, std::uint64_t> &low,
                  std::unordered_set<NodeID_T> &visited,
                  std::vector<Edge<NodeID_T>> &bridges,
                  std::uint64_t &time);
} // namespace _util
} // namespace Tarjan
} // namespace Algorithm
} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{

namespace Algorithm
{

namespace Tarjan
{

template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
std::vector<Edge<NodeID_T>> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph)
{
    std::vector<Edge<NodeID_T>> bridges;
    std::unordered_map<NodeID_T, std::uint64_t> disc, low;
    std::unordered_set<NodeID_T> visited;
    std::uint64_t time = 0;

    for (const auto &[node, _] : graph.adjacency_map)
    {
        if (visited.find(node) == visited.end())
        {
            _util::find_bridges(graph,
                                node,
                                node,
                                disc,
                                low,
                                visited,
                                bridges,
                                time);
        }
    }
    return bridges;
}

namespace _util
{
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
void find_bridges(ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
                  NodeID_T u,
                  NodeID_T parent,
                  std::unordered_map<NodeID_T, std::uint64_t> &disc,
                  std::unordered_map<NodeID_T, std::uint64_t> &low,
                  std::unordered_set<NodeID_T> &visited,
                  std::vector<Edge<NodeID_T>> &bridges,
                  std::uint64_t &time)
{
    visited.insert(u);
    time++;
    disc[u] = low[u] = time;

    for (auto v : graph.adjacency_map.at(u))
    {
        if (v == parent)
            continue; // Skip the edge to parent

        if (visited.find(v) == visited.end()) // If not visited
        {
            find_bridges(graph, v, u, disc, low, visited, bridges, time);

            // Update the low-link value
            low[u] = std::min(low[u], low[v]);

            // If `low[v]` is greater than `disc[u]`, we found a bridge
            if (low[v] > disc[u])
                bridges.push_back({u, v});
        }
        else // Back edge case
        {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}
} // namespace _util
} // namespace Tarjan
} // namespace Algorithm
} // namespace KnoKan

#endif //_KNOKAN_ALGORITHMTOOLS_TARJAN_HPP