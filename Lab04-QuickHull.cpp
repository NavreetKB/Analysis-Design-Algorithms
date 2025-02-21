#include<iostream>
#include<string>
#include<math.h>
#include<random>
#include<iomanip>

using namespace std;

int determinant(int **mat, int n){
    if(n==1){
        return mat[0][0];
    }
    if(n==2){
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    int ans=0;
    int col=0;
    for(col=0;col<n;col++){
        int **subMat=new int*[n-1];
        for(int i=0;i<n-1;i++){
            subMat[i]=new int[n-1];
        } 
    
        for(int i=1;i<n;i++){
            int subcol=0;
            for(int j=0;j<n;j++){
                if(j==col) 
                   continue;
                subMat[i-1][subcol++]=mat[i][j];
                
            }
        }
        int sign=1;
        if(col%2==0) 
           sign=1;
        else 
           sign =-1;
        ans+=sign*mat[0][col]*determinant(subMat,n-1);
    }
   
    return ans;
}

/*
bool LeftRightcheck(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y){
    bool flag=true;
    int **mat=new int*[3];
    for(int i=0;i<3;i++){
        mat[i]=new int[3];
    }
    mat[0][0]=p1x;
    mat[1][0]=p1y;
    mat[2][0]=1;

    mat[0][1]=p2x;
    mat[1][1]=p2y;
    mat[2][1]=1;

    mat[0][2]=p3x;
    mat[1][2]=p3y;
    mat[2][2]=1;

    int det = determinant(mat,3);
    if(det>0){
       flag=false;
    }
    else{
        flag =true;
    }
    
    return flag;
}
*/

bool LeftRightcheck(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
    int **mat = new int*[3];
    for (int i = 0; i < 3; i++) {
        mat[i] = new int[3];
    }
    mat[0][0]=p1x;  
    mat[0][1]=p2x;  
    mat[0][2]=p3x;  
    mat[1][0]=p1y;
    mat[1][1]=p2y;
    mat[1][2]=p3y;
    mat[2][0]=1;
    mat[2][1]=1;
    mat[2][2]=1;

    int det = determinant(mat, 3);

    for (int i=0;i<3;i++) 
    {
        delete[] mat[i];
    }
    delete[] mat;

    if(det < 0) return true;
    else return false;
}


void LeftRight(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y,vector<pair<int,int>> &leftPoints, vector<pair<int,int>> &rightPoints){
    int l=0;
    int r=0;
    bool flag=true;
    int **mat=new int*[3];
    for(int i=0;i<3;i++){
        mat[i]=new int[3];
    }
    mat[0][0]=p1x;
    mat[1][0]=p1y;
    mat[2][0]=1;

    mat[0][1]=p2x;
    mat[1][1]=p2y;
    mat[2][1]=1;

    mat[0][2]=p3x;
    mat[1][2]=p3y;
    mat[2][2]=1;

    int det = determinant(mat,3);
    if(det>0){
       leftPoints.push_back(make_pair(p3x,p3y));
    }
    else if(det<0){
       rightPoints.push_back(make_pair(p3x,p3y));
    }
  
}
/*
float distance(int x1,int y1, int x2,int y2){
    float d= pow((pow((x2-x1),2)+pow((y2-y1),2)),0.5);
    return d;
}

double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * abs(x1 *(y2 -y3)+ x2*(y3-y1)+x3*(y1-y2));
}

pair<int,int> largestTriangle(int **points,vector<pair<int,int>> side ,pair<int,int> p){
    
    int x1=points[p.first][0];
    int y1=points[p.first][1];
    int x2=points[p.second][0];
    int y2=points[p.second][1];
    int x3,y3;
    float maxarea=-1;
    pair<int,int> thirdPoint;

    for(int i=0;i<side.size();i++){
         x3=side[i].first;
         y3=side[i].second;
        float area=triangleArea(x1,y1,x2,y2,x3,y3);
        if(area>maxarea){
            thirdPoint.first=x3;
            thirdPoint.second=y3;
        }
    }
       
    
    cout<<"largest triangle "<<x3<<"  "<<y3<<endl;
    return thirdPoint;
}

*/



bool interior(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y,int p4x,int p4y){
    bool l1=LeftRightcheck(p1x,p1y,p2x,p2y,p4x,p4y);
    bool l2=LeftRightcheck(p2x,p2y,p3x,p3y,p4x,p4y);
    bool l3=LeftRightcheck(p3x,p3y,p1x,p1y,p4x,p4y);
    
    if(l1 && l2 && l3){
        cout<<"Point D is an interior point of triangle ABC ";
        return true;
    }
    else{
        cout<<"Point D is an exterior point of triangle ABC ";
        return false;
    }


}


void initialise(int **arr,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            arr[i][j]=(rand()%20-10);
        }
    }
}



pair<int,int> partition(int **points,int n){
    // pair<int,int> p;
    // float maxdist=-1;
    // int p1x,p1y,p2x,p2y;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         float d= distance(points[i][0],points[i][1],points[j][0],points[j][1]);
    //         if(d>maxdist){
    //             maxdist=d;
    //             p1x=i;
    //             p2x=j;
                
    //         }

    //     }
        
    // }
    // if(points[p1x][0]<points[p2x][0]){
    //     p.first=p1x;
    //     p.second=p2x;
    // }
    // else{
    //     p.first=p2x;
    //     p.second=p1x;
    // }
    
    // cout<<"max distance "<<maxdist<<endl;
    // cout<<setw(4)<<points[p1x][0]<<points[p1x][1]<<points[p2x][0]<<points[p2x][1]<<endl;
    // return p;

    int leftmost=0,rightmost=0;
    for(int i = 1; i < n; i++){
        if(points[i][0]<points[leftmost][0]) leftmost =i;
        if(points[i][0]>points[rightmost][0]) rightmost =i;
    }
    return {leftmost, rightmost};
   
}

