/**
 * Authors
 * Andre Barajas
 * Gabriel Espejo
 */

//a class to represent a a matrix
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <pthread.h>

using namespace std;


class Matrix {
  private:
    int **dimen;
  public:
    //Constructor
    Matrix()
    {
      //allocating memory for two dimen array
      this-> dimen = new int*[3];
      for(int i = 0; i < 3; i++)
        this -> dimen[i] = new int[3];

        //assigning random integers to matrix
      srand (time(NULL));
      for(int i = 0; i < 3; i++)
      {
          for(int j = 0; j < 3; j++) {
            /* initialize random seed: */
            int number = rand() % 10 + j;
            //cout << "rando number " << number << endl;
            this-> dimen[i][j] = number;
          }
      }
    }

    //Destructor
    ~Matrix() {
      //releasing heap memory
      //deleting pointers in array first
      for(int i = 0; i < 3; i++)
        delete[] this -> dimen[i];
      //now deleting pointer
      delete[] this -> dimen;
    }

    //method to retrieve a value in matrix at an index
    int getValue(int i, int j) {
        int value = dimen[i][j];
        return value;
    }

    //method to traverse pointers in array and print int values stored
    void displayMatrix() {
      //variable to keep track of non zero elements
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          cout << this->dimen[i][j] << " ";
        }
        cout << endl;
      }
    }

};

//thread routine to multiply for each value
static void* multiply(void* args)
{
    int* data = (int*)args;
    int k = 0;
    int x = data[0];
    for (int i = 1; i <= x; i++) {
        k += data[i] * data[i + x];
    }
    int* y = new int();
    *y = k;
    pthread_exit(y);
}
  //main method to divide work b/w threads for a process
static void multiplication(Matrix m1, Matrix m2) {
    pthread_t* threads;
    threads = new pthread_t[9];
    int c = 0;
    int* data;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data = new int[20];
            data[0] = 3;

            for (int k = 0; k < 3; k++) {
                data[k + 1] = m1.getValue(i, k);
                data[k + 3 + 1] = m2.getValue(k, j);
            }
            pthread_create(&threads[c++], NULL, multiply, (void*)(data));

        }
    }
    printf("\n");
    for (int i = 0; i < 9; i++) {
        void* k;
        pthread_join(threads[i], &k);
        int* p = (int*)k;
        printf("%d ", *p);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

//main function to test matrix
int main() {
  Matrix matrix1;
  Matrix matrix2;
  matrix1.displayMatrix();
  matrix2.displayMatrix();
  multiplication(matrix1, matrix2);
  return 0;
}
