#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

bool place(int k, int i,vector<int> x){
    for(int j=0;j<k;j++){
        if(i==x[j] || abs(j-k)==abs(i-x[j])){
            return false;
        }
    }
    return true;

}


void print(vector<int> x,int n){
    for(int i=0;i<n;i++){
        int pos=x[i];
        for(int j=0;j<n;j++){
            if(j==pos){
                cout<<setw(5)<<"Q";
            }
            else{
                cout<<setw(5)<<".";
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void nqueens(int k, int n,vector<int> &x){
    
    for(int i=0;i<n;i++){
        if(place(k,i,x)){
            x[k]=i;
            if(k==n-1){
                print(x,n);
            }
            else{
                nqueens(k+1,n,x);
            }
        }
    }
   
}

int main(){
    cout<<"enter no. of queens : ";
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Invalid ! ";
        return 0;
    }
    vector<int> x(n,-1);
    nqueens(0,n,x);
    return 0;
}
