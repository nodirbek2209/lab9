#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int N = 6; 
    int adjacencyMatrix[N][N] = {0}; 

    
    int edges[][3] = {{0, 1, 12},
                      {0, 5, 25},
                      {1, 2, 13},
                      {1, 3, 15},
                      {2, 4, 5},
                      {2, 5, 2},
                      {3, 5, 13},
                      {4, 3, 5}};

    
    for (const auto& edge : edges) {
        int node1 = edge[0];
        int node2 = edge[1];
        int distance = edge[2];
        adjacencyMatrix[node1][node2] = distance;
        adjacencyMatrix[node2][node1] = distance; 
    }

    int inputNode;
    cin >> inputNode;

    
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (adjacencyMatrix[inputNode][i] != 0) {
            sum += adjacencyMatrix[inputNode][i];
        }
    }

    cout << sum << endl;

    return 0;
}
