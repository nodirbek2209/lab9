#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<vector<pair<int, int>>> adjList(n);

    int n1, n2, dis;
    for (int i = 0; i < e; i++) {
        cin >> n1 >> n2 >> dis;
        adjList[n1].push_back({n2, dis});
        adjList[n2].push_back({n1, dis});
    }
    
    int input;
    cin >> input;
    
    int result = 0;
    for (auto edge : adjList[input]) {
        result += edge.second; // Sum the distances of edges
    }
    cout << result;

    return 0;
}
