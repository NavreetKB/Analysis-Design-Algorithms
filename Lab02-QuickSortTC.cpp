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
int partition(int *arr, int s,int e){
        int pivot=arr[s];
        int i=s,j=e;
        while(i<j){
            while(arr[i]<=pivot && i<e)
            i++;
            while(arr[j]>pivot && j>s)
            j--;
            if(i<j)
            swap(arr[i],arr[j]);
        }
        swap(arr[s],arr[j]);
        return j;
}

void quicksort(int *arr,int s,int e){
        if(s>=e) return;
        int p=partition(arr,s,e);
        quicksort(arr,s,p-1);
        
        quicksort(arr,p+1,e);
    }

void initialize(int *arr,int n){
    for(int i=n-1;i>=0;i--){
        arr[i]=i;
    }
}

int main(){
    
    int sizes[7];
    double times[7];
    int size=4;
    for(int i=0;i<7;i++){
        sizes[i]=size;
        int *arr=new int[size];
        initialize(arr,size);
        auto start=high_resolution_clock::now();
        for(int i=0;i<10;i++){
            quicksort(arr,0,size-1);
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
    for(int i=0;i<6;i++){
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


nlogn = sizes *np.log(sizes)
plt.plot(sizes, times,label='Timecomplexity' ,marker='o', linestyle='-', color='b')  
plt.plot(sizes,nlogn,marker='o', linestyle='-', color='r',label='n^2')


plt.xlabel('Array Size')
plt.ylabel('Average Time (microseconds)')
plt.title('Average Time vs. Array Size')
plt.legend()
plt.show()  
*/
