/*
ID : 22011737
Name : Nur Aina Nabila
Group : G1
Lab: Lab 2 (Hard) - Find a specific pair in Matrix
Problem: https://www.geeksforgeeks.org/dsa/find-a-specific-pair-in-matrix/
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxValue(const vector<vector<int>>& mat, int n, int &aMax, int &bMax, int &dMax, int &eMax) {
    int maxValue = INT_MIN;
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - 1; b++) {
            for (int d = a + 1; d < n; d++) {
                for (int e = b + 1; e < n; e++) {
                    int diff = mat[d][e] - mat[a][b];
                    if (diff > maxValue) {
                        maxValue = diff;
                        aMax = a;
                        bMax = b;
                        dMax = d;
                        eMax = e;
                    }
                }
            }
        }
    }
    return maxValue;
}

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> mat[i][j];

    int a, b, d, e;
    int maxVal = findMaxValue(mat, n, a, b, d, e);

    cout << "Output: " << maxVal << endl;
    cout << "The maximum value is " << maxVal << " as mat[" << d << "][" << e << "] - mat[" << a << "][" << b << "] = " << maxVal << " has maximum difference." << endl;

    return 0;
}
