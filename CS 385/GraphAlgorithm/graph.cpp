/*******************************************************************************
 * Name        : graph.h
 * Author      : Brian S. Borowski
 * Version     : 1.0
 * Date        : September 23, 2014
 * Description : Simple graph class.
 ******************************************************************************/
#include "graph.h"
#include <list>
#include <vector>
#include <set>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

Graph::Graph() : num_vertices_(0), num_edges_(0) {
	adjacency_list_.push_back(list<vertex_weight_pair>());
}

Graph::~Graph() { }

vector<vertex_id> Graph::get_vertices() const {
    set<vertex_id> vertex_set;
    for (size_t i = 1, len = adjacency_list_.size(); i < len; ++i) {
        vertex_set.insert(static_cast<vertex_id>(i));
        if (adjacency_list_[i].size() > 0) {
            const list<vertex_weight_pair> * const adjacent_vertices =
                            &adjacency_list_[i];
            for (list<vertex_weight_pair>::const_iterator it =
                    adjacent_vertices->begin(); it != adjacent_vertices->end();
                    ++it) {
                vertex_set.insert(it->first);
            }
        }
    }
    vector<vertex_id> vertices;
    vertices.reserve(vertex_set.size());
    copy(vertex_set.begin(), vertex_set.end(), back_inserter(vertices));
    return vertices;
}

vector<vertex_id> Graph::get_adjacent(vertex_id vertex) const {
    vector<vertex_id> adjacent;
    if (vertex < adjacency_list_.size()) {
        const list<vertex_weight_pair> * const adjacent_vertices =
                &adjacency_list_[vertex];
        for (list<vertex_weight_pair>::const_iterator it =
                adjacent_vertices->begin(); it != adjacent_vertices->end();
                ++it) {
            adjacent.push_back(it->first);
        }
    }
    return adjacent;
}

vertex_id Graph::get_highest_vertex_id() const {
    vector<vertex_id> v = get_vertices();
    return v[v.size() - 1];
}

ostream& operator<<(std::ostream &os, const Graph &graph) {
    os << graph.to_string();
    os.flush();
    return os;
}

int Graph::num_digits(int num) {
    if (num == 0) {
        return 1;
    }
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}
