/**
 * KnoKan
 * Graph Library.
 * ProtoGraph. The base of all graphs.
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_PROTO_GRAPH_HPP
#define _KNOKAN_PROTO_GRAPH_HPP

#include "../misc/Edge.hpp"
#include "../misc/PropertyBase.hpp"
#include "../misc/concepts.hpp"

#include <list>
#include <unordered_map>
#include <utility>

/*=========================================================================
 * Declaration
 */
namespace KnoKan
{

template <IntegralOrString NodeID_T, std::derived_from<PropertyBase> Property_T>
class ProtoGraph
{
  protected:
    /**
     * Stores the adjacency list showing if a Node ID is pointing at another.
     * This is implicitly directed.
     */
    std::unordered_map<NodeID_T, std::list<NodeID_T>> adjacency_map;
    /**
     * Stores the properties for each node
     */
    std::unordered_map<NodeID_T, Property_T> node_properties;
    /**
     * Stores the properties for each edge. This is implicitly directed.
     */
    std::unordered_map<Edge<NodeID_T>, Property_T, EdgeHash<NodeID_T>>
        edge_properties;

  public:
    /**
     * Adds a node with a `node_id` into the graph if it does not already
     * exist. Attaches the `node_property` to it. If a node was added that way,
     * returns `true`, otherwise (so nothing happened) it returns `false`.
     */
    bool add_node(const NodeID_T &node_id, Property_T node_property);

    /**
     * Gets all nodes in the graph as a vector of Node IDs.
     */
    std::vector<NodeID_T> get_all_nodes();
};

} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{
template <IntegralOrString NodeID_T, std::derived_from<PropertyBase> Property_T>
bool ProtoGraph<NodeID_T, Property_T>::add_node(const NodeID_T &node_id,
                                                Property_T node_property)
{
    if (adjacency_map.find(node_id) == adjacency_map.end())
    {
        node_properties[node_id] = std::move(node_property);
        adjacency_map[node_id]   = std::list<NodeID_T>();
        return true;
    }
    else
    {
        return false;
    }
}

template <IntegralOrString NodeID_T, std::derived_from<PropertyBase> Property_T>
std::vector<NodeID_T> ProtoGraph<NodeID_T, Property_T>::get_all_nodes()
{
    std::vector<NodeID_T> all_nodes;

    for (auto &[node_id, _] : adjacency_map)
    {
        all_nodes.push_back(node_id);
    }

    return all_nodes;
}

} // namespace KnoKan

#endif // _KNOKAN_PROTO_GRAPH_HPP