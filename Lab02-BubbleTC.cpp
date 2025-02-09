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

void bubble(int*arr,int n)
{
    bool swapped;

    for(int i=0;i<n-1;i++) {
        swapped = false;
        for (int j=0;j<n -i -1;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        if (!swapped)
            break;
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
