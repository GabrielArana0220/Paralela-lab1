#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <limits>  
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){

    cout << "A\n";

    int **A;
    int *x;
    int *y1;
 

    A = new int*[10000];
    for (int i =0; i < 10000; i++)
        A[i]=new int[10000];

    x= new int[10000];
    y1= new int[10000];
    y1= new int[10000];

    for (int i =0; i < 10000;i++){
        x[i]=rand()%100;
        y1[i]=0;
        y1[i]=0;
        for (int j=0; j < 10000;j++)
            A[i][j] = rand()%100;
    }    



    cout << "A\n";
    /*FIRST*/

    auto beg = high_resolution_clock::now();

    for (int i = 0; i < 10000; i++)
        for (int j=0; j<10000; j++)
            y1[i]+=A[i][j]*x[j];

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - beg);
 
    std::cout << "Tiempo filas: " << duration.count();


    for (int i = 0; i < 10000; i++)
        y1[i]=0;
    /*SECOND*/

    beg = high_resolution_clock::now();


    for (int j = 0; j < 10000; j++)
        for (int i=0; i<10000; i++)
            y1[i]+=A[i][j]*x[j];

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - beg);
 
    std::cout << "\nTiempo columnas: " << duration.count();
}