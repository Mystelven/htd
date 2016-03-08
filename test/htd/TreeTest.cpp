/*
 * File:   TreeTest.cpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 *
 * Copyright 2015, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 *
 * This file is part of htd.
 *
 * htd is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * htd is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>

#include <htd/main.hpp>

#include <vector>

class TreeTest : public ::testing::Test
{
    public:
        TreeTest(void)
        {

        }

        ~TreeTest()
        {

        }

        void SetUp()
        {

        }

        void TearDown()
        {

        }
};

TEST(TreeTest, CheckEmptyTree)
{
    htd::Tree tree;

    ASSERT_EQ((std::size_t)0, tree.vertexCount());
    ASSERT_EQ((std::size_t)0, tree.edgeCount());

    ASSERT_EQ((std::size_t)0, tree.vertices().size());
    ASSERT_EQ((std::size_t)0, tree.hyperedges().size());

    ASSERT_EQ((std::size_t)0, tree.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, tree.isolatedVertices().size());

    ASSERT_TRUE(tree.isConnected());

    ASSERT_EQ((std::size_t)0, tree.leafNodeCount());

    ASSERT_EQ((std::size_t)0, tree.isolatedVertexCount());

    try
    {
        tree.root();

        FAIL();
    }
    catch (const std::logic_error & error)
    {
        HTD_UNUSED(error);
    }
}

TEST(TreeTest, CheckSize1Tree)
{
    htd::Tree tree;

    ASSERT_EQ((std::size_t)0, tree.vertexCount());
    ASSERT_EQ((std::size_t)0, tree.edgeCount());

    ASSERT_EQ((std::size_t)0, tree.vertices().size());
    ASSERT_EQ((std::size_t)0, tree.hyperedges().size());

    ASSERT_EQ((std::size_t)0, tree.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, tree.isolatedVertices().size());

    ASSERT_TRUE(tree.isConnected());

    ASSERT_EQ((std::size_t)0, tree.leafNodeCount());

    ASSERT_EQ((std::size_t)0, tree.isolatedVertexCount());

    try
    {
        tree.root();

        FAIL();
    }
    catch (const std::logic_error & error)
    {
        HTD_UNUSED(error);
    }

    htd::vertex_t root = tree.insertRoot();

    ASSERT_TRUE(tree.isVertex(root));
    ASSERT_TRUE(tree.isRoot(root));
    ASSERT_EQ(root, tree.root());

    ASSERT_EQ((std::size_t)1, tree.vertexCount());
    ASSERT_EQ((std::size_t)0, tree.edgeCount());

    ASSERT_EQ((std::size_t)1, tree.vertices().size());
    ASSERT_EQ((std::size_t)0, tree.hyperedges().size());

    ASSERT_EQ((std::size_t)1, tree.isolatedVertexCount());
    ASSERT_EQ((std::size_t)1, tree.isolatedVertices().size());

    ASSERT_TRUE(tree.isConnected());

    ASSERT_EQ((std::size_t)1, tree.leafNodeCount());

    ASSERT_EQ((std::size_t)1, tree.isolatedVertexCount());
    ASSERT_EQ(root, tree.isolatedVertices()[0]);
    ASSERT_EQ(root, tree.isolatedVertexAtPosition(0));
    ASSERT_TRUE(tree.isIsolatedVertex(root));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
