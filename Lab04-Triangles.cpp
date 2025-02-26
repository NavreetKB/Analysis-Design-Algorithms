#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;



void initialise(vector<pair<int,int>>& arr,int n)
{
    for(int i=0;i<n;i++){
        arr[i].first=rand()%10-5;
        arr[i].second=rand()%10-5;
    }

}
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void triangles(vector<pair<int,int>> points,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                float d1= distance(points[i].first,points[i].second,points[j].first,points[j].second);
                float d2=distance(points[j].first,points[j].second,points[k].first,points[k].second);
                float d3=distance(points[i].first,points[i].second,points[k].first,points[k].second);
                if(d1==0 || d2==0 || d3==0){
                    break;
                }
                if((d1+d2>d3) && (d1+d3>d2) && (d2+d3>d1))
                {
                    cout<<"points ("<<points[i].first<<","<<points[i].second<<") , ("<<points[j].first<<","<<points[j].second<<") , ("<<points[k].first<<","<<points[k].second<<") form a triangle "<<endl;
                }
            }
        }
    }
}


int main(){
    cout<<"enter the number of points ";
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    initialise(points,n);
    cout<<"points are \n";
    for(int i=0;i<n;i++){
        cout<<points[i].first<<","<<points[i].second<<endl;
    }
    triangles(points,n);

    return 0;

}
