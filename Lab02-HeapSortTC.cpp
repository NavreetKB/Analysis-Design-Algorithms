#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include<math.h>
#include<iomanip>
#include <chrono> 
#include <fstream>
#include<random>

using namespace std;
using namespace std::chrono; 
void heapify(int arr[],int n,int index){
        int l=index*2+1;
        int r=index*2+2;
        int large=index;
        if(l<n && arr[l]>arr[large]){
            large=l;
        }
        if(r<n && arr[r]>arr[large]){
            large=r;
        }
        if(large!=index){
            swap(arr[index],arr[large]);
            heapify(arr,n,large);
        }
    }

void heapsort(int arr[],int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }

void initialize(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=(rand()%n+1);
    }
}
int main(){
    
    int sizes[8];
    double times[8];
    int size=10;
    for(int i=0;i<7;i++){
        sizes[i]=size;
        int *arr=new int[size];
        initialize(arr,size);
        auto start=high_resolution_clock::now();
        // for(int i=0;i<10;i++){
            heapsort(arr,size-1);
        
        auto end= high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        double avg=static_cast<long double>(duration.count())/10;
        times[i]=avg;
        cout<<"size : "<<size<<"  time :"<<avg<<endl;
        size=size*5;
        delete []arr;
        
    }

    ofstream fout("InsertData.csv");
    fout<<"Size,Time(nanoseconds)"<<endl;
    for(int i=0;i<8;i++){
        fout<<sizes[i]<<","<<times[i]<<endl;
    }
    fout.close();
    return 0;
}

