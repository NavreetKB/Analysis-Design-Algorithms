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
void merge(int arr[], int l, int m, int h)
        {
            int l1=m-l+1;
            int l2=h-m;
            int *a=new int[l1];
            int *b=new int[l2];
            int k=l;
            for(int i=0;i<l1;i++){
                a[i]=arr[k++];
            }
            k=m+1;
            for(int i=0;i<l2;i++){
                b[i]=arr[k++];
            }
            int ind1=0,ind2=0;
            int mainInd=l;
            while(ind1<l1 && ind2<l2){
                if(a[ind1]<=b[ind2]){
                    arr[mainInd++]=a[ind1++];
                }
                else 
                arr[mainInd++]=b[ind2++];
            }
            while(ind1<l1 ){
                arr[mainInd++]=a[ind1++];
            }
            while(ind2<l2){
                arr[mainInd++]=b[ind2++];
            }
            return;
        }
void mergesort(int arr[], int l, int h)
        {   
            if(l>=h) return;
            int mid=(l+h)/2;
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,h);
            merge(arr,l,mid,h);
            return;
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
    for(int i=0;i<8;i++){
        sizes[i]=size;
        int *arr=new int[size];
        initialize(arr,size);
        auto start=high_resolution_clock::now();
        for(int i=0;i<10;i++){
            mergesort(arr,0,size-1);
        }
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

//Python Code
/*
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('InsertData.csv')
sizes = data['Size']
times = data['Time(nanoseconds)']

n_square=sizes**2
plt.figure(figsize=(10, 6)) 
plt.yscale('linear')
maxval=max(max(sizes),max(times))
plt.ylim(0,maxval)
plt.plot(sizes, times,label='Timecomplexity' ,marker='o', linestyle='-', color='b')  

plt.xlabel('Array Size')
plt.ylabel('Average Time (microseconds)')
plt.title('Average Time vs. Array Size')
plt.legend()
plt.show()  

*/
