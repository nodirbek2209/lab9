#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findSeparationLevels(int N, int M, vector<pair<int, int>>& friendships) {
    vector<vector<int>> graph(N);
    for (const auto& friendship : friendships) {
        int u = friendship.first;
        int v = friendship.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> levels(N, -1);
    queue<int> q;
    q.push(0);
    levels[0] = 0;

    while (!q.empty()) {
        int curr_user = q.front();
        q.pop();
        for (int neighbor : graph[curr_user]) {
            if (levels[neighbor] == -1) {
                levels[neighbor] = levels[curr_user] + 1;
                q.push(neighbor);
            }
        }
    }

    return levels;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> friendships(M);
    for (int i = 0; i < M; ++i) {
        cin >> friendships[i].first >> friendships[i].second;
    }

    vector<int> separation_levels = findSeparationLevels(N, M, friendships);

    for (int level : separation_levels) {
        cout << level << " ";
    }
    cout << endl;

    return 0;
}
