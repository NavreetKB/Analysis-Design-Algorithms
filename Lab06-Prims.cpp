#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<climits>

using namespace std;

pair<int,int> minEdge(vector<vector<int>> edge,int e){
    pair<int,int> p={-1,-1};
    int minWeight=INT16_MAX;
    for (int i=0; i< e; i++) {
        if (edge[i][2]<minWeight) {
            minWeight=edge[i][2];
            p.first=edge[i][0];
            p.second=edge[i][1];
        }
    }
    
    return p;
}

void Prims(vector<vector<int>> edge,vector<vector<int>> cost , int e, int n){
    vector<vector<int>> tree(n-1,vector<int>(2,0));
    
   
    int k=-1;
    int l=-1;
    int min_cost_start =INT16_MAX;
    for (int i=0;i<n; i++) {
        for (int j=i+1;j < n; j++) {
            if (cost[i][j]<min_cost_start) {
                min_cost_start = cost[i][j];
                k=i;
                l=j;
            }
        }
    }

    vector<int> near(n);
    int minwt=0;
    
    for(int i=0;i<n;i++){
        if(cost[i][k]<=cost[i][l]){
           near[i]=k;
        }
        else
           near[i]=l;
    }

    near[k]=-1;
    near[l]=-1;
    tree[0][0]=k;
    tree[0][1]=l;
    minwt+=cost[k][l];
    
    for(int j=1;j<n;j++){
        int min=INT16_MAX;
        int u=-1;
        for(int p=0;p<n;p++){
            
               if(near[p]!=-1 && cost[p][near[p]]<min){
                   min=cost[p][near[p]];
                   u=p;
               }
            
        }
       
        if(u!=-1){
            cout<<"adding "<<u<<"  "<<near[u]<<endl;
            tree[j][0]=u;
            tree[j][1]=near[u];
            minwt+=cost[u][near[u]];
            near[u]=-1;
        }
        
        for(int w=0;w<n;w++){
            if(near[w]!=-1){
                if(cost[w][near[w]]>cost[w][u] ){
                    near[w]=u;
                }
            }
        }
       
    }
    
    cout<<"Minimum spanning tree : \n";
    for(int t=0;t<n-1;t++){
        cout<<"---------"<<endl;
        cout<<"| "<<tree[t][0]<<" | "<<tree[t][1]<<" |"<<endl;
    }
    cout<<"Minimum weight : "<<minwt<<endl;

}





int main(){

    int n,e;
    cout<<"enter no. of vertices : ";
    cin>>n;
    cout<<"enter no. of edges : ";
    cin>>e;

    // r*c 2d matrix initialised with 0 : vector<vector<int>> vec(r, vector<int> (c, 0));
    vector<vector<int>> cost(n,vector<int>(n,INT16_MAX));
    vector<vector<int>> edges(e,vector<int>(3,0));
    for(int i=0;i<n;i++){
        cost[i][i]=0;
    }
    int v1,v2,wt;
    for(int i=0;i<e;i++){
        cout<<"enter source, destination and weight : ";
        cin>>v1>>v2>>wt;
        cost[v1][v2]=wt;
        cost[v2][v1]=wt;
        edges[i][0]=v1;
        edges[i][1]=v2;
        edges[i][2]=wt;
    }
    
    cout<<"Adjacency matrix : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( cost[i][j] == INT16_MAX){
                cout<<setw(4)<<"";
            }
            cout<<setw(4)<<cost[i][j];
        }
        cout<<endl;
    }
    Prims(edges,cost,e,n);


    return 0;

}
