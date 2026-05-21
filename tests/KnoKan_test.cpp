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
#define KNOKAN_ALGORITHM_TARJAN
#define KNOKAN_ALGORITHM_DFS
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
        KnoKan::Algorithm::Dijkstra::run(pg, 2);
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
        KnoKan::Algorithm::Dijkstra::run(pg, 2, {}, {KnoKan::Edge<int>(1, 7)});
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
        KnoKan::Algorithm::Dijkstra::run(pg, 2, {1});
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
        KnoKan::Algorithm::Dijkstra::run(
            pg,
            2,
            {1},
            KnoKan::bidirectionalize<int>(
                KnoKan::uset_of_edges<int>{KnoKan::Edge<int>(-4, 2)}));
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

TEST(KnoKan_UndirectedGraph, int_tarjan)
{
    KnoKan::UndirectedGraph<int, UniWeight, UniWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<int>> expected_edges{
        {KnoKan::Edge<int>{1, 2}},
        {KnoKan::Edge<int>{2, 3}},
        {KnoKan::Edge<int>{3, 1}},
        {KnoKan::Edge<int>{3, 4}},
        {KnoKan::Edge<int>{4, 5}},
        {KnoKan::Edge<int>{5, 6}},
        {KnoKan::Edge<int>{4, 6}},
        {KnoKan::Edge<int>{6, 7}},
        {KnoKan::Edge<int>{7, 8}},
        {KnoKan::Edge<int>{8, 9}},
        {KnoKan::Edge<int>{7, 9}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    auto expected_bridges = KnoKan::bidirectionalize(KnoKan::uset_of_edges<int>{
        KnoKan::Edge<int>{3, 4},
        KnoKan::Edge<int>{6, 7},
    });

    std::vector<KnoKan::Edge<int>> bridges = KnoKan::Algorithm::Tarjan::run(pg);
    EXPECT_EQ(bridges.size() * 2, expected_bridges.size());
    for (auto &bridge : bridges)
    {
        EXPECT_NE(expected_bridges.find(bridge), expected_bridges.end());
    }
    auto given_bridges = KnoKan::bidirectionalize(bridges);
    auto given_bridges_uset =
        KnoKan::uset_of_edges<int>(given_bridges.begin(), given_bridges.end());
    EXPECT_EQ(expected_bridges, given_bridges_uset);
}

TEST(KnoKan_DirectedGraph, int_tarjan)
{
    KnoKan::DirectedGraph<int, UniWeight, UniWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<int>> expected_edges{
        {KnoKan::Edge<int>{1, 2}},
        {KnoKan::Edge<int>{2, 3}},
        {KnoKan::Edge<int>{3, 1}},
        {KnoKan::Edge<int>{3, 4}},
        {KnoKan::Edge<int>{4, 5}},
        {KnoKan::Edge<int>{5, 6}},
        {KnoKan::Edge<int>{6, 4}},
        {KnoKan::Edge<int>{6, 7}},
        {KnoKan::Edge<int>{7, 9}},
        {KnoKan::Edge<int>{9, 8}},
        {KnoKan::Edge<int>{8, 7}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    std::vector<KnoKan::Edge<int>> expected_bridges = {
        KnoKan::Edge<int>{3, 4},
        KnoKan::Edge<int>{6, 7},
    };

    std::vector<KnoKan::Edge<int>> bridges = KnoKan::Algorithm::Tarjan::run(pg);
    auto uset_expected_bridges =
        KnoKan::uset_of_edges<int>(expected_bridges.begin(),
                                   expected_bridges.end());
    auto uset_bridges =
        KnoKan::uset_of_edges<int>(bridges.begin(), bridges.end());
    EXPECT_EQ(uset_expected_bridges, uset_bridges);
}

TEST(KnoKan_DirectedGraph, int_DFS)
{
    KnoKan::DirectedGraph<int, UniWeight, UniWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<int>> expected_edges{
        {KnoKan::Edge<int>{1, 2}},
        {KnoKan::Edge<int>{2, 3}},
        {KnoKan::Edge<int>{3, 1}},
        {KnoKan::Edge<int>{4, 5}},
        {KnoKan::Edge<int>{5, 6}},
        {KnoKan::Edge<int>{6, 4}},
        {KnoKan::Edge<int>{7, 9}},
        {KnoKan::Edge<int>{9, 8}},
        {KnoKan::Edge<int>{8, 7}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg, 1, 3));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg, 2, 6));

    EXPECT_TRUE(pg.add_edge(3, 4));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg, 2, 6));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg, 6, 2));
}

