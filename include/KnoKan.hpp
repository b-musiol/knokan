/**
 * KnoKan
 * Graph Library.
 * Main Header
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_HPP
#define _KNOKAN_HPP

#ifdef KNOKAN_DIRECTED_GRAPH
#include "graphs/DirectedGraph.hpp"
#endif
#ifdef KNOKAN_UNDIRECTED_GRAPH
#include "graphs/UndirectedGraph.hpp"
#endif

#ifdef KNOKAN_ALGORITHM_DIJKSTRA
#include "algorithms/Dijkstra.hpp"
#endif

#ifdef KNOKAN_ALGORITHM_TARJAN
#include "algorithms/Tarjan.hpp"
#endif

#endif // _KNOKAN_HPP