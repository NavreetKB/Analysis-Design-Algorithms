#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<chrono> 
#include<fstream>
#include<random>

using namespace std;
using namespace std::chrono; 

void selection(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
               min=j;
            }
        }
        swap(arr[i],arr[min]);
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
    for(int i=0;i<6;i++){
        sizes[i]=size;
        int *arr=new int[size];
        initialize(arr,size);
        auto start=high_resolution_clock::now();
        for(int i=0;i<10;i++){
            selection(arr,size);
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
    for(int i=0;i<7;i++){
        fout<<sizes[i]<<","<<times[i]<<endl;
    }
    fout.flush();
    fout.close();
    return 0;
}

/*
PYTHON CODE 
import matplotlib.pyplot as plt

sizes = [10,50,250,1250,6250,31250]
times = [0.1,1.2,25.9,572.7,11715.1,381244]
scaling_factor = times[0] / (sizes[0] ** 2)
n_squared_times = [scaling_factor * (n ** 2) for n in sizes]

plt.plot(sizes, times, 'o-',color="b", label='TimeComplexity')
plt.plot(sizes, n_squared_times, '-', label='$O(n^2)$',color="r")
plt.xlabel('Input Size (n)')
plt.ylabel('Execution Time')
plt.legend()
plt.grid()
plt.show()
*/
