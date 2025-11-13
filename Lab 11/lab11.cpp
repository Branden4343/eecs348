#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
private:
    int size;
    int data[100][100]; // simple fixed-size storage

public:
    Matrix() {
        size = 0;
    }

    bool readFromFile(string filename, Matrix &second) { // Problem 1
        ifstream in(filename);
        if (!in) {
            cout << "Error opening file.\n";
            return false;
        }
        in >> size;
        if (size <= 0 || size > 100) {
            cout << "Invalid matrix size.\n";
            return false;
        }
        second.size = size;
        // Reads the first matrix
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                in >> data[i][j];

        // Reads the second matrix
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                in >> second.data[i][j];
        return true;
    }

    // Format the matrix
    void display() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << setw(4) << data[i][j];
            cout << endl;
        }
    }
    Matrix operator+(const Matrix &other) const { // 2. Add the two matrices and display the result by using operator overloading
        Matrix result;
        result.size = size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &other) const { // 3. Multiply two matrices and display the result, utilizing the operator overloading
        Matrix result;
        result.size = size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
        return result;
    }

    void sumDiagonals() const { // 4. Get the sum of matrix diagonal elements
        int mainSum = 0, secondarySum = 0;
        for (int i = 0; i < size; i++) {
            mainSum += data[i][i];
            secondarySum += data[i][size - 1 - i];
        }
        cout << "Main diagonal sum is " << mainSum << endl;
        cout << "Secondary diagonal sum is " << secondarySum << endl;
    }

    Matrix swapRows(int r1 = 0, int r2 = 1) const { // 5. Swap matrix rows and display the result
        Matrix temp = *this;
        if (r1 < 0 || r2 < 0 || r1 >= size || r2 >= size)
            return temp;
        for (int j = 0; j < size; j++)
            swap(temp.data[r1][j], temp.data[r2][j]);
        return temp;
    }

    Matrix swapCols(int c1 = 0, int c2 = 1) const { // 6. Swap matrix columns and display the result:
        Matrix temp = *this;
        if (c1 < 0 || c2 < 0 || c1 >= size || c2 >= size)
            return temp;
        for (int i = 0; i < size; i++)
            swap(temp.data[i][c1], temp.data[i][c2]);
        return temp;
    }

    Matrix updateElement(int row = 0, int col = 0, int value = 100) const { // 7. Update matrix rows and display the result
        Matrix temp = *this;
        if (row >= 0 && row < size && col >= 0 && col < size)
            temp.data[row][col] = value;
        return temp;
    }
};

// Runs all 7 problems
int main() {
    Matrix A, B;

    string filename;
    cout << "Enter the input file: ";
    cin >> filename;

    if (!A.readFromFile(filename, B)) {
        return 1;
    }

    cout << "Problem 1: \nMatrix A:\n";
    A.display(); // Problem 1
    cout << "\nMatrix B:\n";
    B.display();
    cout << "\nA + B (Problem 2):\n";
    (A + B).display(); // Problem 2
    cout << "\nA * B (Problem 3):\n";
    (A * B).display(); // Problem 3
    cout << "\nProblem 4:\n";
    A.sumDiagonals(); // Problem 4
    cout << "\nA after swapping rows 0 and 1 (Problem 5):\n";
    A.swapRows().display(); // Problem 5
    cout << "\nB after swapping columns 0 and 1 (Problem 6):\n";
    B.swapCols().display(); // Problem 6
    cout << "\nA after updating [0][0] to 100 (Problem 7):\n";
    A.updateElement().display(); // Problem 7

    return 0;
}
