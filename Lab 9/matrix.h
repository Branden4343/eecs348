#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
using namespace std;

void readMatrices(const string &filename, vector<vector<int>> &A, vector<vector<int>> &B, int &N);
void printMatrix(const vector<vector<int>> &M);
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B);
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B);
void sumDiagonals(const vector<vector<int>> &M);
void swapRows(vector<vector<int>> &M, int r1, int r2);
void swapCols(vector<vector<int>> &M, int c1, int c2);
void updateValue(vector<vector<int>> &M, int r, int c, int value);

#endif
