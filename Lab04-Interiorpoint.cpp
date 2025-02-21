#include<iostream>
#include<string>

using namespace std;

int determinant(int **mat, int n){
    if(n==1){
        return mat[0][0];
    }
    if(n==2){
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
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

bool LeftRight(int p1x,int p1y,int p2x,int p2y,int p3x,int p3y){
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


int main(){
    
    int **triangle= new int*[3];
    for(int i=0;i<3;i++){
        triangle[i]=new int[2];
    }

    cout<<"*************** Triangle ABC *****************"<<endl;
    cout<<"enter the coordinates of A ";
    cin>>triangle[0][0];
    cin>>triangle[0][1];
    cout<<"enter the coordinates of B ";
    cin>>triangle[1][0];
    cin>>triangle[1][1];
    cout<<"enter the coordinates of C ";
    cin>>triangle[2][0];
    cin>>triangle[2][1];

    cout<<"enter the coordinates of D ";
    int dx,dy;
    cin>>dx>>dy;

    bool l1=LeftRight(triangle[0][0],triangle[0][1],triangle[1][0],triangle[1][1],dx,dy);
    bool l2=LeftRight(triangle[1][0],triangle[1][1],triangle[2][0],triangle[2][1],dx,dy);
    bool l3=LeftRight(triangle[2][0],triangle[2][1],triangle[0][0],triangle[0][1],dx,dy);
    
    if(l1 && l2 && l3){
        cout<<"Point D is an interior point of triangle ABC ";
    }
    else{
        cout<<"Point D is an exterior point of triangle ABC ";
    }

    for (int i = 0; i < 3; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
    return 0;

}
