//a class to represent a a matrix
#include <iostream>
#include <time.h>

using namespace std;


class Matrix {
  private:
    int dimen[3][3];
  public:
    //Constructor
    Matrix()
    {

      for(int i = 0; i < 3; i++)
      {
          for(int j = 0; j < 3; j++) {
            /* initialize random seed: */
            srand (time(NULL));
            int number = rand() % 10 + 1;
            this-> dimen[i][j] = number;
          }
      }
    }
    //Destructor
    ~Matrix() {
      //delete [] elem;
    }
    void displayMatrix() {
      //variable to keep track of non zero elements
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          cout << this->dimen[i][j];
        }
        cout << endl;
      }
    }


};

//main function to test matrix
int main() {
  Matrix matrix;
  matrix.displayMatrix();
  return 0;
}
