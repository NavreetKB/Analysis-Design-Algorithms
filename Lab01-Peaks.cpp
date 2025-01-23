#include<iostream>
#include<string>
using namespace std;

int findPeak1D(int arr[],int n){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    while (s<=e)
    {
       if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
       {
         return mid;
       }
       else if(arr[mid]<arr[mid-1]){
        e=mid-1;
       }
       else if(arr[mid]<arr[mid+1]){
        s=mid+1;
       }
       mid=(s+e)/2;
    }
    return -1;
    
}

void findPeak2D(int arr[][4],int r,int c){
    int i=r/2-1;
    int j=c/2-1;
    int peak=arr[i][j];
    cout<<"starting at "<<i<<" "<<j<<" "<<peak<<endl;
    int counter=0;
    while(counter<16)
    {
        if(peak>=arr[i-1][j] && peak>=arr[i+1][j] && peak>=arr[i][j-1] && peak>=arr[i][j+1]){
        cout<<"Peak element is "<<peak<<endl;
        break;
        }
        else if(peak<arr[i][j-1]){
            peak=arr[i][j-1];
            counter++;
        }
        else if(peak<arr[i][j+1]){
            peak=arr[i][j+1];
            counter++;
        }
        else if(peak<arr[i-1][j]){
            peak=arr[i-1][j];
            counter++;
        }
        else if(peak<arr[i+1][j]){
            peak=arr[i+1][j];
            counter++;
        }
    }
    cout<<"counted "<<counter<<" times";

}

void columnDiv(int arr[][4],int r,int start, int end){
    if(start<0 || start>3 || end<0 || end>3){
        return;
    }
    int j=(start+end)/2;
    int max_r=0;
    int max=arr[max_r][j];
    for(int i=0;i<r;i++){
       if(arr[i][j]>max){
        
        max=arr[i][j];
        max_r=i;
       }
    }
    
    cout<<endl<<"maximum element "<<arr[max_r][j]<<endl;
    int peak=arr[max_r][j];
    
    if(max_r==0){
        
        if((j == 0 || arr[max_r][j] >= arr[max_r][j-1]) &&
    (j == 3 || arr[max_r][j] >= arr[max_r][j+1]))
        {
            cout<<"Peak element is "<<peak<<endl;
            return;
        }
        else if((j == 0 || arr[max_r][j]< arr[max_r][j-1])) {
            columnDiv(arr,4,start,j-1);
        }
        else if((j == 3 || arr[max_r][j]< arr[max_r][j+1])){
            columnDiv(arr,4,j+1,end);
        }
    }
    else if (max_r==r-1) {
        
        if ((j==0 || arr[max_r][j] >= arr[max_r][j - 1]) && (j==3 || arr[max_r][j] >= arr[max_r][j + 1])) {
            cout << "Peak element is " << peak << endl;
            return;
        }
        else if((j==0 || arr[max_r][j]<arr[max_r][j - 1])){
            columnDiv(arr,r,start,j-1);
        }
        else if((j==3 || arr[max_r][j]<arr[max_r][j + 1])){
            columnDiv(arr,r,j+1,end);
        }

    }
    else {
        
        if (arr[max_r][j] >=arr[max_r][j-1] && arr[max_r][j]>=arr[max_r][j+1] ){
            
            cout<<"Peak element is " <<arr[max_r][j]<< endl;
            return;
        }
   

    if (j>0 && arr[max_r][j]<arr[max_r][j-1]) {
        columnDiv(arr,r, start, j-1);
    } else if (j<3 && arr[max_r][j]<arr[max_r][j + 1]) {
        columnDiv(arr,r,j+1, end);
    } 
    }
}


int main(){
    int arr[] = {1,2,6,3,8,9,4};
    int ans=findPeak1D(arr,7);
    cout<<"Peak at "<<ans<<endl;

    int arr2[4][4]={
    {1,  2,  3,  100},
    {4,  5,  6,  7},
    {8,  9,  10, 11},
    {12, 13, 14, 15}   
};
    int n=4,m=4;
    cout<<"finding peak in 2D array"<<endl;
    cout<<"by method 1"<<endl;
    findPeak2D(arr2,n,m);
    cout<<"by method 2"<<endl;
    columnDiv(arr2,4,0,3);
    return 0;
}