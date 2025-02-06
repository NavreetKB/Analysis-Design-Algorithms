#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<iomanip>

using namespace std;
int partitionByWt(int arr[2][7], int s,int e){
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

int partitionByProfit(int arr[2][7], int s,int e){
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

void quicksort(int arr[2][7],int s,int e){
        if(s>=e) return;
        int p=partitionByWt(arr,s,e);
        quicksort(arr,s,p-1);
        
        quicksort(arr,p+1,e);
}

int partitionPbyW(float arr[3][7], int s,int e){
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

void quicksort2(float arr[3][7],int s,int e){
        if(s>=e) return;
        int p=partitionPbyW(arr,s,e);
        quicksort2(arr,s,p-1);
        
        quicksort2(arr,p+1,e);
}


float* KnapSack(int arr[2][7],float c){
    float *result=new float[7]{0};
    for(int i=0;i<7;i++){
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

float* knapWeight(int arr[2][7],float c){
        float *result=new float[7]{0};
    for(int i=0;i<7;i++){
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

float* knapPW(float arr[3][7],float c){
        float *result=new float[7]{0};
    for(int i=0;i<7;i++){
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

int main(){
    int arr[2][7]={{12,14,10,7,5,15,9},
                   {2,35,7,15,5,7,3}};
    
    int temp[2][7]={0};
    for(int i=0;i<2;i++){
        for(int j=0;j<7;j++){
            temp[i][j]=arr[i][j];
        }
    }

    quicksort(arr,0,6);
    float C=25;
    cout<<"sorted in non increasing order"<<endl;
    for(int i=0;i<7;i++){
        cout<<arr[0][i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<7;i++){
        cout<<arr[1][i]<<"  ";
    }
    cout<<endl;
    
    float* output=knapWeight(arr,C);
    float answer[7]={0};
    cout<<endl<<endl;
     for(int i=0;i<2;i++){
          for(int j=0;j<7;j++){
           cout<<temp[i][j]<<"  ";
          }
          cout<<endl;
        }  
    cout<<"answer : "<<endl;

        for(int i=0;i<7;i++){
          for(int j=0;j<7;j++){
            if(arr[0][i]==temp[0][j])
            {
                answer[j]=output[i];
            }
          }
        }
    for(int i=0;i<7;i++){
        cout<<answer[i]<<"  ";
    }
    

    cout<<"\n******Using Profit by weight******\n";
    float arr2[3][7]={0};
    for(int i=0;i<2;i++){
          for(int j=0;j<7;j++){
            arr2[i][j]=temp[i][j];
          }
        }    
    for(int i=0;i<7;i++){
        arr2[2][i]=float(temp[0][i])/float(temp[1][i]);
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            cout<<setw(5)<<arr2[i][j]<<"  ";
        }
        cout<<endl;
    }

    quicksort2(arr2,0,6);
    cout<<"sorted profit by weight"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            cout<<setw(5)<<arr2[i][j]<<"  ";
        }
        cout<<endl;
    }
    float* answer3=knapPW(arr2,C);
        for(int i=0;i<7;i++){
        cout<<answer3[i]<<"  ";
    }


    

}
