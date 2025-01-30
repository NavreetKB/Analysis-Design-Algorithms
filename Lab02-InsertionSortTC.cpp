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

void insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
            int j=i;
            while(j>0 && arr[j-1]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
            }
        }  
}

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
    for(int i=0;i<n;i++){
        arr[i]=(rand()%n+1);
    }
}

int main(){
    
    int sizes[7];
    double times[7];
    int size=10;
    for(int i=0;i<7;i++){
        sizes[i]=size;
        int *arr=new int[size];
        initialize(arr,size);
        auto start=high_resolution_clock::now();
        for(int i=0;i<10;i++){
            insertionSort(arr,size);
        }
        auto end= high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        double avg=static_cast<long double>(duration.count())/10;
        times[i]=avg;
        cout<<"size : "<<size<<"  time :"<<avg<<endl;
        size=size*3;
        delete []arr;
        
    }

    ofstream fout("InsertData.csv");
    fout<<"Size,Time(nanoseconds)"<<endl;
    for(int i=0;i<7;i++){
        fout<<sizes[i]<<","<<times[i]<<endl;
    }
    fout.close();
    return 0;
}


//Python Code for plotting graph
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

n_square=n_square*(max(times)/max(n_square))

plt.plot(sizes, times,label='Timecomplexity' ,marker='o', linestyle='-', color='b')  
plt.plot(sizes,n_square,marker='o', linestyle='-', color='r',label='n^2')

plt.xlabel('Array Size')
plt.ylabel('Average Time (nanoseconds)')
plt.title('Average Time vs. Array Size')
plt.legend()
plt.show()  



# Size,time(nanoseconds)
# 179,312.72
# 199,452.37
# 219,489.2
# 239,498.84
# 259,678.52
# 279,924.72
# 299,971.39
# 319,1048.53
# 339,1159.86
# 359,1323.39
*/
