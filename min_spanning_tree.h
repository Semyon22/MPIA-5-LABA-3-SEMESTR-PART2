#pragma once

#include "graph.h"

#include <vector>

// Return minimal spanning tree for the (connected) graph as array of edges.
std::vector<std::pair<int, int>> min_spanning_tree(const Graph& graph);

void measure_time();
Graph random_graph(int size);
int random_number(int size);
double min_spanning_tree_time(const Graph& graph);
