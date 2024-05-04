#include <iostream>

using namespace std;

class DynamicMatrix {
private:
    int rows;
    int cols;
    int **matrix; // Pointer to a 2D array

public:
    // Constructor to initialize the matrix with specified dimensions
    DynamicMatrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        // Allocate memory for the matrix
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    // Destructor to free dynamically allocated memory
    ~DynamicMatrix() {
        // Deallocate memory for the matrix
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Function to set the value at a specific position in the matrix
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            matrix[row][col] = value;
        } else {
            cout << "Invalid matrix indices." << endl;
        }
    }

    // Function to get the value at a specific position in the matrix
    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return matrix[row][col];
        } else {
            cout << "Invalid matrix indices." << endl;
            return 0; // Return a default value (can be adjusted based on use case)
        }
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a dynamic matrix with 3 rows and 4 columns
    DynamicMatrix mat(3, 4);

    // Set values in the matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            mat.setValue(i, j, (i * 4) + j + 1);
        }
    }

    // Display the matrix
    cout << "Matrix:" << endl;
    mat.display();

    // Get and display a specific value from the matrix
    int row = 1;
    int col = 2;
    cout << "Value at position (" << row << ", " << col << "): " << mat.getValue(row, col) << endl;

    return 0;
}
