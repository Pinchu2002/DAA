#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void bfs(unordered_map<int, vector<int>>& graph, int start) {
    unordered_set<int> visited;    // to keep track of visited nodes
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        for (auto neighbor : graph[current_node]) {
            if (visited.count(neighbor) == 0) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {2}},
        {2, {0, 3}},
        {3, {3}}
    };

    int start_node = 2;
    bfs(graph, start_node);

    return 0;
}
