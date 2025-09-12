#include <iostream>
#include <map>

using namespace std;

int main() {
    int r, c, value;
    
    
    map<pair<int, int>, int> sm;
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter value for element at (" << i << ", " << j << "): ";
            cin >> value;

            if (value != 0) {
                sm[{i, j}] = value;
            }
        }
    }

    cout << "\nSparse Matrix view (Row, Column, Value):\n";
    cout << "| Row | Column | Value |\n";
    cout << "|-----|--------|-------|\n";
    for (const auto& element : sm) {
        cout << "|  " << element.first.first << "   |   " << element.first.second 
             << "    |   " << element.second << "   |\n";
    }

    return 0;
}
