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
    vector<int> bdist(n,INT16_MAX);
    bdist[0]=0;
    vector<int> path(n,-1);
    for(int j=1;j<n;j++){
        int r=-1,minr=-1;
        int len=INT16_MAX;
        
        for (int p =0;p<n;p++) {  
            if (cost[p][j]!=0 &&cost[p][j]!= INT16_MAX) {
                int new_cost=cost[p][j] + bdist[p];
                if (new_cost<bdist[j]) {
                    bdist[j]=new_cost;
                    minr = p;
                }
            }
        }
        cout<<"chosen edge : "<<j<<" "<<minr<<endl;
       
        path[j]=minr;

    }
    
    vector<int> P(k);
    P[k-1] = n-1;
    int current =n-1;
    for (int i=k-2; i >=0; i--) {
        P[i] =path[current];
        current =path[current];
    }

    cout<<"The shortest path from 0 to "<<n-1<<" is: ";
    for (int i=0;i<k;i++) {
        cout<<P[i];
        if (i != P.size() - 1) cout << " ---> ";
    }
    cout << "\nTotal cost: " << bdist[n - 1] << endl;
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
