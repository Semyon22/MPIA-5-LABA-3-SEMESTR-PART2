#include "min_spanning_tree.h"

using namespace std;

vector<pair<int, int>> min_spanning_tree(const Graph& graph) {
    vector<pair<int, int>> result;

    map<int, double> minWeight;
    vector<int> vertices = graph.get_vertices();

    if (vertices.size() <= 1) {
        return {};
    }

    for (int i = 0; i < vertices.size(); ++i) {
        minWeight.emplace(vertices[i], DBL_MAX);
    }

    map<int, int> parent;
    for (int i = 0; i < vertices.size(); ++i) {
        parent.emplace(vertices[i], -1);
    }

    minWeight[vertices[0]] = 0;

    while (!vertices.empty()) {
        double min_weight = minWeight[vertices[0]];
        int min_weight_vertex = vertices[0];

        for (int i = 0; i < vertices.size(); ++i) {
            if (minWeight[vertices[i]] < min_weight) {
                min_weight = minWeight[vertices[i]];
                min_weight_vertex = vertices[i];
            }
        }

        vertices.erase(find(vertices.begin(), vertices.end(), min_weight_vertex));

        vector<int> adjacent_vertices = graph.get_adjacent_vertices(min_weight_vertex);
        for (int i = 0; i < adjacent_vertices.size(); ++i) {
            if (find(vertices.begin(), vertices.end(), adjacent_vertices[i]) != vertices.end() && minWeight[adjacent_vertices[i]] > graph.edge_weight(min_weight_vertex, adjacent_vertices[i])) {
                minWeight[adjacent_vertices[i]] = graph.edge_weight(min_weight_vertex, adjacent_vertices[i]);
                parent[adjacent_vertices[i]] = min_weight_vertex;
            }
        }
    }

    vector<int> vertices_t = graph.get_vertices();
    for (int i = 0; i < vertices_t.size(); ++i) {
        if (parent[vertices_t[i]] != -1) {
            result.push_back(make_pair(parent[vertices_t[i]], vertices_t[i]));
        }
    }

    return result;
}

