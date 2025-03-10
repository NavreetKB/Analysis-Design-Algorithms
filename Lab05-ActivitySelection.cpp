#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<cstdlib> 
#include<iomanip>
#include <ctime>
using namespace std;

int partitionByFinish(int arr[3][15], int s,int e){
    int pivot=arr[2][s];
    int i=s,j=e;
    while(i<j){
        while(arr[2][i]<=pivot && i<e)
        i++;
        while(arr[2][j]>pivot && j>s)
        j--;
        if(i<j)
        {
            swap(arr[0][i],arr[0][j]);
            swap(arr[1][i],arr[1][j]);
            swap(arr[2][i],arr[2][j]);
        }
        
    }
    swap(arr[0][s],arr[0][j]);
    swap(arr[1][s],arr[1][j]);
    swap(arr[2][s],arr[2][j]);
    return j;
}

int partitionByStart(int arr[2][15], int s,int e){
    int pivot=arr[1][s];
    int i=s,j=e;
    while(i<j){
        while(arr[1][i]<=pivot && i<e)
        i++;
        while(arr[1][j]>pivot && j>s)
        j--;
        if(i<j)
        {
            swap(arr[0][i],arr[0][j]);
            swap(arr[1][i],arr[1][j]);
            swap(arr[2][i],arr[2][j]);
        }
        
    }
    swap(arr[0][s],arr[0][j]);
    swap(arr[1][s],arr[1][j]);
    swap(arr[2][s],arr[2][j]);
    return j;
}

int partitionByDuration(float arr[4][15], int s,int e){
    int pivot=arr[3][s];
    int i=s,j=e;
    while(i<j){
        while(arr[3][i]<=pivot && i<e)
        i++;
        while(arr[3][j]>pivot && j>s)
        j--;
        if(i<j)
        {
            swap(arr[0][i],arr[0][j]);
            swap(arr[1][i],arr[1][j]);
            swap(arr[2][i],arr[2][j]);
            swap(arr[3][i],arr[3][j]);
        }
        
    }
    swap(arr[0][s],arr[0][j]);
    swap(arr[1][s],arr[1][j]);
    swap(arr[2][s],arr[2][j]);
    swap(arr[3][s],arr[3][j]);
    return j;
}

void quicksort(int arr[3][15],int s,int e,bool flag){
    if(s>=e) return;
    int p;
    if(flag==true){
        p=partitionByStart(arr,s,e);
    }
    else{
        p=partitionByFinish(arr,s,e);
    }
    quicksort(arr,s,p-1,flag);
    
    quicksort(arr,p+1,e,flag);
}

void quicksort2(float arr[4][15],int s,int e){
    if(s>=e) return;
    int p=partitionByDuration(arr,s,e);
    quicksort2(arr,s,p-1);
    
    quicksort2(arr,p+1,e);
}

int* activitySelection(int arr[3][15]){
    int c=24;
    int *result=new int[15];
    for(int i=0;i<15;i++){
        result[i]=-1;
    }
    int prev_finish=-1;
    for(int i=0;i<15;i++){
        if(c<=0){
           result[i]=-1;
        }
        else if(arr[1][i]<prev_finish){
            continue;
        }
        else if(c >=(arr[2][i]-arr[1][i]) && arr[1][i] >= prev_finish){
            result[i]=arr[0][i];
            prev_finish=arr[2][i];
            c-=(arr[2][i]-arr[1][i]);
            
        }
        
    }
    return result;
}

int* activitySelection2(float arr[4][15]){
    int c=24;
    int *ans=new int[15];
    for(int i=0;i<15;i++){
        ans[i]=-1;
    }
    int prev_finish=-1;
    for(int i=0;i<15;i++){
        if(c<=0){
           ans[i]=-1;
        }
        else if(arr[1][i]<prev_finish){
            continue;
        }
        else if(c >= arr[3][i] && arr[1][i] >= prev_finish){
            ans[i]=arr[0][i];
            prev_finish=arr[2][i];
            c-=arr[3][i];
            
        }
     
        
    }
    return ans;
}

void initialise(int arr[2][15],int n){
    for(int i=0;i<n;i++){
        arr[0][i]=i;
        arr[1][i]=rand()%23;
        int k=arr[1][i]+ (rand()%20+1);
        if(k<=24){
            arr[2][i]=k;
        }
        else{
            arr[2][i]=arr[1][i]+1;
        }

    }
}

int main(){

    int arr[3][15]={0};
    srand(time(0));

    for(int i=0;i<5;i++){

    
    initialise(arr,15);


    int temp[3][15]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<15;j++){
            temp[i][j]=arr[i][j];
        }
    }

    cout<<"  ORIGINAL TABLE  \n";
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }cout<<endl;
    
    for(int i=0;i<3;i++){
        if(i==0)
           cout<<setw(8)<<" JOBS |";
        if(i==1)
           cout<<setw(8)<<"START |";
        if(i==2)
           cout<<setw(8)<<"FINISH|";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }
    
    cout<<setw(100)<<"********************** Sorting by start time ************************* \n";
    quicksort(arr,0,14,true);
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }cout<<endl;
    
    cout<<endl;
    for(int i=0;i<3;i++){
        if(i==0)
           cout<<setw(8)<<" JOBS |";
        if(i==1)
           cout<<setw(8)<<"START |";
        if(i==2)
           cout<<setw(8)<<"FINISH|";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }
    int *result=activitySelection(arr);
    cout<<"Result : \n";
    int cnt=0;
    for(int l=0;l<15;l++){
        if(result[l]==-1) continue;
        cout<<"J"<<result[l]<<"   ";
        cnt++;
    }cout<<endl;
    cout<<"No. of jobs executed : "<<cnt<<endl;




    cout<<setw(100)<<"********************** Sorting by Finish time ************************* \n";
    quicksort(arr,0,14,false);
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }cout<<endl;
    
    cout<<endl;
    for(int i=0;i<3;i++){
        if(i==0)
           cout<<setw(8)<<" JOBS |";
        if(i==1)
           cout<<setw(8)<<"START |";
        if(i==2)
           cout<<setw(8)<<"FINISH|";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }
   
    int *result2=activitySelection(arr);
    cout<<"Result : \n";
    cnt=0;
    for(int l=0;l<15;l++){
        if(result2[l]==-1) continue;
        cout<<"J"<<result2[l]<<"   ";
        cnt++;
    }cout<<endl;
    cout<<"No. of jobs executed : "<<cnt<<endl;






    cout<<setw(100)<<"**************** Sorted by Duration ***************\n";
    float arr2[4][15]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<15;j++){
            arr2[i][j]=temp[i][j];
        }
    }
    for(int i=0;i<15;i++){
        arr2[3][i] = arr2[2][i]-arr2[1][i];
    } 

    quicksort2(arr2,0,14);
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }cout<<endl;
    
    for(int i=0;i<4;i++){
        if(i==0)
           cout<<setw(10)<<" JOB |";
        if(i==1)
           cout<<setw(10)<<"START |";
        if(i==2)
           cout<<setw(10)<<"FINISH|";
        if(i==3)
           cout<<setw(10)<<"DURATION|";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr2[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }
    int *result3=activitySelection2(arr2);
    cout<<"Result : \n";
    cnt=0;
    for(int l=0;l<15;l++){
        if(result3[l]==-1) continue;
        cout<<"J"<<result3[l]<<"   ";   
        cnt++;
    }cout<<endl;
    cout<<"No. of jobs executed : "<<cnt<<endl;
    
    
    }
    

    return 0;
}
