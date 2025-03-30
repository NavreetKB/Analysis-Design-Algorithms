#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;


void knapsack01(vector<int> profit,vector<int> wts,int capacity, int n ){
    vector<vector<int>> table(n+1,vector<int>(capacity+1,0));
    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            if(i==0 || w==0){
                table[i][w]=0;
            }
            else if(wts[i-1]<=w){
                table[i][w]=max(profit[i-1]+table[i-1][w-wts[i-1]],table[i-1][w]);
            }
            else{
                table[i][w]=table[i-1][w];
            }
        }
        
    }
    cout<<"Result: \n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            cout<<table[i][j]<<"   ";
        }
        cout<<endl;
    }
    vector<int> selectedItems;
    int w=capacity;
    for (int i=n;i>0; i--) {
        if(w==0){
            break;
        }
        if (table[i][w]!=table[i-1][w]) { 
            selectedItems.push_back(i);
            w-= wts[i-1]; 
        }
    }
    cout<<"Selected items for maximum profit: ";
    reverse(selectedItems.begin(), selectedItems.end()); 
    for(int i=0;i<selectedItems.size();i++) {
        cout<<"P"<<(selectedItems[i]-1)<<" ";
    }
    cout << endl;
    cout<<"Maximum Profit : "<<table[n][capacity];
        
}

int main(){
    int n,p,w;
    cout<<"enter no. of items : ";
    cin>>n;
    cout<<"enter capacity : ";
    int capacity;
    cin>>capacity;
    vector<int> profit(n,0);
    vector<int> wts(n,0);
    for(int i=0;i<n;i++){
        cout<<"enter profit and weight for P"<<i<<" : ";
        cin>>p>>w;
        profit[i]=p;
        wts[i]=w;
    }
    cout<<"Original Table :\n";
    for(int i=0;i<n+1;i++){
        cout<<"-------+";
    }cout<<endl;
    
    for(int i=0;i<2;i++){
        if(i==0){
            cout<<setw(8)<<"PROFIT |";
            for(int j=0;j<n;j++){
                cout<<setw(4)<<profit[j]<<setw(4)<<"|";
            }
        }  
        if(i==1){
            cout<<setw(8)<<"WEIGHT |";
            for(int j=0;j<n;j++){
                cout<<setw(4)<<wts[j]<<setw(4)<<"|";
            }
        }
        
        cout<<endl;
        for(int k=0;k<n+1;k++){
            cout<<"-------+";
        }
        cout<<endl;
    }
    knapsack01(profit,wts,capacity,n);

    return 0;


}
