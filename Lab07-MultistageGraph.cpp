#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int countStages(vector<vector<int>> cost,int n){
    int i=0;
    int p=0;
    int cnt=1;
    while (i!=n-1)
    {
        cnt++;
        for(int j=0;j<n;j++){
            if(cost[i][j]!=0 && cost[i][j]!=INT16_MAX){
                p=j;
                break;
            }
        }
        i=p;
    }
    return cnt;
}

void Multistage(vector<vector<int>> edges,vector<vector<int>> cost,int n,int k){
    vector<int> fdist(n,INT16_MAX);
    fdist[n-1]=0;
    vector<int> path(n,-1);
    for(int j=n-2;j>=0;j--){
        int r=-1,minr=-1;
        int len=INT16_MAX;
        
        for (int p =j+1;p<n;p++) {  
            if (cost[j][p]!=0 &&cost[j][p]!= INT16_MAX) {
                int new_cost=cost[j][p] + fdist[p];
                if (new_cost<fdist[j]) {
                    fdist[j]=new_cost;
                    minr = p;
                }
            }
        }
        cout<<"chosen edge : "<<j<<" "<<minr<<endl;
       
        path[j]=minr;

    }
    
    vector<int> P;
    int current = 0;
    while (current != -1) {
        P.push_back(current);
        current = path[current];
    }
    
   
    cout << "The shortest path from 0 to "<<n-1<<" is: ";
    for (int i=0;i<k; i++) {
        cout<<P[i];
        if (i!= P.size()-1) cout << " ---> ";
    }
    cout << "\nTotal cost: " << fdist[0] << endl;
}


int main(){
    int n,e;
    cout<<"enter no. of vertices : ";
    cin>>n;
    cout<<"enter no. of edges : ";
    cin>>e;
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
        edges[i][0]=v1;
        edges[i][1]=v2;
        edges[i][2]=wt;
    }
    int k=countStages(cost,n);
    cout<<"No. of stages : "<<k<<endl;
    
    Multistage(edges,cost,n,k);
    return 0;


}