/*
void QuickHull(int **points, int n,vector<pair<int,int>> & polygon,vector<pair<int,int>> side){
    
    
    pair<int,int> p;
    
    p=partition(points,n);

    cout<<"partion "<<p.first<<" "<<p.second;
    polygon.push_back(make_pair(points[p.first][0],points[p.first][1]));
    polygon.push_back(make_pair(points[p.second][0],points[p.second][1]));

    vector<pair<int,int>> leftPoints;
    vector<pair<int,int>> rightPoints;
    for(int i=0;i<n;i++){
        LeftRight(points[p.first][0],points[p.first][1],points[p.second][0],points[p.second][1],points[i][0],points[i][1],leftPoints,rightPoints);
    }
    //------------------------------------------------------------------
    pair<int,int> third_pt;
    third_pt=largestTriangle(points,leftPoints,p);
   
    polygon.push_back(make_pair(third_pt.first,third_pt.second));
    for(int i=0;i<leftPoints.size();i++){
        bool internal=interior(points[p.first][0],points[p.first][1],points[p.second][0],points[p.second][1],third_pt.first,third_pt.second,leftPoints[i].first,leftPoints[i].second);
        if (!internal){
            polygon.push_back(make_pair(leftPoints[i].first,leftPoints[i].second));
        }
        
    }

    pair<int,int> third_pt_rt;
    third_pt_rt=largestTriangle(points,rightPoints,p);
   
    polygon.push_back(make_pair(third_pt_rt.first,third_pt_rt.second));
    for(int i=0;i<rightPoints.size();i++){
        bool internal=interior(points[p.first][0],points[p.first][1],points[p.second][0],points[p.second][1],third_pt_rt.first,third_pt_rt.second,rightPoints[i].first,rightPoints[i].second);
        if (!internal){
            polygon.push_back(make_pair(rightPoints[i].first,rightPoints[i].second));
        }
        
    }

    
}
*/

double pointLineDistance(int x1, int y1, int x2, int y2, int px, int py) {
    return abs((y2 - y1) * px - (x2 - x1) * py + x2 * y1 - y2 * x1) /
           sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

pair<int, int> findFarthestPoint(int **points, vector<pair<int, int>> &side, pair<int, int> p) {
    int x1 = points[p.first][0], y1 =points[p.first][1];
    int x2 = points[p.second][0], y2 =points[p.second][1];
    int farthestIdx = -1;
    double maxDist = -1;

    for (int i = 0; i < side.size(); i++) {
        int x = side[i].first, y = side[i].second;
        double dist = pointLineDistance(x1, y1, x2, y2, x, y);
        if (dist > maxDist) {
            maxDist = dist;
            farthestIdx = i;
        }
    }

    if (farthestIdx != -1) {
        return side[farthestIdx];
    }
    return {-1, -1}; // No valid point found
}


// Recursively construct the convex hull
void QuickHullRec(int **points, vector<pair<int, int>> &hull, vector<pair<int, int>> &side, pair<int, int> p) {
    if (side.empty()) return;
    
    pair<int, int> farthest = findFarthestPoint(points, side, p);
    if (farthest.first == -1) return;

    hull.push_back(farthest);

    vector<pair<int, int>> leftSide1, leftSide2;
    for (auto point : side) {
        if (LeftRightcheck(points[p.first][0], points[p.first][1], farthest.first, farthest.second, point.first, point.second)) {
            leftSide1.push_back(point);
        } else if (LeftRightcheck(farthest.first, farthest.second, points[p.second][0], points[p.second][1], point.first, point.second)) {
            leftSide2.push_back(point);
        }
    }

    QuickHullRec(points, hull, leftSide1, {p.first, farthest.first});
    QuickHullRec(points, hull, leftSide2, {farthest.first, p.second});
}

// QuickHull Wrapper Function
void QuickHull(int **points, int n, vector<pair<int, int>> &hull) {
    pair<int, int> p=partition(points, n);
    
    
    hull.push_back({points[p.first][0], points[p.first][1]});
    hull.push_back({points[p.second][0], points[p.second][1]});
   
    vector<pair<int, int>> leftSide, rightSide;
    for (int i = 0; i < n; i++) {
        if (i != p.first && i != p.second) {
            if (LeftRightcheck(points[p.first][0], points[p.first][1], points[p.second][0], points[p.second][1], points[i][0], points[i][1])) {
                leftSide.push_back({points[i][0], points[i][1]});
            } else {
                rightSide.push_back({points[i][0], points[i][1]});
            }
        }
    }
    
    QuickHullRec(points, hull, leftSide, {p.first, p.second});
    QuickHullRec(points, hull, rightSide, {p.second, p.first});
}


int main(){
   
    cout << "Enter number of points: ";
    int n;
    cin >> n;
    if (n < 3) {
        cout << "Too few points for convex hull\n";
        return 0;
    }

    int **points = new int *[n];
    for (int i = 0; i < n; i++) {
        points[i] = new int[2];
    }

    initialise(points, n);

    cout << "The points are:\n";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << points[i][0] << ", " << setw(3) << points[i][1] << "\n";
    }

    vector<pair<int, int>> hull;
    QuickHull(points,n,hull);

    cout << "\nConvex Hull Points:\n";
    for (const auto &p : hull) {
        cout<<p.first<< ", " <<p.second<<"\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] points[i];
    }
    delete[] points;

    return 0;

}
