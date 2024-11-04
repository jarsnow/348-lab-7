
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    for (int row_i = 0; row_i < SIZE; row_i++){
      for (int col_i = 0; col_i < SIZE; col_i++){
        cout << "Enter a value for " << row_i << "," << col_i << ": " << endl;
        cin >> data[row_i][col_i];
      }
    }
  };

  // 2. Display a matrix
  void display() const{
    for (int row_i = 0; row_i < SIZE; row_i++){
      for (int col_i = 0; col_i < SIZE; col_i++){
        cout << data[row_i][col_i] << " ";
      }
      cout << endl;
    };
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    Matrix res;

    for (int row_i = 0; row_i < SIZE; row_i++){
      for (int col_i = 0; col_i < SIZE; col_i++){
        // add values
        res.data[row_i][col_i] = data[row_i][col_i] + other.data[row_i][col_i];
      }
    }

    return res;
  };

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    Matrix res;

    for (int row_i = 0; row_i < SIZE; row_i++){
      for (int col_i = 0; col_i < SIZE; col_i++){
        // get dot product of rows
        int dot_product = 0;
        for (int i = 0; i < SIZE; i++){
          dot_product += data[row_i][i] * other.data[i][col_i];
        }
        res.data[row_i][col_i] = dot_product;
      }
    }

    return res;
  };

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0;
    // calculate main diagonal
    for (int i = 0; i < SIZE; i++){
      sum += data[i][i];
    }
    // calculate secondary diagonal
    for (int i = 0; i < SIZE; i++){
      sum += data[i][(SIZE - 1) - i];
    }

    // subtract the middle element ONLY if it is added twice (size is odd)
    if (SIZE % 2 == 1){
      sum -= data[SIZE / 2][SIZE / 2];
    }

    return sum;
  };

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    for (int i = 0; i < SIZE; i++){
      // swap values
      int temp_val = data[row1][i];
      data[row1][i] = data[row2][i];
      data[row2][i] = temp_val;
    }
  };

};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
