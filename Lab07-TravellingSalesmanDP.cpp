#include<iostream>
#include<vector>
#include<chrono>
#include<ctime>
#include<random>
#include<climits>

using namespace std;
using namespace std::chrono;

int travel(vector<vector<int>> cost,int n)
{
    vector<vector<int>> dp(1<<n ,vector<int>(n,INT_MAX));
    dp[1][0]=0;

    for(int mask=0;mask< (1<<n);mask++){     //subset
        for(int u=0;u<n;u++){                //all visited nodes
            if((mask & (1<<u)) == 0)
                continue;
            
            for(int v=0;v<n;v++){           // all remaining nodes
                if((mask & (1<<v))== 0){
                    int newmask=(mask | (1<<v));
                    if(cost[u][v]!=INT_MAX && dp[mask][u]!=INT_MAX){
                        dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+cost[u][v]);
                    }
                }
            }
        }
    }
    vector<int> path;
    int mincost=INT_MAX;
    for(int i=1;i<n;i++){
        if(cost[i][0]!=INT_MAX && dp[(1<<n)-1][i]!=INT_MAX){
            mincost=min(mincost,dp[(1<<n)-1][i]+cost[i][0]);
            path.push_back(i);
        }
    }
    // cout<<0<<" --> ";
    // for(int i=0;i<n-1;i++){
    //     cout<<path[i]<<" --> ";
    // }
    // cout<<0<<endl;
    return mincost;
}

void initialise(vector<vector<int>> &cost,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j]=rand()%20+1;
        }
    }
}

int main(){
    // cout<<"enter no. of vertices : ";
    // int n;
    // cin>>n;
    // cout<<"enter no. of edges : ";
    // int e;
    // cin>>e;
    int *sizes=new int[7];
    float *times=new float[7];
    int n=5;
    for(int p=0;p<7;p++){
    sizes[p]=n;
    
    vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
    initialise(cost,n);
    for(int i=0;i<n;i++){
        cost[i][i]=0;
    }
    // int v1,v2,wt=0;
    // for(int i=0;i<e;i++){
    //     cout<<"enter source, destination and weight : ";
    //     cin>>v1>>v2>>wt;
    //     cost[v1][v2]=wt;
    //     cost[v2][v1]=wt;
    // }
    auto start=high_resolution_clock::now();
    int ans=travel(cost,n);
    auto end=high_resolution_clock::now();

    double timetaken=duration<double,micro>(end-start).count();
    times[p]=timetaken;
    //cout<<"Minimum path length : "<<ans;
     n=n+5;
    }
    
    for(int i=0;i<7;i++){
        cout<<sizes[i]<<", ";
    }
    for(int i=0;i<7;i++){
        cout<<times[i]<<", ";
    }
    return 0;
}



/*
#include<iostream>
#include<vector>
#include<chrono>
#include<ctime>
#include<random>

using namespace std;
using namespace std::chrono;

int travel(vector<vector<int>> cost,int n)
{
    vector<vector<int>> dp(1<<n ,vector<int>(n,INT_MAX));
    dp[1][0]=0;

    for(int mask=0;mask< (1<<n);mask++){     //subset
        for(int u=0;u<n;u++){                //all visited nodes
            if((mask & (1<<u)) == 0)
                continue;
            
            for(int v=0;v<n;v++){           // all remaining nodes
                if((mask & (1<<v))== 0){
                    int newmask=(mask | (1<<v));
                    if(cost[u][v]!=INT_MAX && dp[mask][u]!=INT_MAX){
                        dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+cost[u][v]);
                    }
                }
            }
        }
    }
    vector<int> path;
    int mincost=INT_MAX;
    for(int i=1;i<n;i++){
        if(cost[i][0]!=INT_MAX && dp[(1<<n)-1][i]!=INT_MAX){
            mincost=min(mincost,dp[(1<<n)-1][i]+cost[i][0]);
            path.push_back(i);
        }
    }
    cout<<0<<" --> ";
    for(int i=0;i<n-1;i++){
        cout<<path[i]<<" --> ";
    }
    cout<<0<<endl;
    return mincost;
}

void initialise(vector<vector<int>> &cost,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j]=rand%20+1;
        }
    }
}

int main(){
    cout<<"enter no. of vertices : ";
    int n;
    cin>>n;
    cout<<"enter no. of edges : ";
    int e;
    cin>>e;

    vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        cost[i][i]=0;
    }
    int v1,v2,wt=0;
    for(int i=0;i<e;i++){
        cout<<"enter source, destination and weight : ";
        cin>>v1>>v2>>wt;
        cost[v1][v2]=wt;
        cost[v2][v1]=wt;
    }

    int ans=travel(cost,n);
    cout<<"Minimum path length : "<<ans;
    return 0;
}
*/
