#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int max = 100;

void input(int matrixA[max][max], int matrixB[max][max], int& size, const std::string& fileName);
void print(const int matrix[max][max], int size);
void add(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size);
void multiply(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size);
void subtract(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size);

int main() {
    int matrixA[max][max];
    int matrixB[max][max];
    int size;

    input(matrixA, matrixB, size, "matrix_input.txt");

    std::cout << "Your name" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    print(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    print(matrixB, size);

    int sumMatrix[max][max];
    int productMatrix[max][max];
    int differenceMatrix[max][max];

    add(matrixA, matrixB, sumMatrix, size);
    multiply(matrixA, matrixB, productMatrix, size);
    subtract(matrixA, matrixB, differenceMatrix, size);

    std::cout << "Matrix Sum (A + B):" << std::endl;
    print(sumMatrix, size);

    std::cout << "Matrix Product (A * B):" << std::endl;
    print(productMatrix, size);

    std::cout << "Matrix Difference (A - B):" << std::endl;
    print(differenceMatrix, size);

    return 0;
}

void input(int matrixA[max][max], int matrixB[max][max], int& size, const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }
    file >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrixA[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrixB[i][j];
        }
    }
}

void print(const int matrix[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void add(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiply(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtract(const int matrixA[max][max], const int matrixB[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
