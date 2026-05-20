/**
 * KnoKan
 * Graph Library.
 * Tests
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#include "../include/KnoKan.hpp"
#include <gtest/gtest.h>
#include <set>
#include <string>
#include <unordered_set>

TEST(KnoKan_UndirectedGraph, int_Nodes)
{
    KnoKan::UndirectedGraph<int,
                            KnoKan::UniWeightProperty,
                            KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
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
    KnoKan::UndirectedGraph<std::string,
                            KnoKan::UniWeightProperty,
                            KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
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

TEST(KnoKan_UndirectedGraph, const_char_string_Nodes)
{
    KnoKan::UndirectedGraph<const char *,
                            KnoKan::UniWeightProperty,
                            KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
    std::unordered_set<const char *> expected{"0sometext",
                                              "1sometext",
                                              "2sometext",
                                              "3sometext",
                                              "4sometext"};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node("2sometext", prop));

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
    KnoKan::
        DirectedGraph<int, KnoKan::UniWeightProperty, KnoKan::UniWeightProperty>
            pg;
    KnoKan::UniWeightProperty prop;
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
    KnoKan::DirectedGraph<std::string,
                          KnoKan::UniWeightProperty,
                          KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
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

TEST(KnoKan_DirectedGraph, const_char_string_Nodes)
{
    KnoKan::DirectedGraph<const char *,
                          KnoKan::UniWeightProperty,
                          KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
    std::unordered_set<const char *> expected{"0sometext",
                                              "1sometext",
                                              "2sometext",
                                              "3sometext",
                                              "4sometext"};
    for (auto &value : expected)
    {
        EXPECT_TRUE(pg.add_node(value, prop));
    }
    // Shouldn't be able to add another 2
    EXPECT_FALSE(pg.add_node("2sometext", prop));

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
    KnoKan::
        DirectedGraph<int, KnoKan::UniWeightProperty, KnoKan::UniWeightProperty>
            pg;
    KnoKan::UniWeightProperty prop;
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
    KnoKan::UndirectedGraph<int,
                            KnoKan::UniWeightProperty,
                            KnoKan::UniWeightProperty>
        pg;
    KnoKan::UniWeightProperty prop;
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