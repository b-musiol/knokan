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
#include <string>
#include <unordered_set>

TEST(KnoKan_ProtoGraph, int_Nodes)
{
    KnoKan::ProtoGraph<int, KnoKan::UniWeightProperty> pg;
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

TEST(KnoKan_ProtoGraph, string_Nodes)
{
    KnoKan::ProtoGraph<std::string, KnoKan::UniWeightProperty> pg;
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

TEST(KnoKan_ProtoGraph, const_char_string_Nodes)
{
    KnoKan::ProtoGraph<const char *, KnoKan::UniWeightProperty> pg;
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