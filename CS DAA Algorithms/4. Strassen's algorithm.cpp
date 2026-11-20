#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Matrix = vector<vector<int>>;

// Helper function to add two matrices
Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Helper function to subtract matrix B from matrix A
Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Recursive Strassen multiplication for power-of-2 square matrices
Matrix strassenRecursive(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // Base case: 1x1 matrix
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    // Partition A and B into 4 submatrices of size (n/2) x (n/2)
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Compute the 7 Strassen products
    Matrix M1 = strassenRecursive(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenRecursive(addMatrix(A21, A22), B11);
    Matrix M3 = strassenRecursive(A11, subMatrix(B12, B22));
    Matrix M4 = strassenRecursive(A22, subMatrix(B21, B11));
    Matrix M5 = strassenRecursive(addMatrix(A11, A12), B22);
    Matrix M6 = strassenRecursive(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenRecursive(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combine products into the 4 quadrants of C
    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    // Merge quadrants into the result matrix C
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j]         = C11[i][j];
            C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

// Wrapper function handling arbitrary matrix sizes via zero-padding
Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // Find next power of 2 >= n
    int m = 1;
    while (m < n) {
        m *= 2;
    }

    Matrix paddedA(m, vector<int>(m, 0));
    Matrix paddedB(m, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            paddedA[i][j] = A[i][j];
            paddedB[i][j] = B[i][j];
        }
    }

    Matrix paddedC = strassenRecursive(paddedA, paddedB);

    // Extract the original n x n result
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = paddedC[i][j];
        }
    }

    return C;
}

int main() {
    int n;
    cout << "Enter dimension n for n x n matrices: ";
    cin >> n;

    if (n <= 0) {
        cout << "Matrix size must be positive." << endl;
        return 0;
    }

    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter elements of Matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    Matrix C = strassenMultiply(A, B);

    cout << "\nResultant Matrix C = A * B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}