#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include<math.h>
#include<iomanip>
#include <chrono> 
#include <fstream>

using namespace std;
using namespace std::chrono; 

void wrap(int &x, int &y, int n) {
    if(x<0){
        x=n-1;
    }
    if(y<0){
        y=n-1;
    }
    if(x>=n){
        x=0;
    }
    if(y>=n){
        y=0;
    }
}


void magic(int n){
    int **arr=new int*[n];
    for( int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=-1;
        }
    }
    arr[0][n/2]=1;
    int x=0;
    int y=n/2;
    int newx=0,newy=0;
    for(int i=2;i<=(n*n);i++){
        newx=x-1;
        newy=y-1;
        wrap(newx,newy,n);
        if(arr[newx][newy]!=-1){
           x=x+1;
           wrap(x,y,n); 
        }
        else{
            x=newx;
            y=newy;
        }
        arr[x][y]=i;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    delete []arr;

}

int main(){
    // cout<<"enter the dimension of square";
    // int n=0;
    // cin>>n;

    // if(n<=0){
    //     cout<<"invalid input\n";
    // }

    // magic(n);

    int sizes[6];
    double times[6];
    int size=3;

    for(int i=0;i<6;i++){
        sizes[i]=size;
        cout<<"size of square : "<<size<<"  ";
        auto start = high_resolution_clock::now();
        for(int j=0;j<100;j++){
          magic(size);
        }
        auto end= high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        double avg = static_cast<long double>(duration.count())/100;
        times[i]=avg;
        cout<<"time taken "<<avg<<endl;
        size=size*3;
        
    }
    ofstream fout("magicData.csv");
    fout<<"Size,time(nanoseconds)"<<endl;
    for(int i=0;i<6;i++){
        fout<<sizes[i]<<","<<times[i]<<endl;
    }
    fout.close();
    return 0;
}
