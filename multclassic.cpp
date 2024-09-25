#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <limits>  
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{

    int **A;
    int **B;
    int **C;
    int **C2;

    A = new int*[1000];
    B = new int*[1000];
    C = new int*[1000];
    C2 = new int*[1000];

    for (int i =0; i < 1000; i++){
        A[i]=new int[1000];
        B[i]=new int[1000];
        C[i]=new int[1000];
        C2[i]=new int[1000];

    }


    //int A[20][20], B[20][20], C[20][20], C2[20][20];
    int k, m, n;



    k =1000; 
    m = 1000;
    n=1000;

    for (int i =0; i < 1000;i++)
        for (int j=0; j < 1000;j++)
            A[i][j] = rand()%100;
    
    for (int i =0; i < 1000;i++)
        for (int j=0; j < 1000;j++)
            B[i][j] = rand()%100;

    // Inicializamos la matriz C.
    for(int i=0; i<k; ++i)
        for(int j=0; j<n; ++j){
            C[i][j] = 0;
            C2[i][j]= 0;
        }

    auto beg = high_resolution_clock::now();


    std::cout << "begin:\n";
    // Multiplicacion normal
    for(int i=0; i<k; ++i)
        for(int j=0; j<n; ++j)
            for(int z=0; z<m; ++z)
                C[i][j] += A[i][z] * B[z][j];

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - beg);
    std::cout << "Elapsed Time: " << duration.count();

    //Multiplicación por bloques

    beg = high_resolution_clock::now();

    int q,s,r;
    q = 20;
    s = 20;
    r = 20;

    int N = 1000;

    int temp;

    for(int jj=0;jj<N;jj+= s){
        for(int kk=0;kk<N;kk+= s){
                for(int i=0;i<N;i++){
                        for(int j = jj; j<((jj+s)>N?N:(jj+s)); j++){
                                temp = 0;
                                for(int o = kk; o<((kk+s)>N?N:(kk+s)); o++){
                                        temp += A[i][o]*B[o][j];
                                }
                                C2[i][j] += temp;
                        }
                }
        }
    }

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - beg);
    std::cout << "\nElapsed Time: " << duration.count();


}