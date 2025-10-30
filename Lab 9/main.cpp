#include "matrix.h"
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> A, B, C;
    int N;
    string filename;

    cout << "Enter the file name: ";
    cin >> filename;

    readMatrices(filename, A, B, N);
    C = addMatrices(A, B);
    C = multiplyMatrices(A, B);
    sumDiagonals(A);
    swapRows(A, 0, 2);
    swapCols(B, 1, 3);
    updateValue(A, 1, 1, 99);

    return 0;
}
