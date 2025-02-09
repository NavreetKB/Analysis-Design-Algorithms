#include<iostream>
#include<ctime>
#include<cmath>
#include<math.h>
#include<iomanip>
#include <chrono> 
#include <fstream>

using namespace std;
using namespace std::chrono; 

bool binsearch(int arr[],int size,int num)
{
    int s=0,e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
       if(arr[mid]==num)
       {
        return true;
       }
       else if(num>arr[mid])
       {
        s=mid+1;
       }
       else if(num<arr[mid])
       {
         e=mid-1;
       }
       mid=s+(e-s)/2;
    }
    return false;
}

void initialize(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=i;
    }
   
} 

int main()
{  
	int sizes[7];
    double times[7];
    bool ans;
    int size=50;
    long double avg=0;
    for (int i=0;i<7;i++)
    {
       sizes[i]=size;
       int* arr=new int[size];
       cout<<"size of array=  "<< size<<"   ";
       initialize(arr,size);
       auto start = high_resolution_clock::now();
      
       for(int j=0;j<100;j++)
       {
         ans=binsearch(arr,size,arr[size]);
       }
       auto end = high_resolution_clock::now();
       auto duration = duration_cast<nanoseconds>(end - start);
      
        avg = static_cast<long double>(duration.count())/100;
       cout<<"average time is " <<avg <<endl;
       
       delete []arr;
       times[i]=avg;
       size=size*10;
    }
  
    ofstream fout("data.csv");
    cout<<"created a file\n";
        fout << "Size,Time (microseconds)\n";  
        for (int i = 0; i < 7; i++) {
            fout<< sizes[i] << "," << times[i] << "\n";
        }
        fout.close(); 
    ifstream infile("data.csv");
    
    if (infile.is_open()) {
        string line;
        cout << "\nContents of data.csv:\n";
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close(); 
    } 
    else {
        cout << "Unable to open file for reading." << endl;
    }
    return 0;

}
