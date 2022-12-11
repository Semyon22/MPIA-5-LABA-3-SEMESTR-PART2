#include "min_spanning_tree.h"
#include <iostream>
#include <random>
#include <numeric>
#include <chrono>
#include <ctime>

const int N = 1e5;

Graph random_graph(int size) {
    Graph graph;
    int vertices = size - 1;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution_distance(10, 100);

    for (int i = 0; i < vertices; ++i) {
        graph.add_edge(i, i + 1, distribution_distance(generator) / 10.0);
    }

    int additional_edges = random_number(size); // количество дополнительных ребер (генерируется)

    for (int i = 0; i < additional_edges; ++i) {
        int vertex_1 = random_number(size);
        int vertex_2 = random_number(size);
        if (!(graph.has_edge(vertex_1, vertex_2) || vertex_1 == vertex_2)) {
            graph.add_edge(vertex_1, vertex_2, distribution_distance(generator) / 10.0);
        }
    }

    return graph;
}

int random_number(int size) {
    srand(time(NULL));

    return rand() % size;
}

void measure_time() {
    Graph graph = random_graph(N);

    std::cout << "min_spanning_tree: " << "N = " << N << ", " << "time = " << min_spanning_tree_time(graph) << std::endl;
}

double min_spanning_tree_time(const Graph& graph) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<std::pair<int, int>> result = min_spanning_tree(graph);
    auto t2 = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration<double>(t2 - t1).count();

    return time;
}
