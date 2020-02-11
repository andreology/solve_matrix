//a class to represent a a matrix
#include <iostream>
using namespace std;

class MatrixElement {
  public:
    int i, j, x;
};

class SparseMatrix {
  private:
    int m, n, number;
    MatrixElement *elem;
  public:
    //Constructor
    SparseMatrix(int m, int n, int number)
    {
      this -> m = m;
      this -> n = n;
      this -> number = number;
      elem = new MatrixElement[this -> number];
    }
    //Destructor
    ~SparseMatrix() {
      delete [] elem;
    }
    void readElements() {
      //collecting matrix values from user
      cout << "Input Elements not equal to zero";
      for(int i = 0; i < number; i++)
        cin >> elem[i].i >> elem[i].j >> elem[i].x;
    }
    void displayMatrix() {
      //variable to keep track of non zero elements
      int k = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if(elem[k].i == i && elem[k].j == j)
          cout << elem[k++].x << " ";
          else
            cout << "0 ";
            //for zero elemetns
        }
        cout << endl;
      }
    }
};

//main function to test matrix
int main() {
  SparseMatrix matrix(5, 5, 5);
  matrix.readElements();
  matrix.displayMatrix();
  return 0;
}
