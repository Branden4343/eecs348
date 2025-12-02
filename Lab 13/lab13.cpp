#include <iostream>
#include <vector>
using namespace std;

// Original function
bool fail_lecture(const vector<int>& records) {
    int absent_count = 0;
    for (int i = 1; i < records.size(); ++i) {
        absent_count += (records[i] == 0);
    }
    return absent_count >= 3;
}

// Corrected function. i = 0 instead
bool fail_lecture_revised(const vector<int>& records) {
    int absent_count = 0;
    for (int i = 0; i < records.size(); ++i) {
        absent_count += (records[i] == 0);
    }
    return absent_count >= 3;
}

void run_test(const vector<int>& rec) {
    cout << "Test case: ";
    for (int x : rec) cout << x << " ";
    cout << "\nExpected: "
         << (fail_lecture_revised(rec) ? "True" : "False");

    cout << "\nActual:   "
         << (fail_lecture(rec) ? "True" : "False") << "\n\n";
}

int main() {

    cout << "Question 2.\n";
    run_test({1});  // Question 2
    cout << "Question 3.\n";
    run_test({1,1,1,1,1,1,1,1,1,1});  // Question 3
    cout << "Question 4.\n";
    run_test({0,1,1,1,1,1,1,1,1,0});  // Question 4
    cout << "Question 5.\n";
    run_test({0,0,0,1,1,1,1,1,1,1});  // Question 5

    return 0;
}
