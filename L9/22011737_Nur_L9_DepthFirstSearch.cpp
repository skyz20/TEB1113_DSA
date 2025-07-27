/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 9 (Graph - Depth First Search)
*/

#include <iostream>
#include <vector>

using namespace std;

// Convert node index to character A-E
char getNodeName(int index) {
    return 'A' + index;
}

// Perform DFS from a starting node
void DFS(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    cout << getNodeName(node) << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
    }
}

int main() {
    const int NUM_NODES = 5;

    // Manually build adjacency list to match DFS output: A B E D C
    vector<vector<int>> adjList(NUM_NODES);

    adjList[0] = {1, 3, 2};       // A → B, D, C
    adjList[1] = {4, 3, 0};       // B → E, D, A
    adjList[2] = {3, 0};          // C → D, A
    adjList[3] = {2, 0, 1, 4};    // D → C, A, B, E
    adjList[4] = {3, 1};          // E → D, B

    vector<bool> visited(NUM_NODES, false);

    cout << "DFS traversal from node A:\n";
    DFS(0, adjList, visited); // Start from node A (index 0)

    return 0;
}