TEST(KnoKan_UndirectedGraph, int_DFS)
{
    KnoKan::UndirectedGraph<int, UniWeight, UniWeight> pg;
    std::unordered_set<int> expected_nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<int>> expected_edges{
        {KnoKan::Edge<int>{1, 2}},
        {KnoKan::Edge<int>{2, 3}},
        {KnoKan::Edge<int>{3, 1}},
        {KnoKan::Edge<int>{4, 5}},
        {KnoKan::Edge<int>{5, 6}},
        {KnoKan::Edge<int>{6, 4}},
        {KnoKan::Edge<int>{7, 9}},
        {KnoKan::Edge<int>{9, 8}},
        {KnoKan::Edge<int>{8, 7}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg, 1, 3));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg, 2, 6));

    EXPECT_TRUE(pg.add_edge(3, 4));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg, 2, 6));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg, 6, 2));
}

TEST(KnoKan_DirectedGraph, string_DFS)
{
    KnoKan::DirectedGraph<std::string, UniWeight, UniWeight> pg;
    std::unordered_set<std::string> expected_nodes{std::string("1"),
                                                   std::string("2"),
                                                   std::string("3"),
                                                   std::string("4"),
                                                   std::string("5"),
                                                   std::string("6"),
                                                   std::string("7"),
                                                   std::string("8"),
                                                   std::string("9")};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<std::string>> expected_edges{
        {KnoKan::Edge<std::string>{std::string("1"), std::string("2")}},
        {KnoKan::Edge<std::string>{std::string("2"), std::string("3")}},
        {KnoKan::Edge<std::string>{std::string("3"), std::string("1")}},
        {KnoKan::Edge<std::string>{std::string("4"), std::string("5")}},
        {KnoKan::Edge<std::string>{std::string("5"), std::string("6")}},
        {KnoKan::Edge<std::string>{std::string("6"), std::string("4")}},
        {KnoKan::Edge<std::string>{std::string("7"), std::string("9")}},
        {KnoKan::Edge<std::string>{std::string("9"), std::string("8")}},
        {KnoKan::Edge<std::string>{std::string("8"), std::string("7")}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                    std::string("1"),
                                                    std::string("3")));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                     std::string("2"),
                                                     std::string("6")));

    EXPECT_TRUE(pg.add_edge(std::string("3"), std::string("4")));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                    std::string("2"),
                                                    std::string("6")));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                     std::string("6"),
                                                     std::string("2")));
}

TEST(KnoKan_UndirectedGraph, string_DFS)
{
    KnoKan::UndirectedGraph<std::string, UniWeight, UniWeight> pg;
    std::unordered_set<std::string> expected_nodes{std::string("1"),
                                                   std::string("2"),
                                                   std::string("3"),
                                                   std::string("4"),
                                                   std::string("5"),
                                                   std::string("6"),
                                                   std::string("7"),
                                                   std::string("8"),
                                                   std::string("9")};
    for (auto &value : expected_nodes)
    {
        EXPECT_TRUE(pg.add_node(value, UniWeight()));
    }

    std::list<KnoKan::Edge<std::string>> expected_edges{
        {KnoKan::Edge<std::string>{std::string("1"), std::string("2")}},
        {KnoKan::Edge<std::string>{std::string("2"), std::string("3")}},
        {KnoKan::Edge<std::string>{std::string("3"), std::string("1")}},
        {KnoKan::Edge<std::string>{std::string("4"), std::string("5")}},
        {KnoKan::Edge<std::string>{std::string("5"), std::string("6")}},
        {KnoKan::Edge<std::string>{std::string("6"), std::string("4")}},
        {KnoKan::Edge<std::string>{std::string("7"), std::string("9")}},
        {KnoKan::Edge<std::string>{std::string("9"), std::string("8")}},
        {KnoKan::Edge<std::string>{std::string("8"), std::string("7")}},

    };
    for (auto &edge : expected_edges)
    {
        EXPECT_TRUE(pg.add_edge(edge.from, edge.to));
    }

    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                    std::string("1"),
                                                    std::string("3")));
    EXPECT_FALSE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                     std::string("2"),
                                                     std::string("6")));

    EXPECT_TRUE(pg.add_edge(std::string("3"), std::string("4")));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                    std::string("2"),
                                                    std::string("6")));
    EXPECT_TRUE(KnoKan::Algorithm::DFS::path_exists(pg,
                                                    std::string("6"),
                                                    std::string("2")));
}

TEST(KnoKan_UndirectedGraph, adding_empty_nodes)
{
    KnoKan::UndirectedGraph<std::string, UniWeight, UniWeight> pg;

    EXPECT_TRUE(pg.add_node("a", UniWeight()));
    EXPECT_TRUE(pg.add_node("b"));
}