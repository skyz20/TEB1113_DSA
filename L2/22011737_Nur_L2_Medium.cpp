/*
ID : 22011737
Name : Nur Aina Nabila
Group : G1
Lab: Lab 2 (Medium) - Rotate Matrix Clockwise by 1
Problem: https://www.geeksforgeeks.org/dsa/inplace-rotate-square-matrix-by-90-degrees/
*/

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - j - 1][i] = mat[i][j];
        }
    }

    mat = res;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    rotateMatrix(mat);

    cout << "Rotated matrix (90 degrees counterclockwise):\n";
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}
