/**
 * KnoKan
 * Graph Library.
 * Dijkstra Algorithm Tools
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */
#ifndef _KNOKAN_ALGORITHMTOOLS_DIJKSTRA_HPP
#define _KNOKAN_ALGORITHMTOOLS_DIJKSTRA_HPP

#include "../graphs/ProtoGraph.hpp"
#include "../misc/Edge.hpp"
#include "../misc/concepts.hpp"

#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

/*=========================================================================
 * Declaration
 */
namespace KnoKan
{

namespace Algorithm
{

namespace Dijkstra
{
template <IntegralOrString NodeID_T> struct ResultPrimitive
{
    double distance;
    NodeID_T predecessor;
};

template <IntegralOrString NodeID_T>
using Result = std::unordered_map<NodeID_T, ResultPrimitive<NodeID_T>>;
// typedef std::unordered_map<NodeID_T, ResultPrimitive<NodeID_T>> Result;

/**
 * Runs Dijkstra's algorithm from a `start_node`, optionally avoiding nodes
 * `avoid_nodes` and edges `avoid_edges`. If the Algorithm shall terminate
 * early when an end node is reached, `end_node` can be specified as a node
 * name instead of a `std::monostate`. Then only the path between `start_node`
 * and `end_node` is reliable. The resulting weight of each path includes the
 * start and the final node weights. Post Processing is required if that is not
 * wished to be the case.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
Algorithm::Dijkstra::Result<NodeID_T> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
    NodeID_T start_node,
    std::unordered_set<NodeID_T> avoid_nodes = {},
    std::unordered_set<Edge<NodeID_T>, EdgeHash<NodeID_T>> avoid_edges =
        std::unordered_set<Edge<NodeID_T>, EdgeHash<NodeID_T>>{},
    std::variant<std::monostate, NodeID_T> end_node = std::monostate());

} // namespace Dijkstra

} // namespace Algorithm

} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{

namespace Algorithm
{

namespace Dijkstra
{

template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
Algorithm::Dijkstra::Result<NodeID_T> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
    NodeID_T start_node,
    std::unordered_set<NodeID_T> avoid_nodes,
    std::unordered_set<Edge<NodeID_T>, EdgeHash<NodeID_T>> avoid_edges,
    std::variant<std::monostate, NodeID_T> end_node)
{
    using distance         = double;
    bool abort_at_end_node = std::holds_alternative<NodeID_T>(end_node);
    Algorithm::Dijkstra::Result<NodeID_T> result;

    /**
     * Comparison lambda for pair of cost and node
     */
    auto cmp = [](std::pair<distance, NodeID_T> &left,
                  std::pair<distance, NodeID_T> &right) {
        return left.first > right.first;
    };
    /**
     * Priority Queue to store cost of edges and target node.
     */
    std::priority_queue<std::pair<distance, NodeID_T>,
                        std::vector<std::pair<distance, NodeID_T>>,
                        decltype(cmp)>
        pq(cmp);

    /**
     * Initialize all distances with infinity
     */
    for (auto &[src_node, _] : graph.adjacency_map)
    {
        result[src_node].distance = std::numeric_limits<distance>::infinity();
    }
    /**
     * Start node has a distance of its own weight to itself
     */
    result[start_node].distance = graph.get_node_weight(start_node);

    /**
     * Insert the start node with distance of its own weight
     */
    pq.push({result[start_node].distance, start_node});

    while (!pq.empty())
    {
        auto [current_dist, current_node] = pq.top();
        pq.pop();

        /**
         * Skip if we found a better path
         */
        if (current_dist > result[current_node].distance)
        {
            continue;
        }

        /**
         * Early exit if the target node is reached
         */
        if (abort_at_end_node)
        {
            if (current_node == std::get<NodeID_T>(end_node))
            {
                break;
            }
        }

        /**
         * Visit each neighbor of the current node
         */
        for (auto &neighbor : graph.adjacency_map.at(current_node))
        {
            /**
             * Only visit neighbors not in the avoid list (nodes)
             */
            if (avoid_nodes.find(neighbor) == avoid_nodes.end())
            {
                /**
                 * Only visit neighbors not in the avoid list (edges)
                 */
                Edge<NodeID_T> curr_edge{current_node, neighbor};
                if (!avoid_edges.empty())
                {
                    if (avoid_edges.find(curr_edge) != avoid_edges.end())
                    {
                        continue;
                    }
                }

                /**
                 * At this point the neighbor node is legal to visit.
                 * Update the edge cost for it. Add the Node cost of the
                 * neighbor to this edge. This is how nodes are considered.
                 * This evidently does not add the starting node but does add
                 * the end node cost to it. However this is easy to fix by the
                 * user if the total cost is necessary for either variant.
                 */
                distance new_dist = current_dist +
                                    graph.get_edge_weight(curr_edge) +
                                    graph.get_node_weight(neighbor);

                /**
                 * If a shorter path is found
                 */
                if (new_dist < result[neighbor].distance)
                {
                    result[neighbor].distance = new_dist;
                    pq.push({new_dist, neighbor});
                    result[neighbor].predecessor = current_node;
                }
            }
        }
    }

    /**
     * If aborted early, only the target node distance and path (via
     * previous) is guaranteed to be correct.
     */
    return result;
}

} // namespace Dijkstra

} // namespace Algorithm

} // namespace KnoKan
#endif // _KNOKAN_ALGORITHMTOOLS_DIJKSTRA_HPP