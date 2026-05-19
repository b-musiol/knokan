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

#include "../misc/PropertyBase.hpp"
#include "../misc/concepts.hpp"

namespace KnoKan
{

template <IntegralOrString NodeID_T, std::derived_from<PropertyBase> Property_T>
class ProtoGraph
{
};

} // namespace KnoKan

#endif // _KNOKAN_PROTO_GRAPH_HPP