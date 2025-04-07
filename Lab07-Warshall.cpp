#include<iostream>
#include<vector>
#include<iomanip>
#include<ctime>
#include<chrono>
#include<random>

using namespace std;
using namespace std::chrono;


void Warshall(vector<vector<int>> cost,int n){
    vector<vector<int>> A=cost;
    
   for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][k]!=INT16_MAX && A[k][j]!=INT16_MAX && A[i][j]> A[i][k]+A[k][j]){
                A[i][j]=A[i][k]+A[k][j];
            }
        }
    }
   }

//    cout<<"Shortest paths matrix "<<endl;
//    for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         if(A[i][j]==INT16_MAX){
//             cout<<setw(4)<<"INF";
//         }
//         else{
//             cout<<setw(4)<<A[i][j];
//         }
        
//     }
//     cout<<endl;
//    }

}

void initialise(vector<vector<int>> &mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                mat[i][j]=0;
            }
            else
            mat[i][j]=rand()%10+1;
        }
    }

}



int main(){
    int n=4,e;
    // cout<<"enter no. of vertices : ";
    // cin>>n;
    // cout<<"enter no. of edges : ";
    // cin>>e;
    // vector<vector<int>> cost(n,vector<int>(n,INT16_MAX));
    // for(int i=0;i<n;i++){
    //     cost[i][i]=0;
    // }
    // int v1,v2,wt;
    // for(int i=0;i<e;i++){
    //     cout<<"enter source, destination and weight : ";
    //     cin>>v1>>v2>>wt;
    //     cost[v1][v2]=wt;
    // }

    int*sizes=new int[7];
    float* times=new float[7];
    for(int i=0;i<7;i++){
        vector<vector<int>> cost(n, vector<int>(n, INT16_MAX)); 
        initialise(cost, n);

        cout<<"running for "<<n<<endl;
        sizes[i]=n;
        

        auto start=high_resolution_clock::now();
        Warshall(cost,n);
        auto end=high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        n+=2;
        times[i]=duration;

    }

    for(int i=0;i<7;i++){
        cout<<sizes[i]<<",";
    }
    cout<<endl;
    for(int i=0;i<7;i++){
        cout<<times[i]<<",";
    }
   return 0;

}

