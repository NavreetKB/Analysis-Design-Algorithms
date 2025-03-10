#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
#include<vector>

using namespace std;

void initialise(vector<vector<int>> &adj,int i,int j,int w){
    adj[i][j]=w;
}


int main(){
    cout<<"enter no. of vertices ";
    int n;
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n,INT16_MAX));
    for(int i=0;i<n;i++){
        adj[i][i]=0;
        
    }

    cout<<"enter no. of edges ";
    int e;
    cin>>e;
    
    int src=0,wt=0,dest=0;
    for(int i=0;i<e;i++){
        cout<<"enter source :";
        cin>>src;
        cout<<"enter destination :";
        cin>>dest;
        cout<<"enter edge weight :";
        cin>>wt;
        initialise(adj,src,dest,wt);
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"edge "<<i<<" to "<<j<<" : "<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    vector<bool> visited(n);
    vector<int> dist(n,INT16_MAX);
    vector<int> path(n);
    

    for(int i=1;i<n;i++){
        dist[i]=adj[0][i];
        visited[i]=false;
    }

    visited[0]=true;
    dist[0]=0;
    path[0]=0;
    
    
    for(int i=0;i<n-1;i++){
        int min_ind=-1;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
        if(!visited[i] && dist[i]<min){
            
                min_ind=i;
                min=dist[i];
            
        }
    }
   

    visited[min_ind]=true;
    

    for(int i=0;i<n;i++){
        if(adj[min_ind][i]!=INT16_MAX){
            if(dist[i]> dist[min_ind]+adj[min_ind][i]){
                dist[i]=dist[min_ind]+adj[min_ind][i];
                path[i]=min_ind;
        }
        }  
    }
    }
    cout<<"minimum distance (0th to nth node): "<<dist[n-1]<<endl;
    int i=n-1;
    cout<<"path from 0 to "<<n-1<<"th node :\n";
    cout<<n-1<<" <-- ";
    while(path[i]!=0){
        cout<<path[i]<<" <-- ";
        i=path[i];
    } cout<<0<<endl;
    

    return 0;
}
