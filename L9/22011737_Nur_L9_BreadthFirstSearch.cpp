/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 9 (Graph - Breadth First Search)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Convert node index to character A-E
char getNodeName(int index) {
    return 'A' + index;
}

// Perform BFS from a starting node
void BFS(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << getNodeName(curr) << " ";

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    const int NUM_NODES = 5;

    // Adjacency matrix
    int matrix[NUM_NODES][NUM_NODES] = {
        {0, 1, 1, 1, 0},  // A
        {1, 0, 0, 1, 1},  // B
        {1, 0, 0, 1, 0},  // C
        {1, 1, 1, 0, 1},  // D
        {0, 1, 0, 1, 0}   // E
    };

    // Build adjacency list from matrix
    vector<vector<int>> adjList(NUM_NODES);

    for (int i = 0; i < NUM_NODES; ++i) {
        for (int j = 0; j < NUM_NODES; ++j) {
            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    vector<bool> visited(NUM_NODES, false);

    cout << "BFS traversal from node B:\n";
    BFS(1, adjList, visited); // Start from 'B' (index 1)

    return 0;
}
