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

#include <cmath>
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
using Result_umap = std::unordered_map<NodeID_T, ResultPrimitive<NodeID_T>>;
// typedef std::unordered_map<NodeID_T, ResultPrimitive<NodeID_T>> Result;

/**
 * Runs Dijkstra's algorithm from a `start_node`, optionally avoiding nodes
 * `avoid_nodes` and edges `avoid_edges`. If the Algorithm shall terminate
 * early when an end node is reached, `end_node` can be specified as a node
 * name instead of a `std::monostate`. Then only the path between `start_node`
 * and `end_node` is reliable. The resulting weight of each path includes the
 * start and the final node weights. Post Processing is required if that is not
 * wished to be the case.
 *
 * NOTE: If `avoid_edges` are to be considered bidirectional (so if a->b is
 * given, then b->a is also to be avoided), call
 * `bidirectionalize(avoid_edges)` or specify both directions explicitly.
 */
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
Algorithm::Dijkstra::Result_umap<NodeID_T> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
    const NodeID_T& start_node,
    std::unordered_set<NodeID_T> avoid_nodes        = {},
    uset_of_edges<NodeID_T> avoid_edges             = uset_of_edges<NodeID_T>{},
    std::variant<std::monostate, NodeID_T> end_node = std::monostate());

/**
 * Returns the cheapest path between `start_node` and `end_node` as a vector of
 * Node IDs passed through in order. This is based on a `result`, which is the
 * output of Algorithm::Dijkstra::run(). Beware of the limitations imposed
 * based on the parametrization of that instance of run(). This involves which
 * node is the actual `start_node` as well as which nodes are eligible to be
 * `end_node` (e.g. because of early termination or avoidance of nodes/edges).
 */
template <IntegralOrString NodeID_T>
std::vector<NodeID_T> cheapest_path(
    Algorithm::Dijkstra::Result_umap<NodeID_T> &result,
    const NodeID_T &start_node,
    const NodeID_T &end_node);
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
Algorithm::Dijkstra::Result_umap<NodeID_T> run(
    ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T> &graph,
    const NodeID_T& start_node,
    std::unordered_set<NodeID_T> avoid_nodes,
    uset_of_edges<NodeID_T> avoid_edges,
    std::variant<std::monostate, NodeID_T> end_node)
{
    using distance         = double;
    bool abort_at_end_node = std::holds_alternative<NodeID_T>(end_node);
    Algorithm::Dijkstra::Result_umap<NodeID_T> result;

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

template <IntegralOrString NodeID_T>
std::vector<NodeID_T> cheapest_path(
    Algorithm::Dijkstra::Result_umap<NodeID_T> &result,
    const NodeID_T &start_node,
    const NodeID_T &end_node)
{
        /**
         * Initialize with an empty path.
         */
        std::vector<NodeID_T> cheapest_path;

        /**
         * Test for reachability
         */
         
        if (std::isinf(result.at(end_node).distance))
        {
            /**
             * Unreachable, return an empty path
             */
            return cheapest_path;
        }
        
        /**
         * Begin with the end node and walk backwards
         */
        std::vector<NodeID_T> cheapest_path_reverse;
        NodeID_T curr_node = end_node;
        cheapest_path_reverse.push_back(curr_node);
        while (curr_node != start_node)
        {
            curr_node = result.at(curr_node).predecessor;
            cheapest_path_reverse.push_back(curr_node);
        }

        /**
         * Reverse, since we want to output the path forwards, not
         * backwards as we assembled it.
         */
        cheapest_path.reserve(cheapest_path_reverse.size());
        for (auto it = cheapest_path_reverse.rbegin();
             it != cheapest_path_reverse.rend();
             it++)
        {
            cheapest_path.push_back(*it);
        }

        /**
         * Done!
         */
        return cheapest_path;
}

} // namespace Dijkstra

} // namespace Algorithm

} // namespace KnoKan
#endif // _KNOKAN_ALGORITHMTOOLS_DIJKSTRA_HPP