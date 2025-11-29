#include <UnitTest++.h>
#include "Graph.h"
#include <string>
#include <vector>
#include <set>

TEST(DefaultConstructorAndEmpty) {
        Graph<int> g;
        CHECK(g.empty());
        CHECK_EQUAL(0, g.size());
        CHECK_EQUAL(0, g.vertices_count());
        CHECK_EQUAL(0, g.edges_count());
}

TEST(AddVertex) {
        Graph<std::string> g;
        g.add_vertex("A");
        CHECK(!g.empty());
        CHECK_EQUAL(1, g.size());
        CHECK(g.has_vertex("A"));
        CHECK(!g.has_vertex("B"));
        g.add_vertex("B");
        CHECK_EQUAL(2, g.size());
        CHECK(g.has_vertex("B"));
}

TEST(AddEdgeAndHasEdge) {
        Graph<int> g;
        g.add_vertex(10);
        g.add_vertex(20);
        g.add_vertex(30);

        g.add_edge(0, 1);
        CHECK(g.has_edge(0, 1));
        CHECK(g.has_edge(1, 0));
        CHECK(!g.has_edge(0, 2));

        g.add_edge(1, 2);
        CHECK(g.has_edge(1, 2));
        CHECK_EQUAL(2, g.edges_count());
}

TEST(Degree) {
        Graph<char> g;
        g.add_vertex('X');
        g.add_vertex('Y');
        g.add_vertex('Z');
        CHECK_EQUAL(0, g.degree(0));

        g.add_edge(0, 1);
        g.add_edge(0, 2);
        CHECK_EQUAL(2, g.degree(0));
        CHECK_EQUAL(1, g.degree(1));
}

TEST(RemoveEdge) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_edge(0, 1);
        CHECK(g.has_edge(0, 1));
        CHECK_EQUAL(1, g.edges_count());

        g.remove_edge(0, 1);
        CHECK(!g.has_edge(0, 1));
        CHECK_EQUAL(0, g.edges_count());
}

TEST(OutOfBoundsVertexIndexThrows) {
        Graph<int> g;
        g.add_vertex(42);
        CHECK_THROW(g.has_edge(0, 10), std::out_of_range);
        CHECK_THROW(g.degree(5), std::out_of_range);
        CHECK_THROW(g.add_edge(0, 99), std::out_of_range);
}

TEST(ComparisonOperators) {
        Graph<std::string> g1, g2;
        g1.add_vertex("A");
        g2.add_vertex("A");
        CHECK(g1 == g2);
        CHECK(!(g1 != g2));

        g2.add_vertex("B");
        CHECK(g1 != g2);
        CHECK(g1 < g2);
}

TEST(VertexIterators) {
        Graph<int> g;
        g.add_vertex(100);
        g.add_vertex(200);
        g.add_vertex(300);

        std::vector<int> collected;
        for (auto it = g.vertex_begin(); it != g.vertex_end(); ++it) {
            collected.push_back(*it);
        }
        CHECK_ARRAY_EQUAL((std::vector<int>{100, 200, 300}), collected, 3);

        const Graph<int>& cg = g;
        std::vector<int> ccollected;
        for (auto it = cg.vertex_cbegin(); it != cg.vertex_cend(); ++it) {
            ccollected.push_back(*it);
        }
        CHECK_ARRAY_EQUAL((std::vector<int>{100, 200, 300}), ccollected, 3);
}

TEST(EdgeIterators) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_vertex(3);
        g.add_edge(0, 1);
        g.add_edge(1, 2);

        std::vector<std::pair<size_t, size_t>> edges;
        for (auto it = g.edge_begin(); it != g.edge_end(); ++it) {
            edges.push_back(*it);
        }

        CHECK_EQUAL(2, edges.size());
        CHECK((edges[0] == std::make_pair(0ULL, 1ULL) || edges[0] == std::make_pair(1ULL, 0ULL))); // порядок может отличаться
        CHECK((edges[1] == std::make_pair(1ULL, 2ULL) || edges[1] == std::make_pair(2ULL, 1ULL)));

        CHECK_EQUAL(0, edges[0].first);
        CHECK_EQUAL(1, edges[0].second);
        CHECK_EQUAL(1, edges[1].first);
        CHECK_EQUAL(2, edges[1].second);
}


TEST(NeighborIterators) {
        Graph<std::string> g;
        g.add_vertex("A");
        g.add_vertex("B");
        g.add_vertex("C");
        g.add_edge(0, 1);
        g.add_edge(0, 2);

        std::vector<std::string> neighbors;
        for (auto it = g.neighbors_begin(0); it != g.neighbors_end(0); ++it) {
            neighbors.push_back(*it);
        }


        CHECK_EQUAL(2, neighbors.size());
        CHECK_EQUAL("B", neighbors[0]);
        CHECK_EQUAL("C", neighbors[1]);
}


TEST(EraseVertexByIterator) {
        Graph<int> g;
        g.add_vertex(10);
        g.add_vertex(20);
        g.add_vertex(30);
        g.add_edge(0, 1);
        g.add_edge(1, 2);

        auto it = g.vertex_begin();
        ++it;
        g.erase_vertex(it);

        CHECK_EQUAL(2, g.size());
        CHECK_EQUAL(0, g.edges_count());
        CHECK(g.has_vertex(10));
        CHECK(g.has_vertex(30));
        CHECK(!g.has_vertex(20));
}

TEST(EraseEdgeByIterator) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_vertex(3);
        g.add_edge(0, 1);
        g.add_edge(1, 2);

        CHECK_EQUAL(2, g.edges_count());

        auto eit = g.edge_begin();
        ++eit; // второе ребро: (1,2)
        g.erase_edge(eit);

        CHECK_EQUAL(1, g.edges_count());
        CHECK(g.has_edge(0, 1));
        CHECK(!g.has_edge(1, 2));
}

TEST(StreamOutput) {
        Graph<std::string> g;
        g.add_vertex("X");
        g.add_vertex("Y");
        g.add_edge(0, 1);

        std::ostringstream oss;
        oss << g;
        std::string result = oss.str();

        CHECK(result.find("Vertices: X Y") != std::string::npos);
        CHECK(result.find("Edges: (0,1)") != std::string::npos);
}

TEST(ClearGraph) {
        Graph<int> g;
        g.add_vertex(1);
        g.add_vertex(2);
        g.add_edge(0, 1);
        CHECK(!g.empty());
        CHECK_EQUAL(1, g.edges_count());

        g.clear();
        CHECK(g.empty());
        CHECK_EQUAL(0, g.size());
        CHECK_EQUAL(0, g.edges_count());
}

TEST(CopyConstructorAndAssignment) {
        Graph<int> g1;
        g1.add_vertex(100);
        g1.add_vertex(200);
        g1.add_edge(0, 1);

        Graph<int> g2(g1);
        CHECK(g1 == g2);

        Graph<int> g3;
        g3 = g1;
        CHECK(g1 == g3);
        CHECK_EQUAL(2, g3.size());
        CHECK_EQUAL(1, g3.edges_count());
}

int main() {
    return UnitTest::RunAllTests();
}