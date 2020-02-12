//a class to represent a a matrix
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 9;

class Matrix {
  private:
    int dimen[3][3];
  public:
    //Constructor
    Matrix()
    {
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
      //delete [] elem;
    }


    int getValue(int i, int j) {
        int value = dimen[i][j];
        return value;
    }


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

//Each thread computes single element in the resultant matrix 
static void* mult(void* arg)
{
    int* data = (int*)arg;
    int k = 0;
    int x = data[0];
    for (int i = 1; i <= x; i++) {
        k += data[i] * data[i + x];
    }
    int* p = (int*)malloc(sizeof(int));
    *p = k;
    //Used to terminate a thread and the return value is passed as a pointer 
    pthread_exit(p);
}
static void multiplication(Matrix m1, Matrix m2) {
    /*=============================================================*/
    int i, j, k;
    int max = 9;		 
    pthread_t* threads;
    threads = (pthread_t*)malloc(max * sizeof(pthread_t));
    int count = 0;
    int* data = NULL;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            //storing row and column elements in data 
            data = (int*)malloc((20) * sizeof(int));
            data[0] = 3;

            for (k = 0; k < 3; k++) {
                data[k + 1] = m1.getValue(i, k);
            }
            for (k = 0; k < 3; k++) {
                data[k + 3 + 1] = m2.getValue(k, j);
            }
            //creating threads 
            pthread_create(&threads[count++], NULL, mult, (void*)(data));

        }
    }
    printf("\n");
    for (i = 0; i < max; i++) {
        void* k;
        //Joining all threads and collecting return value 
        pthread_join(threads[i], &k);
        int* p = (int*)k;
        printf("%d ", *p);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    /*=============================================================*/
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


