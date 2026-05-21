/**
 * KnoKan
 * Graph Library.
 * Dijkstra Algorithm Tools
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */
#ifndef _KNOKAN_ALGORITHMTOOLS_DFS_HPP
#define _KNOKAN_ALGORITHMTOOLS_DFS_HPP

#include "../graphs/ProtoGraph.hpp"
#include "../misc/Edge.hpp"
#include "../misc/concepts.hpp"

/*=========================================================================
 * Declaration
 */
namespace KnoKan
{

namespace Algorithm
{

namespace DFS
{
/**
 * Checks if a path from `start_node` to `end_node` exists with the
 * Depth-First-Search-Algorithm. Stops when `end_node` is reached.
 * Optionally allows to `avoid_nodes` or to `avoid_edges` during the
 * search.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
bool path_exists(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
    const NodeID_T &start_node,
    const NodeID_T &end_node,
    std::unordered_set<NodeID_T> avoid_nodes = {},
    uset_of_edges<NodeID_T> avoid_edges      = uset_of_edges<NodeID_T>{});

namespace _utils
{
/**
 * Recursive Depth-First-Search allowing for avoiding nodes and edges.
 * Requires a pre-made `visited` set and a `curr_path` vector if this is
 * not the recursive call. Returns if `target_node` has been encountered
 * and unwinds the entire stack in that moment.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
bool DFS(ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
         const NodeID_T &ref_node,
         const NodeID_T &target_node,
         std::unordered_set<NodeID_T> &visited,
         std::vector<NodeID_T> &curr_path,
         std::unordered_set<NodeID_T> avoid_nodes,
         uset_of_edges<NodeID_T> avoid_edges);
} // namespace _utils

} // namespace DFS
} // namespace Algorithm
} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{

namespace Algorithm
{

namespace DFS
{
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
bool path_exists(ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
                 const NodeID_T &start_node,
                 const NodeID_T &end_node,
                 std::unordered_set<NodeID_T> avoid_nodes,
                 uset_of_edges<NodeID_T> avoid_edges)
{
    std::unordered_set<NodeID_T> visited;
    std::vector<NodeID_T> curr_path;
    return _utils::DFS(graph,
                       start_node,
                       end_node,
                       visited,
                       curr_path,
                       avoid_nodes,
                       avoid_edges);
}

namespace _utils
{
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
bool DFS(ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
         const NodeID_T &ref_node,
         const NodeID_T &target_node,
         std::unordered_set<NodeID_T> &visited,
         std::vector<NodeID_T> &curr_path,
         std::unordered_set<NodeID_T> avoid_nodes,
         uset_of_edges<NodeID_T> avoid_edges)
{
    // Put the current node into the visited set and the current path.
    visited.insert(ref_node);
    curr_path.push_back(ref_node);

    if (ref_node == target_node)
    {
        // We have hit the target node
        return true;
    }

    for (NodeID_T neighbor : graph.adjacency_map[ref_node])
    {
        // Do not visit banned nodes
        if (avoid_nodes.find(neighbor) == avoid_nodes.end())
        {
            // Do not visit banned edges
            if (avoid_edges.find(Edge<NodeID_T>(ref_node, neighbor)) ==
                avoid_edges.end())
            {
                // Do not revisit nodes
                if (visited.find(neighbor) == visited.end())
                {
                    bool target_is_hit = DFS(graph,
                                             neighbor,
                                             target_node,
                                             visited,
                                             curr_path,
                                             avoid_nodes,
                                             avoid_edges);
                    if (target_is_hit)
                    {
                        // If the target has been hit, we propagate that all
                        // back.
                        return true;
                    }
                }
            }
        }
    }
    // We have not hit the target node
    return false;
}
} // namespace _utils
} // namespace DFS
} // namespace Algorithm
} // namespace KnoKan

#endif // _KNOKAN_ALGORITHMTOOLS_DFS_HPP