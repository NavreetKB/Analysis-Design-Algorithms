#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> x;
int m;

void print(vector<int>x,vector<int> set){
    for(int i=0;i<x.size();i++){
       if(x[i]==1){
        cout<<set[i]<<" ";
       }
    }
    cout<<endl;
}

void sumSubsets(int s,int k,int r,vector<int> set){
    if(k>=set.size()) return;
    
    x[k]=1;
    if(s+set[k] == m){
        print(x,set);
    }
    else if (s+set[k]+set[k+1] <= m){
        sumSubsets(s+set[k],k+1,r-set[k],set);
    }
    x[k]=0;
    if(s+r-set[k] >=m  && (s+set[k+1]<=m)){
        
        sumSubsets(s,k+1,r-set[k],set);
    }
}

int main(){
    cout<<"enter size of set : ";
    int n;
    cin>>n;
    x=vector<int>(n,0);
    vector<int> set(n,0);
    cout<<"enter elements of the set : \n";
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
    sort(set.begin(),set.end());
    cout<<"enter the value of sum : ";
 
    cin>>m;
    int r=0;
    for(int i=0;i<n;i++){
        r+= set[i];
    }
    sumSubsets(0,0,r,set);

    return 0;
}
