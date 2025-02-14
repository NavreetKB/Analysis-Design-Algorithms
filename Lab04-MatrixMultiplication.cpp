#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<chrono>  
#include<random>

using namespace std;
using namespace std::chrono; 

void initialise(int **mat,int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j]=(rand()%20+1);
        }
    }
}

void multiply(int**mat1, int** mat2,int startrow1,int endrow1,int startcol1,int endcol1,int startrow2,int endrow2,int startcol2,int endcol2,int **mat3){
  

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                mat3[startrow1+i][startcol2+j]+=((mat1[startrow1+i][startcol1+k])*(mat2[startrow2+k][startcol2+j]));
                
            }
        }
    }

}

void matrix(int** mat1,int** mat2,int startrow1,int endrow1,int startcol1,int endcol1,int startrow2,int endrow2,int startcol2,int endcol2,int** mat3)
{
    int midR1=(startrow1+endrow1)/2;
    int midC1=(startcol1+endcol1)/2;
    int midR2=(startrow2+endrow2)/2;
    int midC2=(startcol2+endcol2)/2;
    if((endrow1-startrow1 == 1)&&(endcol1-startcol1==1)&&(endrow2-startrow2==1)&&(endcol2-startcol2==1)){
        multiply(mat1,mat2,startrow1, endrow1, startcol1, endcol1, startrow2, endrow2, startcol2, endcol2,mat3);
        return;
    }
    
   
    matrix(mat1, mat2, startrow1, midR1, startcol1, midC1, startrow2, midR2, startcol2, midC2, mat3);
    matrix(mat1, mat2, startrow1, midR1, midC1 + 1, endcol1, midR2 + 1, endrow2, startcol2, midC2, mat3);

    matrix(mat1, mat2, startrow1, midR1, startcol1, midC1, startrow2, midR2, midC2 + 1, endcol2, mat3);
    matrix(mat1, mat2, startrow1, midR1, midC1 + 1, endcol1, midR2 + 1, endrow2, midC2 + 1, endcol2, mat3);

    matrix(mat1, mat2, midR1 + 1, endrow1, startcol1, midC1, startrow2, midR2, startcol2, midC2, mat3);
    matrix(mat1, mat2, midR1 + 1, endrow1, midC1 + 1, endcol1, midR2 + 1, endrow2, startcol2, midC2, mat3);

    matrix(mat1, mat2, midR1 + 1, endrow1, startcol1, midC1, startrow2, midR2, midC2 + 1, endcol2, mat3);
    matrix(mat1, mat2, midR1 + 1, endrow1, midC1 + 1, endcol1, midR2 + 1, endrow2, midC2 + 1, endcol2, mat3);

}

int main()
{
    
    cout<<"enter number of rows and columns of matrix1 ";
    int r1,c1;
    cin>>r1>>c1;
    cout<<"enter number of rows and columns of matrix2 ";
    int r2,c2;
    cin>>r2>>c2;
    if(c1!=r2){
        cout<<"That is an invalid matrix";
        return 0;
    }
    // int r1=8;
    // int r2=8;
    // int c1=8;
    // int c2=8;

    // int sizes[7];
    // double times[7];
//for(int i=0;i<7;i++)
    // sizes[i]=r1;
    int** mat1=new int*[r1];
    int** mat2=new int*[r2];
    int** mat3=new int*[r1];
    for(int i =0;i<r1;i++){
        mat1[i] = new int[c1];
        mat3[i] = new int[c2];
    }
    for(int i=0;i<r2;i++){
        mat2[i]=new int[c2];
    }


    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            mat3[i][j]=0;
        }
    }
    initialise(mat1,r1,c1);
    initialise(mat2,r2,c2);
    cout<<"elements of matrix1\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout<<mat1[i][j]<<"  ";
        }cout<<endl;
    }
    cout<<"\nelements of matrix2 \n";
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cout<<mat2[i][j]<<"  ";
        }cout<<endl;
    }
    // cout<<"enter elements for matrix1\n";
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>mat1[i][j];
    //     }
    // }
    // cout<<"\nenter elements for matrix2\n";
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>mat2[i][j];
    //     }
    // }
    //auto start=high_resolution_clock::now();
    
    matrix(mat1,mat2,0,r1-1,0,c1-1,0,r2-1,0,c2-1,mat3);
    // auto end= high_resolution_clock::now();
    // auto duration=duration_cast<nanoseconds>(end-start)/10;
    // double avg=static_cast<long double>(duration.count());

    cout<<"Resutant matrix\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<mat3[i][j]<<"  ";
        }
        cout<<endl;
        
    }
    for (int i=0; i<r1; i++) {
        delete[] mat1[i];
        delete[] mat3[i];
    }
    for (int i=0; i<r2; i++) {
        delete [] mat2[i];
    }

    delete []mat1;
    delete []mat2;
    delete []mat3;

    // r1*=2;
    // r2*=2;
    // c1*=2;
    // c2*=2;
    // times[i]=avg;

// for(int i=0;i<7;i++){
//     cout<<sizes[i]<<",";
// }
// cout<<endl;
// for(int i=0;i<7;i++){
//     cout<<times[i]<<",";
// }
    return 0;


}

//PYTHON CODE FOR GRAPH
/*
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure(figsize=(10,10))
x = np.array([8,16,32,64,128,256,512])
y = np.array([0,0,0,0,859500,1.25067e+007,9.75637e+007])


plt.plot(x, y,label="Timecomplexity",marker="o",color="b")
plt.plot(x, x*x*x,label="n^3",marker="o",color="r")
plt.legend()
plt.show()
*/
