#include<iostream>
#include<vector>

using namespace std;

vector<int> x;
int cnt=0;

void nextValue(int k,vector<vector<int>> adj,int n){
    while(true){
        x[k]=(x[k]+1)%(n);
        if(x[k]==0) return;
        int i;
        if( adj[x[k-1]][x[k]]!=0){
            for( i=0;i<k;i++){
                if(x[i]==x[k]){
                    break;
                }
            }
            if(i==k){
                if((k==n-1 && adj[x[k]][x[0]]!=0)||(k<n-1)){
                    return;
                }
            }
        }
    }
}

void print(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<"  ";
    }
    cout<<x[0]<<" ";
    cout<<endl;
}
void hamiltonian(int k,vector<vector<int>> adj,int n){
    while(true){
        nextValue(k,adj,n);
        if(x[k]==0){
            return;
        }
        if(k==n-1){
            print(x);
            cnt++;
            return;
        }

        else{
            hamiltonian(k+1,adj,n);
        }
    }       
}

int main(){
    
    cout<<"enter no. of vertices : ";
    int n,e;
    cin>>n;
    cout<<"enter no. of edges : ";
    cin>>e;
    x=vector<int>(n,0);
    int v1,v2;
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
        cout<<"enter source and destination : ";
        cin>>v1>>v2;
        adj[v1][v2]=1;
        adj[v2][v1]=1;
    }
    x[0]=0;
    hamiltonian(1,adj,n);
    if(cnt==0){
        cout<<" Hamiltonian cycle does not exist ";

    }
    return 0;

}
/*
enter no. of vertices : 4
enter no. of edges : 6
enter source and destination : 0 1
enter source and destination : 1 2
enter source and destination : 2 3 
enter source and destination : 3 0
enter source and destination : 0 2
enter source and destination : 1 3
0  1  2  3  0 
0  2  1  3  0 
0  3  1  2  0 
*/


