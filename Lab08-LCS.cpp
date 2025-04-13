#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<ctime>
#include<random>

using namespace std;
using namespace std::chrono;

void printLCS(vector<vector<char>> b,string x,int i,int j){
    if (i==0 || j==0){
        return;
    }
    if( b[i][j]=='\\'){
        printLCS(b,x,i-1,j-1);
        cout<<x[i-1];
    }
    else if (b[i][j]=='|'){
        printLCS(b,x,i-1,j);
    }
    else{
        printLCS(b,x,i,j-1);
    }
}

int LCS(string x,string y){
    int m=x.length();
    int n=y.length();
    
    vector<vector<int>> c(m+1,vector<int>(n+1,0));
    vector<vector<char>> b(m+1,vector<char>(n+1,0));
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    int i=0,j=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=1+c[i-1][j-1];
                b[i][j]='\\';         //dont use ""
            }
            else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='-';
            }
        }
    }
    i--;j--;     //careful here
    cout<<"LCS: \n";
    printLCS(b,x,i,j);
    return c[m][n];
}


int main()
{
    // cout<<"enter string X : ";
    // string x,y;
    // cin>>x;
    // cout<<"enter string y : ";
    // cin>>y;
    // int len= LCS(x,y);
    // cout<<"\nlength of LCS : "<<len;
    int len;
    int *sizes=new int[10];
    float *times=new float[10];
    int n=10;
    for(int i=0;i<10;i++){
        string x,y;
        for(int j=0;j<n;j++){
            x.push_back('A' + rand() % 26);
            y.push_back('A' + rand() % 26);
        }
        auto start=high_resolution_clock::now();
        len=LCS(x,y);
        auto end=high_resolution_clock::now();
        long timetaken=duration<double,micro>(end-start).count();
        times[i]=timetaken;
        n*=2;
    }

    for(int i=0;i<10;i++){
        cout<<sizes[i]<<", ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<times[i]<<", ";
    }
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<string>


using namespace std;

void printLCS(vector<vector<char>> b,string x,int i,int j){
    if (i==0 || j==0){
        return;
    }
    if( b[i][j]=='\\'){
        printLCS(b,x,i-1,j-1);
        cout<<x[i-1];
    }
    else if (b[i][j]=='|'){
        printLCS(b,x,i-1,j);
    }
    else{
        printLCS(b,x,i,j-1);
    }
}

int LCS(string x,string y){
    int m=x.length();
    int n=y.length();
    
    vector<vector<int>> c(m+1,vector<int>(n+1,0));
    vector<vector<char>> b(m+1,vector<char>(n+1,0));
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    int i=0,j=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=1+c[i-1][j-1];
                b[i][j]='\\';         //dont use ""
            }
            else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='-';
            }
        }
    }
    i--;j--;     //careful here
    cout<<"LCS: \n";
    printLCS(b,x,i,j);
    return c[m][n];
}


int main()
{
    cout<<"enter string X : ";
    string x,y;
    cin>>x;
    cout<<"enter string y : ";
    cin>>y;
    int len= LCS(x,y);
    cout<<"\nlength of LCS : "<<len;
    return 0;
}
*/

