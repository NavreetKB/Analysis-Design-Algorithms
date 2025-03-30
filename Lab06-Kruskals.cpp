#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

struct edgelist{
    int src;
    int dest;
    int wt;
};
typedef struct edgelist edge;

int find(int u,int*P){
    while(P[u]>=0){
        u=P[u];
    }
    return u;
}
void unite(int u,int v,int* P){
    P[u]=v;
}

void heapify(edge * edges,int e,int index){
    int l=index*2+1;
    int r=index*2+2;
    int least=index;
    if(l<e && edges[l].wt<edges[least].wt){
        least=l;
    }
    if(r<e && edges[r].wt<edges[least].wt){
        least=r;
    }
    if(least!=index){
        swap(edges[index].src,edges[least].src);
        swap(edges[index].dest,edges[least].dest);
        swap(edges[index].wt,edges[least].wt);
        heapify(edges,e,least);
    }
}

void minheap(edge* edges,int e){
    for(int i=e/2-1;i>=0;i--){
        heapify(edges,e,i);
    }
    
}

pair<int,int> deleteNode(edge * edges,int &size){
    if(size==-1){
        return {-1,-1};
    }

    pair<int,int> p;
    p.first=edges[0].src;
    p.second=edges[0].dest;

    edges[0]=edges[size];
    size--;
    heapify(edges,size,0);
    return p;
}

void Kruskal(edge* edges,int n,int** cost,int e){

    int** tree=new int*[n-1];
    for(int i=0;i<n-1;i++){
        tree[i]=new int[2];
    }
    minheap(edges,e);
    
    int size=e-1;
    
    int* P=new int[n];
    for(int i=0;i<n;i++){
        P[i]=-1;
    }
    int mincost=0;
    int i=0;
    pair<int,int> pr;
    while(i<n-1 && size!=0){
        pr=deleteNode(edges,size);
        
        int u=pr.first;
        int v=pr.second;
        int j=find(u,P);
        int k=find(v,P);
        if(j!=k){
            
            mincost+=cost[u][v];
            tree[i][0]=u;
            tree[i][1]=v;
            unite(j,k,P);
            i++;
        }
    }
    if(i!= (n-1)){
        cout<<"spanning tree does not exist\n";
        return;
    }
    cout<<"Tree : \n";
    for(int i=0;i<n-1;i++){
        cout<<tree[i][0]<<" to "<<tree[i][1]<<endl;
    }
    return;

}

int main(){
    int n;
    int e;
    cout<<"enter no. of vertices in graph : ";
    cin>>n;
    cout<<"enter no. of edges in graph : ";
    cin>>e;
    
    edge *edges=new edge[e]; 
  
    for (int i=0; i<e; i++) {
        cout<<" Enter 1st vertex, 2nd vertex, and weight: ";
        cin >>edges[i].src >> edges[i].dest >> edges[i].wt;
        int v1 =edges[i].src, v2=edges[i].dest, w=edges[i].wt;
    }

    int** cost =new int*[n];
    for (int i=0; i < n; i++) {
        cost[i]=new int[n]();
    } 
    int a,b,w;
    for(int i=0;i<n;i++){
        a=edges[i].src;
        b=edges[i].src;
        w=edges[i].wt;
        cost[a][b]=w;
        cost[b][a]=w;
    }
    Kruskal(edges,n,cost,e);
    return 0;
}

/*PYTHON CODE FOR GRAPH PLOTTING*/
/*
import networkx as nx
import matplotlib.pyplot as plt

class GraphVisualization:
    def __init__(self):
        self.visual = []

    def addEdge(self, a, b, weight=1):
        temp = (a, b, weight)
        self.visual.append(temp)

    def visualize(self):
        G = nx.Graph()
        for u, v, weight in self.visual:
            G.add_edge(u, v, weight=weight)

        pos = nx.spring_layout(G, k=1)  # Increase k for more spacing
        plt.figure(figsize=(7,7))
        nx.draw_networkx(G, pos)
        labels = nx.get_edge_attributes(G, 'weight')
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
        plt.show()
        # pos = nx.planar_layout(G)
        # nx.draw_networkx(G, pos)
        # labels = nx.get_edge_attributes(G, 'weight')
        # nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
        # plt.show()

G = GraphVisualization()
G.addEdge(6, 7, 1)
G.addEdge(5, 6, 2)
G.addEdge(2, 5, 4)
G.addEdge(8, 2, 2)
G.addEdge(3, 2, 7)
G.addEdge(0, 7, 8)
G.addEdge(1, 0, 4)
G.addEdge(4, 3, 9)
G.visualize()
*/
