#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int node) {
    visited.insert(node);

    for (auto neighbor : graph[node]) {
        if (visited.count(neighbor) == 0) {
            dfs(graph, visited, neighbor);
        }
    }
}

bool is_connected(unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;    // to keep track of visited nodes
    int start_node = graph.begin()->first;    // starting from an arbitrary node

    dfs(graph, visited, start_node);

    return visited.size() == graph.size();    // checking if all nodes have been visited
}

int main() {
    unordered_map<int, vector<int>> graph = {
        {1, {2, 3}},
        {2, {1, 3}},
        {3, {1, 2}},
        {4, {5}},
        {5, {4}}
    };

    bool is_graph_connected = is_connected(graph);

    if (is_graph_connected) {
        cout << "The given graph is connected." << endl;
    }
    else {
        cout << "The given graph is not connected." << endl;
    }

    return 0;
}
