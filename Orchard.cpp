#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to count valid triples of indices where no two adjacent trees are of the same type
int countValidTriples(const string& row) {
    int n = row.size();
    int count = 0;

    // Check all combinations of three different indices (i, j, k)
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            if (row[j] == row[i]) continue;
            for (int k = j + 1; k < n; ++k) {
                if (row[k] != row[j]) {
                    ++count;
                }
            }
        }
    }

    return count;
}

// Function to check if the input is valid
bool isValidInput(const string& row) {
    for (char ch : row) {
        if (ch != 'M' && ch != 'L') return false;
    }
    return true;
}

int main() {
    string ashokRow, anandRow;
    
    getline(cin, ashokRow);
    getline(cin, anandRow);

    // Validate inputs
    if (!isValidInput(ashokRow) || !isValidInput(anandRow) || ashokRow.empty() || anandRow.empty()) {
        cout << "Invalid input" << endl;
        return 0;
    }

    // Count valid triples
    int ashokCount = countValidTriples(ashokRow);
    int anandCount = countValidTriples(anandRow);

    // Determine the result
    if (ashokCount > anandCount) {
        cout << "Ashok" << endl;
    } else if (anandCount > ashokCount) {
        cout << "Anand" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
