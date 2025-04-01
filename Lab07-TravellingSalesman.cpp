#include<iostream>
#include<vector>

using namespace std;

int travel(vector<vector<int>> cost,int source, vector<int> set,int &sum){
    if(set.empty()){
        return cost[source][0];
    }

    int len=set.size();
    int min=INT16_MAX;
    int pathlen=0;
    int node=-1;
    for(int i=0;i<len;i++){
        vector<int> newset=set;
        newset.erase(newset.begin()+i);
        pathlen= cost[source][set[i]]+travel(cost,set[i],newset,sum);
        if(pathlen<min){
            min=pathlen;
            node=i;
        }
        
    }
    
    return min;

}


int main(){
    int n,e;
    cout<<"enter no. of vertices : ";
    cin>>n;
    cout<<"enter no. of edges : ";
    cin>>e;
    vector<vector<int>> cost(n,vector<int>(n,INT16_MAX));
    vector<int> set(n,-1);
    for(int i=0;i<n;i++){
        cost[i][i]=0;
        set[i]=i;
    }
    int v1,v2,wt;
    for(int i=0;i<e;i++){
        // cout<<"enter source, destination and weight : ";

        cin>>v1>>v2>>wt;
        cost[v1][v2]=wt;
    }
    int sum=0;
    cout<<"minimum distance to travel all nodes and return back : ";
    int ans=travel(cost,0,set,sum);
    cout<<ans;
    return 0;

}
