#include<iostream>
#include<string>

using namespace std;
struct subArray{
    int max;
    int min;
};
typedef struct subArray subArray;


subArray* maxmin(int l,int h,int *arr){
    subArray* left=new subArray;
    subArray* right=new subArray; 
    subArray* result=new subArray;
    if(l==h){
        result->max=arr[l];
        result->min=arr[l];
        return result;
    }
    else{
        int mid=(l+h)/2;
        left= maxmin(l,mid,arr);
        right= maxmin(mid+1,h,arr);
     
        if(left->max>=right->max){
            result->max=left->max;
        }
        else{
            result->max=right->max;
        } 
        if(left->min<=right->min){
            result->min=left->min;
        }
        else{
            result->min=right->min;
        }
        return result;
    }
    
}

int main(){
    cout<<"enter no. of elements in array ";
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subArray* answer=new subArray;
    answer=maxmin(0,n-1,arr);
    cout<<"maxmum element "<<answer->max<<endl;
    cout<<"minimum element "<<answer->min<<endl;

    return 0;
}
