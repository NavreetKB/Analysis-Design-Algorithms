#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<chrono>  
#include<random>
#include<iomanip>

using namespace std;
using namespace std::chrono; 

void initialise(vector<vector<int>> &mat,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j]=(rand()%20+1);
        }
    }
}

vector<vector<int>> add(vector<vector<int>> a , vector<vector<int>> b , int n){
    vector<vector<int>> c(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    return c;
}


vector<vector<int>> sub(vector<vector<int>> a , vector<vector<int>> b , int n){
    vector<vector<int>> c(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    return c;
}

vector<vector<int>> conventional(vector<vector<int>> a,vector<vector<int>> b,int n){
    vector<vector<int>> c(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

vector<vector<int>> strassen(const vector<vector<int>> & A,const vector<vector<int>> &B, int n){

    if(n==2){
       return conventional(A,B,n);
    }
    
    vector<vector<int>> A11(n/2, vector<int>(n/2));
    vector<vector<int>> A12(n/2, vector<int>(n/2));
    vector<vector<int>> A21(n/2, vector<int>(n/2));
    vector<vector<int>> A22(n/2, vector<int>(n/2));
    vector<vector<int>> B11(n/2, vector<int>(n/2));
    vector<vector<int>> B12(n/2, vector<int>(n/2));
    vector<vector<int>> B21(n/2, vector<int>(n/2));
    vector<vector<int>> B22(n/2, vector<int>(n/2));

    for (int i=0; i <n/2; i++) {
        for (int j =0; j <n/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+n/2];
            A21[i][j] = A[i+n/2][j];
            A22[i][j] = A[i+n/2][j+n/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+n/2];
            B21[i][j] = B[i+n/2][j];
            B22[i][j] = B[i+n/2][j + n/2];
        }
    }

    vector<vector<int>> P = strassen(add(A11, A22, n/2), add(B11, B22, n/2), n/2);
    vector<vector<int>> Q = strassen(add(A21, A22, n/2), B11, n/2);
    vector<vector<int>> R = strassen(A11, sub(B12, B22, n/2), n/2);
    vector<vector<int>>S = strassen(A22, sub(B21, B11, n/2), n/2);
    vector<vector<int>> T = strassen(add(A11, A12, n/2), B22, n/2);
    vector<vector<int>> U = strassen(sub(A21, A11, n/2), add(B11, B12, n/2), n/2);
    vector<vector<int>> V = strassen(sub(A12, A22, n/2), add(B21, B22, n/2), n/2);

    vector<vector<int>> C11 = add(sub(add(P, S, n/2), T, n/2), V, n/2);
    vector<vector<int>> C12 = add(R, T, n/2);
    vector<vector<int>> C21 = add(Q, S, n/2);
    vector<vector<int>> C22 = add(sub(add(P, R, n/2),Q, n/2), U, n/2);


    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n/2] = C12[i][j];
            C[i + n/2][j] = C21[i][j];
            C[i + n/2][j + n/2] = C22[i][j];
        }
    }

    return C;
}

void print(vector<vector<int>> C,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<setw(6)<<C[i][j];
        }
        cout<<endl;
    }
}

int main(){
    // cout<<"enter number of rows and columns of matrix1 ";
    // int r1,c1;
    // cin>>r1>>c1;
    // cout<<"enter number of rows and columns of matrix2 ";
    // int r2,c2;
    // cin>>r2>>c2;
    // if(c1!=r2){
    //     cout<<"That is an invalid matrix";
    //     return 0;
    // }
    // if(r1%2!=0 || r2%2 !=0 || c1%2!= 0 || c2%2!=0){
    //     cout<<"matrix dimensions should be power of 2";
    //     return 0;
    // }

    int *sizes=new int[6];
    double* times=new double[6];
    int r1,r2,c1,c2;
    r1=r2=c1=c2=2;
    for(int i=0;i<6;i++){

    sizes[i]=r1;
    vector<vector<int>> A(r1,vector<int>(c1));
    vector<vector<int>> B(r2,vector<int>(c2));
    
    srand(time(0));
    initialise(A,r1,c1);
    initialise(B,r2,c2);

    // cout<<"Matrix A : \n";
    // print(A,r1,c1);
    // cout<<"Matrix B : \n";
    // print(B,r2,c2);
     
    vector<vector<int>> C(r1,vector<int>(c2));

    auto start = high_resolution_clock::now();
    C=strassen(A,B,r1);
    auto end= high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    double avg = static_cast<long double>(duration.count());
    times[i]=avg;
    cout<<"Resultant matrix C :\n";
    print(C,r1,c2);
    r1*=2;
    r2*=2;  
    c1*=2;
    c2*=2;

    }
    
    for(int i=0;i<6;i++){
        cout<<sizes[i]<<", ";
    }
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<times[i]<<", ";
    }

    return 0;
}


/* PYTHON CODE 
import matplotlib.pyplot as plt
import numpy as np

x = np.array([2, 4, 8, 16, 32, 64, 128])
y = np.array([2, 49, 378, 2265, 17893, 113186, 1.07008e+06])
y1=x**3

plt.title("Strassen's algorihtm Time complexity")
plt.xlabel("Array size")
plt.ylabel("Time (microseconds)")
plt.plot(x, y,color='b',label="Stassen's (n^2.81)",marker="o")
plt.plot(x,y1,color='r',linestyle="--", label ="Conventional (n^3)",marker="o")
plt.legend()
plt.grid(True)
plt.show()
*/
