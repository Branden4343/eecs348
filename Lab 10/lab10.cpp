#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
// ChatGPT provided lots of helpful code to use below.

// 2. Identify if a number is a valid double number
bool isValidDouble(string s) {
    if (s.empty()) return false;
    int i = 0;
    if (s[0] == '+' || s[0] == '-') i++;
    bool hasDigit = false, hasDot = false;
    int beforeDot = 0, afterDot = 0;

    for (; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            hasDigit = true;
            if (!hasDot) beforeDot++;
            else afterDot++;
        } else if (c == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else return false;
    }

    if (hasDot && (beforeDot == 0 || afterDot == 0)) return false;
    return hasDigit;
}


void padFraction(string &fraction_1, string &fraction_2) { // Used as a helper to pad fractionals
    while (fraction_1.size() < fraction_2.size()) fraction_1 += '0';
    while (fraction_2.size() < fraction_1.size()) fraction_2 += '0';
}

// 3. Perform addition between the parsed double numbers:
string addStringsSimple(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? a[i--] - '0' : 0;
        int d2 = (j >= 0) ? b[j--] - '0' : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}

// Subtract two positive number strings (a >= b)
string subtractStringsSimple(string a, string b) {
    string result = "";
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0) {
        int d1 = a[i] - '0' - borrow;
        int d2 = (j >= 0) ? b[j--] - '0' : 0;
        if (d1 < d2) {
            d1 += 10;
            borrow = 1;
        } else borrow = 0;
        result += (d1 - d2) + '0';
        i--;
    }
    reverse(result.begin(), result.end());
    size_t pos = result.find_first_not_of('0');
    return pos != string::npos ? result.substr(pos) : "0";
}

int compareNumbers(string intA, string fracA, string intB, string fracB) {
    if (intA.size() != intB.size()) return intA.size() > intB.size() ? 1 : -1;
    if (intA != intB) return intA > intB ? 1 : -1;
    if (fracA != fracB) return fracA > fracB ? 1 : -1;
    return 0;
}

// Add two numbers with decimals, positive numbers only
string addPositive(string a, string b) {
    size_t dotA = a.find('.');
    size_t dotB = b.find('.');
    string intA = dotA != string::npos ? a.substr(0, dotA) : a;
    string fracA = dotA != string::npos ? a.substr(dotA + 1) : "";
    string intB = dotB != string::npos ? b.substr(0, dotB) : b;
    string fracB = dotB != string::npos ? b.substr(dotB + 1) : "";

    padFraction(fracA, fracB);

    string fracSum = addStringsSimple(fracA, fracB);
    int carry = 0;
    if (fracSum.size() > fracA.size()) {
        carry = fracSum[0] - '0';
        fracSum = fracSum.substr(1);
    }

    string intSum = addStringsSimple(intA, intB);
    if (carry) intSum = addStringsSimple(intSum, to_string(carry));

    string result = intSum;
    if (!fracSum.empty()) result += "." + fracSum;
    return result;
}

// Subtract two positive numbers a-b, assuming a>=b
string subtractPositive(string a, string b) {
    size_t dotA = a.find('.');
    size_t dotB = b.find('.');
    string intA = dotA != string::npos ? a.substr(0, dotA) : a;
    string fractionA = dotA != string::npos ? a.substr(dotA + 1) : "";
    string intB = dotB != string::npos ? b.substr(0, dotB) : b;
    string fractionB = dotB != string::npos ? b.substr(dotB + 1) : "";

    padFraction(fractionA, fractionB);

    int borrow = 0;
    string fractionRes = "";
    for (int i = fractionA.size() - 1; i >= 0; i--) {
        int d1 = fractionA[i] - '0' - borrow;
        int d2 = fractionB[i] - '0';
        if (d1 < d2) { d1 += 10; borrow = 1; } else borrow = 0;
        fractionRes += (d1 - d2) + '0';
    }
    reverse(fractionRes.begin(), fractionRes.end());

    string intRes = "";
    int i = intA.size() - 1, j = intB.size() - 1;
    while (i >= 0) {
        int d1 = intA[i] - '0' - borrow;
        int d2 = (j >= 0) ? intB[j--] - '0' : 0;
        if (d1 < d2) { d1 += 10; borrow = 1; } else borrow = 0;
        intRes += (d1 - d2) + '0';
        i--;
    }
    reverse(intRes.begin(), intRes.end());
    size_t pos = intRes.find_first_not_of('0');
    intRes = pos != string::npos ? intRes.substr(pos) : "0";

    while (!fractionRes.empty() && fractionRes.back() == '0') fractionRes.pop_back();

    if (!fractionRes.empty()) return intRes + "." + fractionRes;
    return intRes;
}

// 1. Read the candidate numbers from the file
int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }
    string num1, num2;
    while (file >> num1 >> num2) {
        string original_1 = num1, original_2 = num2;

        if (!isValidDouble(num1)) { cout << num1 << " isn't a valid number.\n"; continue; }
        if (!isValidDouble(num2)) { cout << num2 << " isn't a valid number.\n"; continue; }

        bool negative_1 = (num1[0] == '-');
        bool negative_2 = (num2[0] == '-');
        if (num1[0] == '+' || num1[0] == '-') num1 = num1.substr(1);
        if (num2[0] == '+' || num2[0] == '-') num2 = num2.substr(1);

        string result;
        if (!negative_1 && !negative_2) {
            result = addPositive(num1, num2);
        } else if (negative_1 && negative_2) {
            result = "-" + addPositive(num1, num2);
        } else {
            int cmp = compareNumbers(num1.substr(0, num1.find('.')), 
                                     num1.find('.') != string::npos ? num1.substr(num1.find('.')+1) : "",
                                     num2.substr(0, num2.find('.')), 
                                     num2.find('.') != string::npos ? num2.substr(num2.find('.')+1) : "");
            if (cmp >= 0) result = (negative_1 ? "-" : "") + subtractPositive(num1, num2);
            else result = (negative_2 ? "-" : "") + subtractPositive(num2, num1);
        }
        cout << original_1 << " + " << original_2 << " = " << result << endl;
    }
    file.close();
    return 0;
}