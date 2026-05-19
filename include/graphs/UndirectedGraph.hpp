/**
 * KnoKan
 * Graph Library.
 * Undirected Graph
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_UNDIRECTED_GRAPH_HPP
#define _KNOKAN_UNDIRECTED_GRAPH_HPP

#include "ProtoGraph.hpp"

namespace KnoKan
{

template <IntegralOrString NodeID_T, std::derived_from<PropertyBase> Property_T>
class UndirectedGraph : public KnoKan::ProtoGraph<NodeID_T, Property_T>
{
};

} // namespace KnoKan

#endif // _KNOKAN_UNDIRECTED_GRAPH_HPP