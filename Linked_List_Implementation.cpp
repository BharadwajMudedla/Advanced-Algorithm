#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int row, col, value;  // Row, Column, Value of non-zero element
    Node* next;           // Address of next node

    // Constructor to initialize the node
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

// Linked List class to represent the sparse matrix
class SparseMatrixLinkedList {
private:
    Node* head;  // Head pointer to the first node in the linked list

public:
    // Constructor to initialize the linked list
    SparseMatrixLinkedList() : head(nullptr) {}

    // Function to insert a non-zero element into the linked list
    void insert(int row, int col, int value) {
        Node* newNode = new Node(row, col, value);  // Create a new node
        if (head == nullptr) {
            head = newNode;  // If list is empty, set new node as head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  // Traverse to the end of the list
                temp = temp->next;
            }
            temp->next = newNode;  // Link the new node at the end of the list
        }
    }

    // Function to display the linked list along with the node addresses
    void display() {
        if (head == nullptr) {
            cout << "The matrix has no non-zero elements." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            // Display the row, column, value, and the address of the next node
            cout << "Row: " << temp->row
                 << ", Column: " << temp->col
                 << ", Value: " << temp->value
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;  // Move to the next node
        }
    }

    // Destructor to free the memory used by the linked list
    ~SparseMatrixLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to handle user input and create the sparse matrix
int main() {
    int rows, cols, value;

    SparseMatrixLinkedList sparseMatrix;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix (0 for empty):\n";
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element at Row " << i << ", Column " << j << ": ";
            cin >> value;
            if (value != 0) {
                sparseMatrix.insert(i, j, value);  // Insert non-zero value into the linked list
            }
        }
    }

    cout << "\nSparse Matrix Linked List Representation:\n";
    sparseMatrix.display();  // Display the linked list representation of the sparse matrix

    return 0;
}
