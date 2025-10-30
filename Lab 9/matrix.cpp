#include "matrix.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readMatrices(const string &filename, vector<vector<int>> &A, vector<vector<int>> &B, int &N) { // Task 1: Reading values from a file into the matrix
    ifstream fin(filename);
    if (!fin) {
        cout << "Error: Cannot open file.\n";
        exit(1);
    }

    fin >> N;
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> B[i][j];

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "\nMatrix B:\n"; printMatrix(B);
    cout << endl;
}

void printMatrix(const vector<vector<int>> &M) { // Function for printing matrix
    for (auto &row : M) {
        for (auto val : row)
            cout << setw(4) << val;
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) { // Task 2: Add two matrices
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    cout << "A + B:\n"; printMatrix(C); cout << endl;
    return C;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) { // Task 3: Multiply two matrices
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    cout << "A x B:\n"; printMatrix(C); cout << endl;
    return C;
}


void sumDiagonals(const vector<vector<int>> &M) { // Task 4: Sum of main and secondary diagonals
    int N = M.size(), mainSum = 0, secSum = 0;
    for (int i = 0; i < N; i++) {
        mainSum += M[i][i];
        secSum += M[i][N - 1 - i];
    }
    cout << "Main diagonal sum => " << mainSum << endl;
    cout << "Secondary diagonal sum => " << secSum << endl << endl;
}


void swapRows(vector<vector<int>> &M, int r1, int r2) { // Task 5: Swaps two rows
    if (r1 >= 0 && r2 >= 0 && r1 < M.size() && r2 < M.size()) {
        swap(M[r1], M[r2]);
        cout << "Row swap of: " << r1 << " and " << r2 << ":\n";
        printMatrix(M); cout << endl;
    } else cout << "Invalid row indices!\n";
}

void swapCols(vector<vector<int>> &M, int c1, int c2) { // Task 6: Swaps two columns
    int N = M.size();
    if (c1 >= 0 && c2 >= 0 && c1 < N && c2 < N) {
        for (int i = 0; i < N; i++) swap(M[i][c1], M[i][c2]);
        cout << "Column swap of: " << c1 << " and " << c2 << ":\n";
        printMatrix(M); cout << endl;
    } else cout << "Invalid column indices!\n";
}

void updateValue(vector<vector<int>> &M, int r, int c, int value) { // Task 7: Update matrix with a new value
    if (r >= 0 && c >= 0 && r < M.size() && c < M.size()) {
        M[r][c] = value;
        cout << "After updating M[" << r << "][" << c << "] = " << value << ":\n";
        printMatrix(M); cout << endl;
    } else cout << "Invalid indices!\n";
}
