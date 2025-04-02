#include<iostream>

using namespace std;

int partition(int* arr,int s,int e){
    int i=s;
    int j=e;
    int pivot=arr[s];
    while(i<j){
        while(arr[i]<=pivot && i<=e)
            i++;
        while(arr[j]>pivot && j>=s)
            j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[s]);
    return j;
}

void median(int*arr,int s,int e,int k){
    if(s>e){
        return ;
    }
    else{
        int p=partition(arr,s,e);
        if(p==k){
            cout<<"Median is "<<arr[p]<<endl;
            return;
        }
        else if(p<k){
            median(arr,p+1,e,k);
        }
        else{
            median(arr,s,p-1,k);
        }
    }

}
int main(){
    cout<<"enter the no. of elements in array ";
    int n;
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    median(arr,0,n-1,n/2);
    return 0;
}
