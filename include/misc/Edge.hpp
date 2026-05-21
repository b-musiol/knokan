#ifndef _KNOKAN_HASH_HPP
#define _KNOKAN_HASH_HPP

#include "concepts.hpp"
#include <functional>
#include <set>
#include <unordered_set>

/*=========================================================================
 * Declaration
 */
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
    Edge()                                               = default;
    Edge(NodeID_T from, NodeID_T to) : from(from), to(to)
    {
    }
    /**
     * Swaps the Nodes `from` and `to` in place.
     */
    void invert();
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

template <IntegralOrString NodeID_T>
using uset_of_edges = std::unordered_set<Edge<NodeID_T>, EdgeHash<NodeID_T>>;

/**
 * Returns a new `edge_set`, where for all edges if only the edge a->b is
 * encountered, the edge b->a is also added in. Does not change the original
 * `edge_set` in place.
 */
template <IntegralOrString NodeID_T>
uset_of_edges<NodeID_T> bidirectionalize(uset_of_edges<NodeID_T> &edge_set);

} // namespace KnoKan

/*=========================================================================
 * Definition
 */
namespace KnoKan
{
template <IntegralOrString NodeID_T> void Edge<NodeID_T>::invert()
{
    auto tmp   = this->from;
    this->from = this->to;
    this->to   = tmp;
}

template <IntegralOrString NodeID_T>
uset_of_edges<NodeID_T> bidirectionalize(std::set<Edge<NodeID_T>> &edge_set)
{
    uset_of_edges<NodeID_T> bidirectionalized;

    for (auto &curr_edge : edge_set)
    {
        bidirectionalized.insert(curr_edge);
        bidirectionalized.insert(curr_edge.invert());
    }

    return bidirectionalized;
}

} // namespace KnoKan
#endif // _KNOKAN_HASH_HPP