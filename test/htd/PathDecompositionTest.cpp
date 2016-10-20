/*
 * File:   PathDecompositionTest.cpp
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

class PathDecompositionTest : public ::testing::Test
{
    public:
        PathDecompositionTest(void)
        {

        }

        virtual ~PathDecompositionTest()
        {

        }

        void SetUp()
        {

        }

        void TearDown()
        {

        }
};

TEST(PathDecompositionTest, CheckEmptyPath)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition(libraryInstance);

    ASSERT_EQ((std::size_t)0, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());

    ASSERT_EQ((std::size_t)0, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)0, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)0, decomposition.leafCount());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());

    ASSERT_EQ(htd::Vertex::FIRST, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST, decomposition.nextEdgeId());

    delete libraryInstance;
}

TEST(PathDecompositionTest, CheckSize1Path)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition(libraryInstance);

    ASSERT_EQ((std::size_t)0, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());

    ASSERT_EQ((std::size_t)0, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)0, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)0, decomposition.leafCount());

    htd::vertex_t root = decomposition.insertRoot();

    ASSERT_TRUE(decomposition.isVertex(root));
    ASSERT_TRUE(decomposition.isRoot(root));
    ASSERT_EQ(root, decomposition.root());

    ASSERT_EQ((std::size_t)1, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition.vertexCount(root));
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount(root));

    ASSERT_EQ((std::size_t)1, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)0, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)1, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)1, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)1, decomposition.leafCount());
    ASSERT_EQ((std::size_t)1, decomposition.leaves().size());
    ASSERT_EQ((htd::vertex_t)1, decomposition.leaves()[0]);

    ASSERT_EQ((std::size_t)1, decomposition.isolatedVertexCount());
    ASSERT_EQ(root, decomposition.isolatedVertices()[0]);
    ASSERT_EQ(root, decomposition.isolatedVertexAtPosition(0));
    ASSERT_TRUE(decomposition.isIsolatedVertex(root));

    ASSERT_EQ(htd::Vertex::FIRST + 1, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST, decomposition.nextEdgeId());

    ASSERT_EQ((std::size_t)0, decomposition.height());
    ASSERT_EQ((std::size_t)0, decomposition.height(1));
    ASSERT_EQ((std::size_t)0, decomposition.depth(1));

    delete libraryInstance;
}

TEST(PathDecompositionTest, CheckSize3Path)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition(libraryInstance);

    ASSERT_EQ((std::size_t)0, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());

    ASSERT_EQ((std::size_t)0, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)0, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)0, decomposition.leafCount());

    htd::vertex_t root = decomposition.insertRoot();

    htd::vertex_t child = decomposition.addChild(root);

    ASSERT_NE(root, child);

    ASSERT_TRUE(decomposition.isVertex(root));
    ASSERT_TRUE(decomposition.isVertex(child));
    ASSERT_TRUE(decomposition.isRoot(root));
    ASSERT_EQ(root, decomposition.root());

    ASSERT_EQ((std::size_t)2, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount());
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount(root));
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount(child));

    ASSERT_EQ((std::size_t)2, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)1, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)1, decomposition.leafCount());

    ASSERT_TRUE(decomposition.isChild(root, child));
    ASSERT_FALSE(decomposition.isChild(child, root));

    htd::vertex_t newRoot = decomposition.addParent(root);

    ASSERT_TRUE(decomposition.isVertex(root));
    ASSERT_TRUE(decomposition.isVertex(child));
    ASSERT_TRUE(decomposition.isVertex(newRoot));
    ASSERT_TRUE(decomposition.isRoot(newRoot));
    ASSERT_EQ(newRoot, decomposition.root());

    ASSERT_EQ((std::size_t)3, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)2, decomposition.edgeCount());
    ASSERT_EQ((std::size_t)2, decomposition.edgeCount(root));
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount(child));
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount(newRoot));

    ASSERT_EQ((std::size_t)3, decomposition.vertices().size());
    ASSERT_EQ((std::size_t)2, decomposition.hyperedges().size());

    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.isolatedVertices().size());

    ASSERT_TRUE(decomposition.isConnected());

    ASSERT_EQ((std::size_t)1, decomposition.leafCount());

    ASSERT_TRUE(decomposition.isChild(newRoot, root));
    ASSERT_TRUE(decomposition.isChild(root, child));
    ASSERT_FALSE(decomposition.isChild(newRoot, child));
    ASSERT_TRUE(decomposition.isParent(child, root));
    ASSERT_TRUE(decomposition.isParent(root, newRoot));
    ASSERT_FALSE(decomposition.isParent(child, newRoot));

    ASSERT_EQ(child, decomposition.childAtPosition(root, (htd::index_t)0));
    ASSERT_EQ(root, decomposition.childAtPosition(newRoot, (htd::index_t)0));

    ASSERT_EQ(newRoot, decomposition.parent(root));
    ASSERT_EQ(root, decomposition.parent(child));

    ASSERT_EQ((std::size_t)1, decomposition.childCount(root));
    ASSERT_EQ((std::size_t)0, decomposition.childCount(child));
    ASSERT_EQ((std::size_t)1, decomposition.childCount(newRoot));

    ASSERT_EQ(root, decomposition.children(newRoot)[0]);
    ASSERT_EQ(child, decomposition.children(root)[0]);

    ASSERT_FALSE(decomposition.isLeaf(root));
    ASSERT_TRUE(decomposition.isLeaf(child));
    ASSERT_FALSE(decomposition.isLeaf(newRoot));

    ASSERT_EQ((std::size_t)2, decomposition.vertexCount(root));
    ASSERT_EQ((std::size_t)1, decomposition.vertexCount(child));
    ASSERT_EQ((std::size_t)3, decomposition.vertexCount(newRoot));

    ASSERT_EQ((std::size_t)2, decomposition.neighborCount(root));
    ASSERT_EQ((std::size_t)1, decomposition.neighborCount(child));
    ASSERT_EQ((std::size_t)1, decomposition.neighborCount(newRoot));

    ASSERT_EQ((std::size_t)0, decomposition.associatedEdgeIds(newRoot, root).size());
    ASSERT_EQ((std::size_t)1, decomposition.associatedEdgeIds(root, newRoot).size());
    ASSERT_EQ((htd::id_t)2, decomposition.associatedEdgeIds(root, newRoot)[0]);

    ASSERT_TRUE(decomposition.isEdge((htd::id_t)1));
    ASSERT_TRUE(decomposition.isEdge(root, newRoot));
    ASSERT_TRUE(decomposition.isEdge(std::vector<htd::vertex_t> { root, newRoot }));
    ASSERT_FALSE(decomposition.isEdge(std::vector<htd::vertex_t> { root, child, newRoot }));

    std::vector<htd::vertex_t> edgeElements1 { root, child };
    std::vector<htd::vertex_t> edgeElements2 { root, child, newRoot };

    ASSERT_TRUE(decomposition.isEdge(htd::ConstCollection<htd::vertex_t>(edgeElements1.begin(), edgeElements1.end())));
    ASSERT_FALSE(decomposition.isEdge(htd::ConstCollection<htd::vertex_t>(edgeElements2.begin(), edgeElements2.end())));

    ASSERT_EQ((std::size_t)1, decomposition.associatedEdgeIds(edgeElements1).size());
    ASSERT_EQ((std::size_t)0, decomposition.associatedEdgeIds(edgeElements2).size());
    ASSERT_EQ((htd::id_t)1, decomposition.associatedEdgeIds(edgeElements1)[0]);

    ASSERT_EQ((std::size_t)1, decomposition.associatedEdgeIds(htd::ConstCollection<htd::vertex_t>(edgeElements1.begin(), edgeElements1.end())).size());
    ASSERT_EQ((std::size_t)0, decomposition.associatedEdgeIds(htd::ConstCollection<htd::vertex_t>(edgeElements2.begin(), edgeElements2.end())).size());
    ASSERT_EQ((htd::id_t)1, decomposition.associatedEdgeIds(htd::ConstCollection<htd::vertex_t>(edgeElements1.begin(), edgeElements1.end()))[0]);

    ASSERT_FALSE(decomposition.isNeighbor(root, root));
    ASSERT_TRUE(decomposition.isNeighbor(root, child));
    ASSERT_TRUE(decomposition.isNeighbor(root, newRoot));
    ASSERT_TRUE(decomposition.isNeighbor(child, root));
    ASSERT_FALSE(decomposition.isNeighbor(child, child));
    ASSERT_FALSE(decomposition.isNeighbor(child, newRoot));;
    ASSERT_TRUE(decomposition.isNeighbor(newRoot, root));
    ASSERT_FALSE(decomposition.isNeighbor(newRoot, child));
    ASSERT_FALSE(decomposition.isNeighbor(newRoot, newRoot));

    ASSERT_TRUE(decomposition.isConnected());
    ASSERT_TRUE(decomposition.isConnected(root, root));
    ASSERT_TRUE(decomposition.isConnected(root, child));
    ASSERT_TRUE(decomposition.isConnected(root, newRoot));
    ASSERT_TRUE(decomposition.isConnected(child, root));
    ASSERT_TRUE(decomposition.isConnected(child, child));
    ASSERT_TRUE(decomposition.isConnected(child, newRoot));;
    ASSERT_TRUE(decomposition.isConnected(newRoot, root));
    ASSERT_TRUE(decomposition.isConnected(newRoot, child));
    ASSERT_TRUE(decomposition.isConnected(newRoot, newRoot));

    ASSERT_EQ(root, decomposition.vertexAtPosition((htd::index_t)0));
    ASSERT_EQ(child, decomposition.vertexAtPosition((htd::index_t)1));
    ASSERT_EQ(newRoot, decomposition.vertexAtPosition((htd::index_t)2));

    const htd::ConstCollection<htd::vertex_t> & rootNeighbors = decomposition.neighbors(root);
    const htd::ConstCollection<htd::vertex_t> & childNeighbors = decomposition.neighbors(child);
    const htd::ConstCollection<htd::vertex_t> & newRootNeighbors = decomposition.neighbors(newRoot);

    std::vector<htd::vertex_t> rootNeighbors2;
    std::vector<htd::vertex_t> childNeighbors2;
    std::vector<htd::vertex_t> newRootNeighbors2;

    ASSERT_EQ((std::size_t)2, rootNeighbors.size());
    ASSERT_EQ((std::size_t)1, childNeighbors.size());
    ASSERT_EQ((std::size_t)1, newRootNeighbors.size());

    ASSERT_EQ((std::size_t)0, rootNeighbors2.size());
    ASSERT_EQ((std::size_t)0, childNeighbors2.size());
    ASSERT_EQ((std::size_t)0, newRootNeighbors2.size());

    decomposition.copyNeighborsTo(rootNeighbors2, root);
    decomposition.copyNeighborsTo(childNeighbors2, child);
    decomposition.copyNeighborsTo(newRootNeighbors2, newRoot);

    ASSERT_EQ((std::size_t)2, rootNeighbors2.size());
    ASSERT_EQ((std::size_t)1, childNeighbors2.size());
    ASSERT_EQ((std::size_t)1, newRootNeighbors2.size());

    ASSERT_EQ(child, rootNeighbors[0]);
    ASSERT_EQ(newRoot, rootNeighbors[1]);
    ASSERT_EQ(root, childNeighbors[0]);
    ASSERT_EQ(root, newRootNeighbors[0]);

    ASSERT_EQ(child, rootNeighbors2[0]);
    ASSERT_EQ(newRoot, rootNeighbors2[1]);
    ASSERT_EQ(root, childNeighbors2[0]);
    ASSERT_EQ(root, newRootNeighbors2[0]);

    ASSERT_EQ(child, decomposition.neighborAtPosition(root, (htd::index_t)0));
    ASSERT_EQ(newRoot, decomposition.neighborAtPosition(root, (htd::index_t)1));
    ASSERT_EQ(root, decomposition.neighborAtPosition(child, (htd::index_t)0));
    ASSERT_EQ(root, decomposition.neighborAtPosition(newRoot, (htd::index_t)0));

    ASSERT_EQ((std::size_t)2, decomposition.hyperedges(root).size());
    ASSERT_EQ((std::size_t)1, decomposition.hyperedges(child).size());
    ASSERT_EQ((std::size_t)1, decomposition.hyperedges(newRoot).size());

    ASSERT_EQ(root, decomposition.hyperedge(1)[0]);
    ASSERT_EQ(child, decomposition.hyperedge(1)[1]);

    ASSERT_EQ(root, decomposition.hyperedge(2)[0]);
    ASSERT_EQ(newRoot, decomposition.hyperedge(2)[1]);

    ASSERT_EQ(root, decomposition.hyperedgeAtPosition(0)[0]);
    ASSERT_EQ(child, decomposition.hyperedgeAtPosition(0)[1]);

    ASSERT_EQ(root, decomposition.hyperedgeAtPosition(1)[0]);
    ASSERT_EQ(newRoot, decomposition.hyperedgeAtPosition(1)[1]);

    ASSERT_EQ(root, decomposition.hyperedgeAtPosition(0, newRoot)[0]);
    ASSERT_EQ(newRoot, decomposition.hyperedgeAtPosition(0, newRoot)[1]);

    const htd::FilteredHyperedgeCollection & hyperedges = decomposition.hyperedgesAtPositions(std::vector<htd::index_t> { 1, 0, 1 });

    auto position = hyperedges.begin();

    ASSERT_EQ(root, (*position)[0]);
    ASSERT_EQ(newRoot, (*position)[1]);

    ++position;

    ASSERT_EQ(root, (*position)[0]);
    ASSERT_EQ(child, (*position)[1]);

    ++position;

    ASSERT_EQ(root, (*position)[0]);
    ASSERT_EQ(newRoot, (*position)[1]);

    ASSERT_EQ(htd::Vertex::FIRST + 3, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST + 2, decomposition.nextEdgeId());

    ASSERT_EQ((std::size_t)2, decomposition.height());
    ASSERT_EQ((std::size_t)2, decomposition.height(newRoot));
    ASSERT_EQ((std::size_t)1, decomposition.height(root));
    ASSERT_EQ((std::size_t)0, decomposition.height(child));
    ASSERT_EQ((std::size_t)0, decomposition.depth(newRoot));
    ASSERT_EQ((std::size_t)1, decomposition.depth(root));
    ASSERT_EQ((std::size_t)2, decomposition.depth(child));

    delete libraryInstance;
}

TEST(PathDecompositionTest, CheckPathManipulations1)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition(libraryInstance);

    htd::vertex_t root = decomposition.insertRoot();

    htd::vertex_t child = decomposition.addChild(root);

    htd::vertex_t intermediateNode = decomposition.addParent(child);

    ASSERT_EQ(htd::Vertex::FIRST + 3, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST + 3, decomposition.nextEdgeId());

    ASSERT_EQ((std::size_t)2, decomposition.height());
    ASSERT_EQ((std::size_t)2, decomposition.height(root));
    ASSERT_EQ((std::size_t)1, decomposition.height(intermediateNode));
    ASSERT_EQ((std::size_t)0, decomposition.height(child));
    ASSERT_EQ((std::size_t)0, decomposition.depth(root));
    ASSERT_EQ((std::size_t)1, decomposition.depth(intermediateNode));
    ASSERT_EQ((std::size_t)2, decomposition.depth(child));

    decomposition.swapWithParent(child);

    ASSERT_EQ(htd::Vertex::FIRST + 3, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST + 4, decomposition.nextEdgeId());

    ASSERT_EQ((std::size_t)2, decomposition.height());
    ASSERT_EQ((std::size_t)2, decomposition.height(root));
    ASSERT_EQ((std::size_t)0, decomposition.height(intermediateNode));
    ASSERT_EQ((std::size_t)1, decomposition.height(child));
    ASSERT_EQ((std::size_t)0, decomposition.depth(root));
    ASSERT_EQ((std::size_t)2, decomposition.depth(intermediateNode));
    ASSERT_EQ((std::size_t)1, decomposition.depth(child));

    ASSERT_EQ(root, decomposition.root());

    htd::vertex_t intermediateNode2 = decomposition.addChild(child);

    decomposition.swapWithParent(child);

    ASSERT_EQ(child, decomposition.root());

    ASSERT_EQ(htd::Vertex::FIRST + 4, decomposition.nextVertex());

    ASSERT_EQ(htd::Id::FIRST + 7, decomposition.nextEdgeId());

    ASSERT_EQ((std::size_t)3, decomposition.height());
    ASSERT_EQ((std::size_t)2, decomposition.height(root));
    ASSERT_EQ((std::size_t)0, decomposition.height(intermediateNode));
    ASSERT_EQ((std::size_t)1, decomposition.height(intermediateNode2));
    ASSERT_EQ((std::size_t)3, decomposition.height(child));
    ASSERT_EQ((std::size_t)1, decomposition.depth(root));
    ASSERT_EQ((std::size_t)3, decomposition.depth(intermediateNode));
    ASSERT_EQ((std::size_t)2, decomposition.depth(intermediateNode2));
    ASSERT_EQ((std::size_t)0, decomposition.depth(child));

    delete libraryInstance;
}

TEST(PathDecompositionTest, CheckPathModifications2)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition(libraryInstance);

    htd::vertex_t vertex1 = decomposition.insertRoot();
    htd::vertex_t vertex2 = decomposition.addChild(vertex1);
    htd::vertex_t vertex3 = decomposition.addChild(vertex2);
    htd::vertex_t vertex4 = decomposition.addChild(vertex3);

    ASSERT_EQ((std::size_t)4, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)3, decomposition.edgeCount());

    decomposition.removeVertex(vertex2);

    ASSERT_FALSE(decomposition.isVertex(vertex2));

    ASSERT_EQ((std::size_t)3, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)2, decomposition.edgeCount());

    ASSERT_TRUE(decomposition.isNeighbor(vertex1, vertex3));
    ASSERT_TRUE(decomposition.isNeighbor(vertex3, vertex4));

    decomposition.removeSubpath(vertex3);

    ASSERT_EQ((std::size_t)1, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());

    decomposition.removeVertex(vertex1);

    ASSERT_EQ((std::size_t)0, decomposition.vertexCount());

    htd::vertex_t vertex5 = decomposition.insertRoot();
    htd::vertex_t vertex6 = decomposition.addChild(vertex5);
    htd::vertex_t vertex7 = decomposition.addChild(vertex6);

    ASSERT_EQ((std::size_t)3, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)2, decomposition.edgeCount());

    decomposition.removeChild(vertex5);

    ASSERT_EQ((std::size_t)2, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition.edgeCount());

    decomposition.removeChild(vertex5, vertex7);

    ASSERT_EQ((std::size_t)1, decomposition.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition.edgeCount());

    delete libraryInstance;
}

TEST(PathDecompositionTest, CheckCopyConstructors)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition decomposition1(libraryInstance);

    htd::vertex_t vertex1 = decomposition1.insertRoot();
    htd::vertex_t vertex2 = decomposition1.addChild(vertex1);
    htd::vertex_t vertex3 = decomposition1.addChild(vertex2);

    decomposition1.removeVertex(vertex2);

    ASSERT_EQ((std::size_t)2, decomposition1.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition1.edgeCount());

    htd::PathDecomposition decomposition2(decomposition1);

    decomposition2.addChild(vertex3);

    ASSERT_EQ((std::size_t)3, decomposition2.vertexCount());
    ASSERT_EQ((std::size_t)2, decomposition2.edgeCount());

    htd::PathDecomposition decomposition3(libraryInstance);

    ASSERT_EQ((std::size_t)0, decomposition3.vertexCount());
    ASSERT_EQ((std::size_t)0, decomposition3.edgeCount());

    decomposition3 = decomposition1;

    ASSERT_EQ((std::size_t)2, decomposition3.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition3.edgeCount());

    decomposition3 = decomposition2;

    ASSERT_EQ((std::size_t)3, decomposition3.vertexCount());
    ASSERT_EQ((std::size_t)2, decomposition3.edgeCount());

    const htd::IPath & pathReference1 = decomposition1;

    decomposition3 = pathReference1;

    ASSERT_EQ((std::size_t)2, decomposition3.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition3.edgeCount());

    htd::PathDecomposition decomposition4(pathReference1);

    ASSERT_EQ((std::size_t)2, decomposition4.vertexCount());
    ASSERT_EQ((std::size_t)1, decomposition4.edgeCount());

    delete libraryInstance;
}

TEST(PathDecompositionTest, TestVertexLabelModifications)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition pd(libraryInstance);

    pd.insertRoot();
    pd.addChild(1);
    pd.addChild(1);
    pd.addChild(2);

    pd.setVertexLabel("Label", 1, new htd::Label<int>(1));
    pd.setVertexLabel("Label", 2, new htd::Label<int>(2));
    pd.setVertexLabel("Label", 3, new htd::Label<int>(3));

    ASSERT_EQ((std::size_t)1, pd.labelCount());
    ASSERT_EQ((std::size_t)1, pd.labelNames().size());
    ASSERT_EQ("Label", pd.labelNames()[0]);
    ASSERT_EQ("Label", pd.labelNameAtPosition(0));

    ASSERT_FALSE(pd.isLabeledVertex("Label", 0));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 1));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 2));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 3));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(3, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    htd::ILabel * newLabel = new htd::Label<int>(33);

    pd.setVertexLabel("Label", 3, newLabel);

    ASSERT_FALSE(pd.isLabeledVertex("Label", 0));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 1));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 2));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 3));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    pd.setVertexLabel("Label", 3, newLabel);

    ASSERT_FALSE(pd.isLabeledVertex("Label", 0));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 1));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 2));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 3));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    pd.swapVertexLabels(1, 1);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    pd.swapVertexLabels(1, 3);

    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    pd.swapVertexLabels(3, 1);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    htd::ILabel * exportedLabel = pd.transferVertexLabel("Label", 1);

    ASSERT_FALSE(pd.isLabeledVertex("Label", 0));
    ASSERT_FALSE(pd.isLabeledVertex("Label", 1));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 2));
    ASSERT_TRUE(pd.isLabeledVertex("Label", 3));

    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));

    ASSERT_EQ(1, htd::accessLabel<int>(*exportedLabel));

    pd.setVertexLabel("Label2", 2, new htd::Label<int>(1));
    pd.setVertexLabel("Label2", 3, new htd::Label<int>(2));

    pd.swapVertexLabel("Label", 2, 3);

    ASSERT_EQ(33, htd::accessLabel<int>(pd.vertexLabel("Label", 2)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label", 3)));
    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label2", 2)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.vertexLabel("Label2", 3)));

    pd.removeVertexLabel("Label", 2);
    pd.removeVertexLabel("Label", htd::Vertex::UNKNOWN);
    pd.removeVertexLabel("Label3", 2);
    pd.removeVertexLabel("Label3", htd::Vertex::UNKNOWN);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.vertexLabel("Label2", 2)));

    delete exportedLabel;

    delete libraryInstance;
}

TEST(PathDecompositionTest, TestEdgeLabelModifications)
{
    htd::LibraryInstance * libraryInstance = htd::createManagementInstance(htd::Id::FIRST);

    htd::PathDecomposition pd(libraryInstance);

    pd.insertRoot();
    pd.addChild(1);
    pd.addChild(1);
    pd.addChild(2);

    pd.setEdgeLabel("Label", 1, new htd::Label<int>(1));
    pd.setEdgeLabel("Label", 2, new htd::Label<int>(2));
    pd.setEdgeLabel("Label", 3, new htd::Label<int>(3));

    ASSERT_EQ((std::size_t)1, pd.labelCount());
    ASSERT_EQ((std::size_t)1, pd.labelNames().size());
    ASSERT_EQ("Label", pd.labelNames()[0]);
    ASSERT_EQ("Label", pd.labelNameAtPosition(0));

    ASSERT_FALSE(pd.isLabeledEdge("Label", 0));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 1));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 2));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 3));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(3, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    htd::ILabel * newLabel = new htd::Label<int>(33);

    pd.setEdgeLabel("Label", 3, newLabel);

    ASSERT_FALSE(pd.isLabeledEdge("Label", 0));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 1));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 2));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 3));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    pd.setEdgeLabel("Label", 3, newLabel);

    ASSERT_TRUE(pd.isLabeledEdge("Label", 1));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 2));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 3));
    ASSERT_FALSE(pd.isLabeledEdge("Label", 0));

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    pd.swapEdgeLabels(1, 1);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    pd.swapEdgeLabels(1, 3);

    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    pd.swapEdgeLabels(3, 1);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label", 1)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    htd::ILabel * exportedLabel = pd.transferEdgeLabel("Label", 1);

    ASSERT_FALSE(pd.isLabeledEdge("Label", 1));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 2));
    ASSERT_TRUE(pd.isLabeledEdge("Label", 3));
    ASSERT_FALSE(pd.isLabeledEdge("Label", 0));

    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));

    ASSERT_EQ(1, htd::accessLabel<int>(*exportedLabel));

    pd.setEdgeLabel("Label2", 2, new htd::Label<int>(1));
    pd.setEdgeLabel("Label2", 3, new htd::Label<int>(2));

    pd.swapEdgeLabel("Label", 2, 3);

    ASSERT_EQ(33, htd::accessLabel<int>(pd.edgeLabel("Label", 2)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label", 3)));
    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label2", 2)));
    ASSERT_EQ(2, htd::accessLabel<int>(pd.edgeLabel("Label2", 3)));

    pd.removeEdgeLabel("Label", 2);
    pd.removeEdgeLabel("Label", htd::Vertex::UNKNOWN);
    pd.removeEdgeLabel("Label3", 2);
    pd.removeEdgeLabel("Label3", htd::Vertex::UNKNOWN);

    ASSERT_EQ(1, htd::accessLabel<int>(pd.edgeLabel("Label2", 2)));

    delete exportedLabel;

    delete libraryInstance;
}

int main(int argc, char **argv)
{
    /* GoogleTest may throw. This results in a non-zero exit code and is intended. */
    // coverity[fun_call_w_exception]
    ::testing::InitGoogleTest(&argc, argv);

    /* GoogleTest may throw. This results in a non-zero exit code and is intended. */
    // coverity[fun_call_w_exception]
    return RUN_ALL_TESTS();
}
