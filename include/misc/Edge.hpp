#ifndef _KNOKAN_HASH_HPP
#define _KNOKAN_HASH_HPP

#include "concepts.hpp"
#include <functional>

namespace KnoKan
{

/**
 * Edge type
 */
template <IntegralOrString NodeID_T> struct Edge
{
    NodeID_T from;
    NodeID_T to;

    bool operator==(const Edge &) const                  = default;
    std::strong_ordering operator<=>(const Edge &) const = default;
    Edge(NodeID_T from, NodeID_T to) : from(from), to(to)
    {
    }
};

template <IntegralOrString NodeID_T> struct EdgeHash
{
    std::size_t operator()(const Edge<NodeID_T> &p) const noexcept
    {
        std::size_t h1 = std::hash<NodeID_T>{}(p.from);
        std::size_t h2 = std::hash<NodeID_T>{}(p.to);

        return h1 ^ (h2 << 1);
    }
};

} // namespace KnoKan

#endif // _KNOKAN_HASH_HPP