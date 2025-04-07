#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;



vector<pair<int,int>> mergePurge(vector<pair<int,int>>  V,int C){

    
    vector<pair<int,int>> filter;
    for(int i=0;i<V.size();i++){
        bool dominates=false;
        if(V[i].second>C){
            continue;
        }
        for(int j=0;j<V.size();j++){
            if(V[i].first<=V[j].first && V[i].second>V[j].second){
                dominates=true;
            }
        }
        if(!dominates){
            filter.push_back(V[i]);
        }

    }
    return filter;
}

vector<int> traceBack(int p, int  w,int n,vector<vector<pair<int,int>>> S,vector<int> profit,vector<int> wts){
    vector<int> result(n,0);
    for(int i=n-1;i>=0;i--){
        pair<int,int> pr={p,w};
        if(std::find(S[i].begin(),S[i].end(),pr)==S[i].end()){
            result[i]=1;
            p-=profit[i];
            w-=wts[i];
        }
        else{
            result[i]=0;
        }
    }
    return result;
}


void knapsack(vector<int> p,vector<int> w,int n,int C){
    vector<vector<pair<int,int>>> S(n+1);
    vector<vector<pair<int,int>>> S_1(n+1);
    S[0].push_back({0,0});
    for(int i=1;i<=n;i++){
        for(int j=0;j<S[i-1].size();j++){
            int new_p= S[i-1][j].first+ p[i-1];
            int new_w= S[i-1][j].second+w[i-1];
            S_1[i-1].push_back({new_p,new_w});
            
        }
        int l1=S[i-1].size();
        int l2=S_1[i-1].size();

        for(int k=0;k<l1;k++){
            S[i].push_back(S[i-1][k]);
        }
        for(int k=0;k<l2;k++){
            S[i].push_back(S_1[i-1][k]);
        }
        S[i]= mergePurge(S[i],C);
    
    } 
    cout<<"S"<<n<<endl;
    int pro=0,wt=0;

    for(auto i : S[n]){
        cout<<i.first<<"  "<<i.second<<"\n";
        if(i.first>pro){
            pro=i.first;
            wt=i.second;
        }
    }
   
    vector<int> ans=traceBack(pro,wt,n,S,p,w);
    for(int l=0;l<n;l++){
        cout<<ans[l]<<"  ";
    }

    
}


int main(){
    cout<<"enter no. of items : ";
    int n,C;
    cin>>n;
    cout<<"enter the capacity of knapsack : ";
    cin>>C;
    vector<int> p(n,0);
    vector<int> w(n,0);
    for(int i=0;i<n;i++){
        cout<<"enter profit and weight for P"<<i<<" : ";
        cin>>p[i]>>w[i];
    }
    for(int i=0;i<n;i++){
        
        cout<<p[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<w[i]<<"  ";
    }
    cout<<endl;

    knapsack(p,w,n,C);
    
    return 0;
}
