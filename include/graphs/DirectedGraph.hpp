/**
 * KnoKan
 * Graph Library.
 * Directed Graph
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_DIRECTED_GRAPH_HPP
#define _KNOKAN_DIRECTED_GRAPH_HPP

#include "ProtoGraph.hpp"

/*=========================================================================
 * Declaration
 */
namespace KnoKan
{

template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
class DirectedGraph
    : public KnoKan::ProtoGraph<NodeID_T, Node_Property_T, Edge_Property_T>
{
  public:
    /**
     * Adds a directed edge `from_node_id` `to_node_id` and attaches an
     * `edge_property`. If a node was added that way, returns `true`, otherwise
     * (so nothing happened) it returns `false`. This method can be used to
     * overwrite the edge property with a different entry.
     */
    bool add_edge(const NodeID_T &from_node_id,
                  const NodeID_T &to_node_id,
                  Edge_Property_T edge_property) override;
};

} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{
template <IntegralOrString NodeID_T,
          std::derived_from<Property::Base> Node_Property_T,
          std::derived_from<Property::Base> Edge_Property_T>
bool DirectedGraph<NodeID_T, Node_Property_T, Edge_Property_T>::add_edge(
    const NodeID_T &from_node_id,
    const NodeID_T &to_node_id,
    Edge_Property_T edge_property)
{
    // To add an edge, we define that nodes must exist first. No implicit
    // adding of nodes, because nodes need to have their properties.
    // A node existing is equivalent to the entry in the adjacency map
    // existing, even if it is empty. So at first we check the existence of
    // both nodes
    if (this->adjacency_map.find(from_node_id) != this->adjacency_map.end())
    {
        // The "from" node exists at this point
        if (this->adjacency_map.find(to_node_id) != this->adjacency_map.end())
        {
            // The "to" node exists as well at this point.
            // Thus we can add the edge between existing nodes
            // This is directed, so we add it in only one direction
            this->adjacency_map.at(from_node_id).insert(to_node_id);
            // Also adding the edge property
            this->edge_properties[Edge(from_node_id, to_node_id)] =
                std::move(edge_property);
            return true;
        }
        else // (this->adjacency_map.find(to_node_id) ==
             // this->adjacency_map.end)
        {
            // The "to" node does not exist at this point. So we refuse to add
            // the edge.
            return false;
        }
    }
    else // (this->adjacency_map.find(from_node_id) == this->adjacency_map.end)
    {
        // The "from" node does not exist at this point. So we refuse to add
        // the edge.
        return false;
    }
}
} // namespace KnoKan

#endif // _KNOKAN_DIRECTED_GRAPH_HPP