#include <iostream>
#include <vector>
using namespace std;
class SparseMatrixCSR {
private:
    vector<int> values;    
    vector<int> columnIndices;  
    vector<int> rowPointers;    
public:
    SparseMatrixCSR(int numRows, int numCols, const vector<vector<int>>& matrix) {
        int nnz = 0;  
        for (int i = 0; i < numRows; i++) {
            rowPointers.push_back(nnz);
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] != 0) {
                    values.push_back(matrix[i][j]);
                    columnIndices.push_back(j);
                    nnz++;
                }
            }
        }
        rowPointers.push_back(nnz);
    }

    void print() {
        int numRows = rowPointers.size() - 1;
        for (int i = 0; i < numRows; i++) {
            for (int j = rowPointers[i]; j < rowPointers[i + 1]; j++) {
                cout << values[j] << " (col " << columnIndices[j] << ") ";
            }
            cout << endl;
        }
    }
    vector<int> multiply(const vector<int>& vector1) {
        int numRows = rowPointers.size() - 1;
        vector<int>result(numRows, 0);
        for (int i = 0; i < numRows; i++) {
            for (int j = rowPointers[i]; j < rowPointers[i + 1]; j++) {
                result[i] += values[j] * vector1[columnIndices[j]];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    vector<int> vector1 = {1, 2, 3, 4, 5};
    SparseMatrixCSR sparseMatrix(matrix.size(), matrix[0].size(), matrix);
    cout << "Sparse Matrix (CSR format):" << endl;
    sparseMatrix.print();
    vector<int>result = sparseMatrix.multiply(vector1);
    cout << "\nResult of matrix-vector multiplication:" << endl;
    for (int value : result) {
        cout << value << " ";
    }
    return 0;
}
