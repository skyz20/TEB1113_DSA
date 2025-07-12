/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 2 (Easy) - Rotate Square Matrix by 90 Degrees Counterclockwise
Problem: https://www.geeksforgeeks.org/dsa/rotate-matrix-elements/
*/


#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int row = 0, col = 0;
    int prev, curr;

    while (row < m && col < n) {
        if (row + 1 == m || col + 1 == n)
            break;

        prev = mat[row + 1][col];

        for (int i = col; i < n; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for (int i = row; i < m; i++) {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        if (row < m) {
            for (int i = n - 1; i >= col; i--) {
                curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;

        if (col < n) {
            for (int i = m - 1; i >= row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: \n";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    rotateMatrix(mat);

    cout << "Rotated matrix:\n";
    for (auto& r : mat) {
        for (int val : r)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
