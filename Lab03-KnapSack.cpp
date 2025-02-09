#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<cstdlib> 
#include<iomanip>
#include <ctime>

using namespace std;
int partitionByWt(int arr[2][15], int s,int e){
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
            }
            
        }
        swap(arr[0][s],arr[0][j]);
        swap(arr[1][s],arr[1][j]);
        return j;
}

int partitionByProfit(int arr[2][15], int s,int e){
        int pivot=arr[0][s];
        int i=s,j=e;
        while(i<j){
            while(arr[0][i]>=pivot && i<e)
            i++;
            while(arr[0][j]<pivot && j>s)
            j--;
            if(i<j)
            {
                swap(arr[0][i],arr[0][j]);
                swap(arr[1][i],arr[1][j]);
            }
            
        }
        swap(arr[0][s],arr[0][j]);
        swap(arr[1][s],arr[1][j]);
        return j;
}

int partitionPbyW(float arr[3][15], int s,int e){
        int pivot=arr[2][s];
        int i=s,j=e;
        while(i<j){
            while(arr[2][i]>=pivot && i<e)
            i++;
            while(arr[2][j]<pivot && j>s)
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


void quicksort(int arr[2][15],int s,int e,bool flag){
        if(s>=e) return;
        int p;
        if(flag==true){
            p=partitionByProfit(arr,s,e);
        }
        else{
            p=partitionByWt(arr,s,e);
        }
        quicksort(arr,s,p-1,flag);
        
        quicksort(arr,p+1,e,flag);
}


void quicksort2(float arr[3][15],int s,int e){
        if(s>=e) return;
        int p=partitionPbyW(arr,s,e);
        quicksort2(arr,s,p-1);
        
        quicksort2(arr,p+1,e);
}


float* KnapSack(int arr[2][15],float c){
    float *result=new float[15]{0.0};
    for(int i=0;i<15;i++){
        if(c<=0  || std::abs(c) < 1e-6){
            result[i]=0;
        }
        else if(arr[1][i]<=c){
           result[i]=1;
           c=c-arr[1][i];
        }
        else if(c!=0){
          float f=c/(arr[1][i]);
          result[i]=f;
          float fractionWt=(arr[1][i])*f;
          c=c-fractionWt;
        }
    }
      
    return result;
}



float* knapPW(float arr[3][15],float c){
        float *result=new float[15]{0};
    for(int i=0;i<15;i++){
        if(c<=0){
            result[i]=0;
        }
        else if(arr[1][i]<=c){
           result[i]=1;
           c=c-arr[1][i];
        }
        else if(c!=0){
        
          float f=c/(arr[1][i]);
          result[i]=f;
          float fractionWt=(arr[1][i])*f;
          c=c-fractionWt;
        }
    }
       
    return result;
} 

void initialise(int arr[2][15]){
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<15;j++){
            arr[i][j]=(rand()%80+1);
        }
    }
}

int main(){
    // int arr[2][15]={{12,14,10,7,5,15,9,22,11,2,4,16,17,21,18},
    //                {2,35,7,15,5,7,3,10,11,12,7,3,6,8,22}};
    int arr[2][15]={0};
    srand(time(0));
for(int i=0;i<10;i++){


    initialise(arr);
    int C=100;
    int temp[2][15]={0};
    for(int i=0;i<2;i++){
        for(int j=0;j<15;j++){
            temp[i][j]=arr[i][j];
        }
    }

    cout<<setw(80)<<"**************** Sorted by profit ******************\n";
    bool flag=true;
    quicksort(arr,0,14,flag);
    for(int p=0;p<16;p++){
            cout<<"-------+";
        }
        cout<<endl;
    for(int i=0;i<2;i++){
        
        if(i==0)
           cout<<"PROFIT |";
        if(i==1)
           cout<<"WEIGHT |";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }

    float* answer=KnapSack(arr,C);

    cout<<"RESULT |";
    for(int i=0;i<15;i++){
       cout<<setw(4)<<setprecision(2)<<answer[i]<<setw(4)<<"|";
    }
    cout<<endl;
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }
    cout<<endl<<endl;
    
    cout<<setw(80)<<"**************** Sorted by Weight ******************\n";
    flag=false;
    quicksort(arr,0,14,flag);
    for(int p=0;p<16;p++){
            cout<<"-------+";
        }
        cout<<endl;
    for(int i=0;i<2;i++){
        
        if(i==0)
           cout<<"PROFIT |";
        if(i==1)
           cout<<"WEIGHT |";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<arr[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }

    float* ansWt=KnapSack(arr,C);

    cout<<"RESULT |";
    for(int i=0;i<15;i++){
       cout<<setw(4)<<setprecision(2) <<ansWt[i]<<setw(4)<<"|";
    }
    cout<<endl;
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }

    cout<<endl;
    
    cout<<setw(100)<<"**************** Sorted by Profit per unit Weight ***************\n";
    float arr2[3][15]={0};
    for(int i=0;i<2;i++){
        for(int j=0;j<15;j++){
            arr2[i][j]=temp[i][j];
        }
    }
    for(int i=0;i<15;i++){
        arr2[2][i] = float(temp[0][i])/float(temp[1][i]);
       
    } 
    quicksort2(arr2,0,14);
    for(int p=0;p<16;p++){
            cout<<"-------+";
        }
        cout<<endl;
    for(int i=0;i<3;i++){
        
        if(i==0)
           cout<<"PROFIT |";
        if(i==1)
           cout<<"WEIGHT |";
        if(i==2)
           cout<<"P/W    |";
        for(int j=0;j<15;j++){
            cout<<setw(4)<<setprecision(2)<<arr2[i][j]<<setw(4)<<"|";
        }
        cout<<endl;
        for(int k=0;k<16;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }

    float* ansPW=knapPW(arr2,C);

    cout<<"RESULT |";
    for(int i=0;i<15;i++){
       cout<<setw(4)<<setprecision(2)<<ansPW[i]<<setw(4)<<"|";
    }
    cout<<endl;
    for(int p=0;p<16;p++){
        cout<<"-------+";
    }
    
    cout<<endl;
}
    return 0;

}



