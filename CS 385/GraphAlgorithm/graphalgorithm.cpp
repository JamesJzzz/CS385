/*******************************************************************************
 * Name        : graphalgorithm.cpp
 * Author      : Brian S. Borowski
 * Version     : 1.0
 * Date        : September 27, 2014
 * Description : Class that implements standard graph traversal algorithms.
 ******************************************************************************/
#include "graphalgorithm.h"
#include "graph.h"
#include "weightedgraph.h"
#include "vertex.h"
#include "minheap.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
#include <stdexcept>

using namespace std;

/*
static void depth_first_search_visit(
        vertex_id vertex,
        const Graph * const graph,
        bool *visited,
        vector<vertex_id> &order);

static void breadth_first_search_visit(
        vertex_id vertex,
        const Graph * const graph,
        bool *visited,
        vector<vertex_id> &order);
*/
vector<vertex_id> breadth_first_search(const Graph * const graph) {
	vector<vertex_id> v;
	return v;
    // TODO
}
/*
static void breadth_first_search_visit(
        vertex_id vertex, const Graph * const graph, bool *visited,
        vector<vertex_id> &order) {
    // TODO
}
*/
vector<vertex_id> depth_first_search(const Graph * const graph) {
	vector<vertex_id> v;
	return v;
    // TODO
}
/*
static void depth_first_search_visit(
        vertex_id vertex, const Graph * const graph, bool *visited,
        vector<vertex_id> &order) {
    // TODO
}
*/
vector<vertex_id> top_sort(const Graph * const graph) {
	vector<vertex_id> v;
	return v;
    // TODO
}

pair<uint_t, string> shortest_path(
        vertex_id src, vertex_id dst, const WeightedGraph * const graph) {
    pair<uint_t, string> result;
    return result;
}
