#include <iostream>
using namespace std;

struct Element {
    int rowIndex, colIndex, data;
    Element* link;
    Element(int r, int c, int d) : rowIndex(r), colIndex(c), data(d), link(nullptr) {}
};

class SparseMatrixLL {
private:
    Element* start;

public:
    SparseMatrixLL() : start(nullptr) {}

    void addElement(int r, int c, int d) {
        Element* newElem = new Element(r, c, d);
        if (!start) {
            start = newElem;
        } else {
            Element* ptr = start;
            while (ptr->link) ptr = ptr->link;
            ptr->link = newElem;
        }
    }

    void showElements() {
        if (start == nullptr) {
            cout << "Matrix contains no non-zero values." << endl;
            return;
        }

        Element* ptr = start;
        while (ptr != nullptr) {
            cout << "Row: " << ptr->rowIndex
                 << ", Column: " << ptr->colIndex
                 << ", Data: " << ptr->data
                 << ", Next: " << ptr->link << endl;
            ptr = ptr->link;
        }
    }

    ~SparseMatrixLL() {
        Element* ptr;
        while (start != nullptr) {
            ptr = start;
            start = start->link;
            delete ptr;
        }
    }
};

int main() {
    int totalRows, totalCols, entry;

    SparseMatrixLL matrix;

    cout << "Enter number of rows: ";
    cin >> totalRows;
    cout << "Enter number of columns: ";
    cin >> totalCols;

    cout << "Enter matrix values (0 for empty):\n";
    for (int r = 0; r < totalRows; ++r) {
        for (int c = 0; c < totalCols; ++c) {
            cout << "Value at (" << r << "," << c << "): ";
            cin >> entry;
            if (entry != 0) {
                matrix.addElement(r, c, entry);
            }
        }
    }

    cout << "\nSparse Matrix Linked List Representation:\n";
    matrix.showElements();

    return 0;
}
