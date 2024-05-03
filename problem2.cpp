#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buildAdjList(int n, vector<pair<int, int>>& pairs) {
    vector<vector<int>> adjList(n);
    for (auto& pair : pairs) {
        int node1 = pair.first;
        int node2 = pair.second;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1); // Since it's a bidirectional graph
    }
    return adjList;
}

bool isConnected(vector<vector<int>>& adjList, int node1, int node2) {
    for (int neighbor : adjList[node1]) {
        if (neighbor == node2) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pairs(m);
    for (int i = 0; i < m; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    vector<vector<int>> adjList = buildAdjList(n, pairs);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        if (isConnected(adjList, node1, node2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
