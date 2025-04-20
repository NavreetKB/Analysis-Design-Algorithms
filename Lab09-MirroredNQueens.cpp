#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


bool place(int k, int i,vector<int> x){
    for(int j=0;j<k;j++){
        if(i==x[j] || abs(j-k)==abs(i-x[j])){
            return false;
        }
    }
    return true;

}
vector<int> mirrored(vector<int> x,int n){
    vector<int> mirror(n,-1);
    for(int i=0;i<n;i++){
        mirror[i]=n-x[i]-1;
    }
    return mirror;
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

void nqueensEven(int k ,int n, vector<int> & x){
    int limit;
    if(k==0){
      limit=n/2;
    }
    else limit=n;
 
    for(int i=0;i<limit;i++){
        if(place(k,i,x)){
            x[k]=i;
            
            if(k==n-1){
                print(x,n);
                print(mirrored(x,n),n);
            }
            else{
                nqueensEven(k+1,n,x);
            }
        }
    }
}

void nqueensOdd(int k ,int n, vector<int> & x){
    int limit;
    if(k==0){
      limit=n/2+1;
    }
    else limit=n;
 
    for(int i=0;i<limit;i++){
        if(place(k,i,x)){
            x[k]=i;
            
            if(k==n-1){
                print(x,n);
                if(i!=limit-1){
                    print(mirrored(x,n),n);
                }
                
            }
            else{
                nqueensOdd(k+1,n,x);
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
    if(n%2==0){
        nqueensEven(0,n,x);
    }
    else{
        nqueensOdd(0,n,x);
    }
    return 0;
}


