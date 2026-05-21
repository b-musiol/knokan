/**
 * KnoKan
 * Graph Library.
 * Tests
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#define KNOKAN_DIRECTED_GRAPH
#define KNOKAN_UNDIRECTED_GRAPH
#define KNOKAN_ALGORITHM_DIJKSTRA
#include "../include/KnoKan.hpp"
#include <format>
#include <gtest/gtest.h>
// #include <iostream>
#include <cmath>
#include <list>
#include <set>
#include <string>
#include <unordered_set>

using namespace KnoKan::Property::Predefined;

TEST(KnoKan_UndirectedGraph, int_Nodes)
{
    KnoKan::UndirectedGraph<int, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<int> expected{1, 2, 3, 7, -4};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node(2, prop));

    auto all_nodes_return = pg.get_all_nodes();
    EXPECT_EQ(all_nodes_return.size(), expected.size());
    for (auto &node_id : all_nodes_return)
    {
        auto it = expected.find(node_id);
        if (it != expected.end())
        {
            expected.erase(it);
        }
    }
    EXPECT_EQ(expected.size(), 0);
}

TEST(KnoKan_UndirectedGraph, string_Nodes)
{
    KnoKan::UndirectedGraph<std::string, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<std::string> expected{std::string("0sometext"),
                                             std::string("1sometext"),
                                             std::string("2sometext"),
                                             std::string("3sometext"),
                                             std::string("4sometext")};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node(std::string("2sometext"), prop));

    auto all_nodes_return = pg.get_all_nodes();
    EXPECT_EQ(all_nodes_return.size(), expected.size());
    for (auto &node_id : all_nodes_return)
    {
        auto it = expected.find(node_id);
        if (it != expected.end())
        {
            expected.erase(it);
        }
    }
    EXPECT_EQ(expected.size(), 0);
}

TEST(KnoKan_DirectedGraph, int_Nodes)
{
    KnoKan::DirectedGraph<int, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<int> expected{1, 2, 3, 7, -4};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node(2, prop));

    auto all_nodes_return = pg.get_all_nodes();
    EXPECT_EQ(all_nodes_return.size(), expected.size());
    for (auto &node_id : all_nodes_return)
    {
        auto it = expected.find(node_id);
        if (it != expected.end())
        {
            expected.erase(it);
        }
    }
    EXPECT_EQ(expected.size(), 0);
}

TEST(KnoKan_DirectedGraph, string_Nodes)
{
    KnoKan::DirectedGraph<std::string, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<std::string> expected{std::string("0sometext"),
                                             std::string("1sometext"),
                                             std::string("2sometext"),
                                             std::string("3sometext"),
                                             std::string("4sometext")};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node(std::string("2sometext"), prop));

    auto all_nodes_return = pg.get_all_nodes();
    EXPECT_EQ(all_nodes_return.size(), expected.size());
    for (auto &node_id : all_nodes_return)
    {
        auto it = expected.find(node_id);
        if (it != expected.end())
        {
            expected.erase(it);
        }
    }
    EXPECT_EQ(expected.size(), 0);
}

TEST(KnoKan_DirectedGraph, int_Edges)
{
    KnoKan::DirectedGraph<int, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }

    std::set<KnoKan::Edge<int>> expected_edges{KnoKan::Edge<int>{1, 2},
                                               KnoKan::Edge<int>{2, 3},
                                               KnoKan::Edge<int>{1, 7},
                                               KnoKan::Edge<int>{-4, 7}};
    for (auto &[n1, n2] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(n1, n2, prop));
    }
    EXPECT_FALSE(pg.add_edge(1, 6, prop));
    EXPECT_FALSE(pg.add_edge(5, 2, prop));
    EXPECT_TRUE(pg.add_edge(1, 2, prop));

    auto all_edges_return = pg.get_all_edges();
    EXPECT_EQ(all_edges_return.size(), expected_edges.size());
    for (auto &edge_id : all_edges_return)
    {
        auto it = expected_edges.find(edge_id);
        if (it != expected_edges.end())
        {
            expected_edges.erase(it);
        }
    }
    EXPECT_EQ(expected_edges.size(), 0);
}

TEST(KnoKan_UndirectedGraph, int_Edges)
{
    KnoKan::UndirectedGraph<int, UniWeight, UniWeight> pg;
    UniWeight prop;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }

    std::set<KnoKan::Edge<int>> expected_edges{KnoKan::Edge<int>{1, 2},
                                               KnoKan::Edge<int>{2, 3},
                                               KnoKan::Edge<int>{1, 7},
                                               KnoKan::Edge<int>{-4, 7}};
    for (auto &[n1, n2] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(n1, n2, prop));
    }
    EXPECT_FALSE(pg.add_edge(1, 6, prop));
    EXPECT_FALSE(pg.add_edge(5, 2, prop));
    EXPECT_TRUE(pg.add_edge(1, 2, prop));

    expected_edges.insert(KnoKan::Edge<int>{2, 1});
    expected_edges.insert(KnoKan::Edge<int>{3, 2});
    expected_edges.insert(KnoKan::Edge<int>{7, 1});
    expected_edges.insert(KnoKan::Edge<int>{7, -4});

    auto all_edges_return = pg.get_all_edges();
    EXPECT_EQ(all_edges_return.size(), expected_edges.size());
    for (auto &edge_id : all_edges_return)
    {
        auto it = expected_edges.find(edge_id);
        if (it != expected_edges.end())
        {
            expected_edges.erase(it);
        }
    }
    EXPECT_EQ(expected_edges.size(), 0);
}

TEST(KnoKan_UndirectedGraph, int_get_weights)
{
    KnoKan::UndirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }
    EXPECT_FALSE(pg.add_node(2, SimpleWeight(5)));

    std::set<KnoKan::Edge<int>> expected_edges{KnoKan::Edge<int>{1, 2},
                                               KnoKan::Edge<int>{2, 3},
                                               KnoKan::Edge<int>{1, 7},
                                               KnoKan::Edge<int>{-4, 7}};
    for (auto &[n1, n2] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(n1, n2, SimpleWeight(4)));
    }
    EXPECT_FALSE(pg.add_edge(1, 6, SimpleWeight(2)));
    EXPECT_FALSE(pg.add_edge(5, 2, SimpleWeight(2)));
    EXPECT_TRUE(pg.add_edge(1, 2, SimpleWeight(2)));

    expected_edges.insert(KnoKan::Edge<int>{2, 1});
    expected_edges.insert(KnoKan::Edge<int>{3, 2});
    expected_edges.insert(KnoKan::Edge<int>{7, 1});
    expected_edges.insert(KnoKan::Edge<int>{7, -4});

    auto all_edges_return = pg.get_all_edges();
    EXPECT_EQ(all_edges_return.size(), expected_edges.size());
    for (auto &edge_id : all_edges_return)
    {
        auto it = expected_edges.find(edge_id);
        if (it != expected_edges.end())
        {
            expected_edges.erase(it);
        }
    }
    EXPECT_EQ(expected_edges.size(), 0);

    EXPECT_EQ(pg.get_edge_weight(KnoKan::Edge<int>{2, 3}), 4.0);
    EXPECT_EQ(pg.get_edge_weight(KnoKan::Edge<int>{3, 2}), 4.0);

    EXPECT_EQ(pg.get_node_weight(3), 2.0);
}

TEST(KnoKan_DirectedGraph, int_get_weights)
{
    KnoKan::DirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }
    EXPECT_FALSE(pg.add_node(2, SimpleWeight(5)));

    std::set<KnoKan::Edge<int>> expected_edges{KnoKan::Edge<int>{1, 2},
                                               KnoKan::Edge<int>{2, 3},
                                               KnoKan::Edge<int>{1, 7},
                                               KnoKan::Edge<int>{-4, 7}};
    for (auto &[n1, n2] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(n1, n2, SimpleWeight(4)));
    }
    EXPECT_FALSE(pg.add_edge(1, 6, SimpleWeight(2)));
    EXPECT_FALSE(pg.add_edge(5, 2, SimpleWeight(2)));
    EXPECT_TRUE(pg.add_edge(1, 2, SimpleWeight(2)));

    auto all_edges_return = pg.get_all_edges();
    EXPECT_EQ(all_edges_return.size(), expected_edges.size());
    for (auto &edge_id : all_edges_return)
    {
        auto it = expected_edges.find(edge_id);
        if (it != expected_edges.end())
        {
            expected_edges.erase(it);
        }
    }
    EXPECT_EQ(expected_edges.size(), 0);

    EXPECT_EQ(pg.get_edge_weight(KnoKan::Edge<int>{2, 3}), 4.0);

    EXPECT_EQ(pg.get_node_weight(3), 2.0);
}

TEST(KnoKan_UndirectedGraph, int_dijkstra)
{
    KnoKan::UndirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }

    std::list<std::pair<KnoKan::Edge<int>, SimpleWeight>> expected_edges{
        {KnoKan::Edge<int>{1, 2}, SimpleWeight(2)},
        {KnoKan::Edge<int>{2, 3}, SimpleWeight(3)},
        {KnoKan::Edge<int>{1, 7}, SimpleWeight(4)},
        {KnoKan::Edge<int>{-4, 7}, SimpleWeight(5)},
        {KnoKan::Edge<int>{-4, 3}, SimpleWeight(6)}};
    for (auto &[edge, weight] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to, weight));
    }

    KnoKan::Algorithm::Dijkstra::Result_umap<int> dijkstra_result =
        KnoKan::Algorithm::Dijkstra::run<int, SimpleWeight, SimpleWeight>(pg,
                                                                          2);
    for (auto &[node, result] : dijkstra_result)
    {
        switch (node)
        {
        case -4:
            EXPECT_FLOAT_EQ(result.distance, 15);
            EXPECT_EQ(result.predecessor, 3);
            break;
        case 7:
            EXPECT_FLOAT_EQ(result.distance, 12);
            EXPECT_EQ(result.predecessor, 1);
            break;
        case 3:
            EXPECT_FLOAT_EQ(result.distance, 7);
            EXPECT_EQ(result.predecessor, 2);
            break;
        case 2:
            EXPECT_FLOAT_EQ(result.distance, 2);
            EXPECT_EQ(result.predecessor, 0);
            break;
        case 1:
            EXPECT_FLOAT_EQ(result.distance, 6);
            EXPECT_EQ(result.predecessor, 2);
            break;
        }
    }
    std::vector<int> path =
        KnoKan::Algorithm::Dijkstra::cheapest_path<int>(dijkstra_result, 2, 7);

    std::vector<int> expected_path = {2, 1, 7};
    EXPECT_EQ(path, expected_path);
}

TEST(KnoKan_UndirectedGraph, int_dijkstra_avoid_edge)
{
    KnoKan::UndirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }

    std::list<std::pair<KnoKan::Edge<int>, SimpleWeight>> expected_edges{
        {KnoKan::Edge<int>{1, 2}, SimpleWeight(2)},
        {KnoKan::Edge<int>{2, 3}, SimpleWeight(3)},
        {KnoKan::Edge<int>{1, 7}, SimpleWeight(4)},
        {KnoKan::Edge<int>{-4, 7}, SimpleWeight(5)},
        {KnoKan::Edge<int>{-4, 3}, SimpleWeight(6)}};
    for (auto &[edge, weight] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to, weight));
    }

    KnoKan::Algorithm::Dijkstra::Result_umap<int> dijkstra_result =
        KnoKan::Algorithm::Dijkstra::run<int, SimpleWeight, SimpleWeight>(
            pg,
            2,
            {},
            {KnoKan::Edge<int>(1, 7)});
    for (auto &[node, result] : dijkstra_result)
    {
        switch (node)
        {
        case -4:
            EXPECT_FLOAT_EQ(result.distance, 15);
            EXPECT_EQ(result.predecessor, 3);
            break;
        case 7:
            EXPECT_FLOAT_EQ(result.distance, 22);
            EXPECT_EQ(result.predecessor, -4);
            break;
        case 3:
            EXPECT_FLOAT_EQ(result.distance, 7);
            EXPECT_EQ(result.predecessor, 2);
            break;
        case 2:
            EXPECT_FLOAT_EQ(result.distance, 2);
            EXPECT_EQ(result.predecessor, 0);
            break;
        case 1:
            EXPECT_FLOAT_EQ(result.distance, 6);
            EXPECT_EQ(result.predecessor, 2);
            break;
        }
        std::cout << std::format("Node: {}; Predecessor: {}; weight: {}",
                                 node,
                                 result.predecessor,
                                 result.distance)
                  << "\n";
    }
    std::vector<int> path =
        KnoKan::Algorithm::Dijkstra::cheapest_path<int>(dijkstra_result, 2, 7);

    std::vector<int> expected_path = {2, 3, -4, 7};
    EXPECT_EQ(path, expected_path);
}

TEST(KnoKan_UndirectedGraph, int_dijkstra_avoid_node)
{
    KnoKan::UndirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }

    std::list<std::pair<KnoKan::Edge<int>, SimpleWeight>> expected_edges{
        {KnoKan::Edge<int>{1, 2}, SimpleWeight(2)},
        {KnoKan::Edge<int>{2, 3}, SimpleWeight(3)},
        {KnoKan::Edge<int>{1, 7}, SimpleWeight(4)},
        {KnoKan::Edge<int>{-4, 7}, SimpleWeight(5)},
        {KnoKan::Edge<int>{-4, 3}, SimpleWeight(6)}};
    for (auto &[edge, weight] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to, weight));
    }

    KnoKan::Algorithm::Dijkstra::Result_umap<int> dijkstra_result =
        KnoKan::Algorithm::Dijkstra::run<int, SimpleWeight, SimpleWeight>(pg,
                                                                          2,
                                                                          {1});
    for (auto &[node, result] : dijkstra_result)
    {
        switch (node)
        {
        case -4:
            EXPECT_FLOAT_EQ(result.distance, 15);
            EXPECT_EQ(result.predecessor, 3);
            break;
        case 7:
            EXPECT_FLOAT_EQ(result.distance, 22);
            EXPECT_EQ(result.predecessor, -4);
            break;
        case 3:
            EXPECT_FLOAT_EQ(result.distance, 7);
            EXPECT_EQ(result.predecessor, 2);
            break;
        case 2:
            EXPECT_FLOAT_EQ(result.distance, 2);
            EXPECT_EQ(result.predecessor, 0);
            break;
        case 1:
            EXPECT_TRUE(std::isinf(result.distance));
            EXPECT_EQ(result.predecessor, 0);
            break;
        }
    }
    std::vector<int> path =
        KnoKan::Algorithm::Dijkstra::cheapest_path<int>(dijkstra_result, 2, 7);

    std::vector<int> expected_path = {2, 3, -4, 7};
    EXPECT_EQ(path, expected_path);
}

TEST(KnoKan_UndirectedGraph, int_dijkstra_avoid_node_and_edge)
{
    KnoKan::UndirectedGraph<int, SimpleWeight, SimpleWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 7, -4};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, SimpleWeight(2)));
    }

    std::list<std::pair<KnoKan::Edge<int>, SimpleWeight>> expected_edges{
        {KnoKan::Edge<int>{1, 2}, SimpleWeight(2)},
        {KnoKan::Edge<int>{2, 3}, SimpleWeight(3)},
        {KnoKan::Edge<int>{1, 7}, SimpleWeight(4)},
        {KnoKan::Edge<int>{2, -4}, SimpleWeight(1)},
        {KnoKan::Edge<int>{-4, 7}, SimpleWeight(5)},
        {KnoKan::Edge<int>{-4, 3}, SimpleWeight(6)}};
    for (auto &[edge, weight] : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to, weight));
    }

    KnoKan::Algorithm::Dijkstra::Result_umap<int> dijkstra_result =
        KnoKan::Algorithm::Dijkstra::run<int, SimpleWeight, SimpleWeight>(
            pg,
            2,
            {1},
            KnoKan::bidirectionalize<int>({KnoKan::Edge<int>(-4, 2)}));
    for (auto &[node, result] : dijkstra_result)
    {
        switch (node)
        {
        case -4:
            EXPECT_FLOAT_EQ(result.distance, 15);
            EXPECT_EQ(result.predecessor, 3);
            break;
        case 7:
            EXPECT_FLOAT_EQ(result.distance, 22);
            EXPECT_EQ(result.predecessor, -4);
            break;
        case 3:
            EXPECT_FLOAT_EQ(result.distance, 7);
            EXPECT_EQ(result.predecessor, 2);
            break;
        case 2:
            EXPECT_FLOAT_EQ(result.distance, 2);
            EXPECT_EQ(result.predecessor, 0);
            break;
        case 1:
            EXPECT_TRUE(std::isinf(result.distance));
            EXPECT_EQ(result.predecessor, 0);
            break;
        }
    }
    std::vector<int> path =
        KnoKan::Algorithm::Dijkstra::cheapest_path<int>(dijkstra_result, 2, 7);

    std::vector<int> expected_path = {2, 3, -4, 7};
    EXPECT_EQ(path, expected_path);
}