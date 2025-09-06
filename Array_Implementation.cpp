#include <iostream>
#include <map>

using namespace std;

int main() {
    int rows, cols, value;
    
    // Dictionary to store non-zero elements in the format {(row, col): value}
    map<pair<int, int>, int> sparseMatrix;

    // Input the matrix dimensions
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Input the matrix values and populate the dictionary for non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for element at (" << i << ", " << j << "): ";
            cin >> value;

            // Store only non-zero elements in the map
            if (value != 0) {
                sparseMatrix[{i, j}] = value;
            }
        }
    }

    // Output the non-zero elements in table format
    cout << "\nSparse Matrix Representation (Row, Column, Value):\n";
    cout << "| Row | Column | Value |\n";
    cout << "|-----|--------|-------|\n";
    for (const auto& element : sparseMatrix) {
        cout << "|  " << element.first.first << "   |   " << element.first.second 
             << "    |   " << element.second << "   |\n";
    }

    return 0;
}
