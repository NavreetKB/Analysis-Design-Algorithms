#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> s,int i,int j){
    if(i==j){
        cout<<"A"<<i<<" ";
        return;
    }
    else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }

}

void MCM(vector<int> p){
    int n=p.size()-1;
    vector<vector<int>> m(n+1,vector<int>(n+1,-1));
    vector<vector<int>> s(n+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT16_MAX;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    
    print(s,1,n);
}




int main(){
    cout<<"enter no. of matrices : ";
    int n;
    cin>>n;
    vector<int> p(n+1,0);
    cout<<"enter the chain : ";
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }

    MCM(p);

    return 0;
}

/*
enter no. of matrices : 4
enter the chain : 10 15 20 5 10
((A1 (A2 A3 ))A4 )
*/

/* plot
import matplotlib.pyplot as plt
import numpy as np

sizes = np.array([4, 54, 104, 154, 204, 254, 304, 354, 404, 454, 504, 554, 604, 654, 704, 754, 804, 854, 904])
times = np.array([10, 625, 4302, 12171, 28972, 65937, 93932, 150674, 219795, 315260, 438216, 597410, 960658, 1.10111e+06, 1.30254e+06, 1.84554e+06, 2.31677e+06, 2.78512e+06, 3.29526e+06]) 
scaled_theory =(sizes**3)*(times[5]/sizes[5]**3)

plt.figure(figsize=(8, 6))

plt.plot(sizes, times, marker='o', linestyle='-', color='b', label="Measured Time ")

plt.plot(sizes, scaled_theory, marker='s', linestyle='--', color='r', label=" O(n^3)")

plt.xlabel('Number of matrices (n)')
plt.ylabel('Time (Microseconds)')
plt.title("Time Complexity of Matrix chain multiplication (O(n^3))")
plt.legend()
plt.grid(True)


plt.show()


*/
