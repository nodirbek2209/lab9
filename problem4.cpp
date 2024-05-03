#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

int countGroups(int N, vector<pair<int, int>>& bridges) {
    vector<vector<int>> graph(N);
    for (const auto& bridge : bridges) {
        int u = bridge.first;
        int v = bridge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N, false);
    int groups = 0;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            groups++;
        }
    }
    return groups;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> bridges(M);
    for (int i = 0; i < M; ++i) {
        cin >> bridges[i].first >> bridges[i].second;
    }

    int distinct_groups = countGroups(N, bridges);
    cout << distinct_groups << endl;

    return 0;
}
