#include<iostream>
#include<vector>


using namespace std;

vector<int> x;
int cnt=0;

void print(vector<vector<int>> adj, int n, int m,int k){
    for(int i=0;i<n;i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}

void nextvalue(vector<vector<int>> adj, int n, int m,int k){
    
    int j;
    while(true){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0){
            return;
        }
        for(j=0;j<n;j++){
            if(adj[j][k]!=0 && x[j]==x[k]){
                break;
            }

        }
        if(j==n){
            return;
        }
        
    }
}

void mColor(vector<vector<int>> adj, int n, int m,int k){
    while(true){
        nextvalue(adj,n,m,k);
        if(x[k]==0){
            return;
        }
        if(k==n-1){
            cnt++;
            print(adj,n,m,k);

        }
        else{
            mColor(adj,n,m,k+1);
        }
        }
    
}


int main(){
    cout<<"enter the number of nodes : ";
    int n, e,m;
    cin>>n;
    cout<<"enter no. of edges : ";
    cin>>e;
    int v1,v2;
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
        cout<<"enter endpoints : ";
        cin>>v1>>v2;
        adj[v1][v2]=1;
        adj[v2][v1]=1;
    }
    x = vector<int>(n,0);
    cout<<"enter no. of colors : ";
    cin>>m;

    mColor(adj,n,m,0);
    if(cnt==0){
        cout<<"No. solution possible ";
    }
    return 0;
}

/*
enter the number of nodes : 6
enter no. of edges : 8
enter endpoints : 0 1
enter endpoints : 0 2
enter endpoints : 1 2 
enter endpoints : 1 3
enter endpoints : 2 4
enter endpoints : 3 4
enter endpoints : 1 4 
enter endpoints : 4 5
enter no. of colors : 3
1  2  3  3  1  2  
1  2  3  3  1  3  
1  3  2  2  1  2  
1  3  2  2  1  3  
2  1  3  3  2  1
2  1  3  3  2  3
2  3  1  1  2  1  
2  3  1  1  2  3
3  1  2  2  3  1
3  1  2  2  3  2
3  2  1  1  3  1
3  2  1  1  3  2
*/

/*
import matplotlib.pyplot as plt
import networkx as nx

edges = [(0, 1), (1, 2), (2, 3), (3, 0),  (1, 4), (2, 5), (3, 4),  (4, 7), (5, 6), (6, 7)]
colors_assigned=[3 , 1 , 3 , 2 , 3 , 2 , 3 , 2] 
color_map = {
    1: 'lime',
    2: 'orange',
    3: 'lightblue',
    4: 'pink',
    5: 'purple',
    6: 'yellow'
}

G = nx.Graph()
G.add_edges_from(edges)

node_colors = [color_map[colors_assigned[node]] for node in G.nodes()]

pos = nx.spring_layout(G)  
nx.draw(G, pos, with_labels=True, node_color=node_colors, node_size=800, font_size=16)
plt.title("Graph Coloring Visualization")
plt.show()

*/
