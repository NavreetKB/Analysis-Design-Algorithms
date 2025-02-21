    #include<iostream>
    #include<string>
    #include<stack>
    using namespace std;

    int partition(int *arr,int s,int e){
        int pivot= arr[s];
        int i=s;
        int j=e;
        while(i<=j){
            while(arr[i]<=pivot && i<=e){
                i++;
            }
            while(arr[j]>pivot && j>=s){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[s],arr[j]);
        return j;

    }

    /*
    void QSiterative(int *arr, int s,int e){
        
        stack<int> st;
        st.push(s);
        st.push(e);
        
        while(!st.empty()){
            cout<<"stack size ";
            cout<<st.size()<<"  ";

        e=st.top();
        st.pop();
        s=st.top();
        st.pop();

        int p=partition(arr,s,e);
        if(p-1>s){
            st.push(s);
            st.push(p-1);

        }
        if(p+1 < e){
            st.push(p+1);
            st.push(e);
        }
        }
        
    }
    */

    void iterativeQS(int *arr,int l ,int h){
        stack<int> stk;
        while(true){
            while(l<h){
                int j=partition(arr,l,h);
                
                if(j-l >=h-j){
                    
                    stk.push(l);
                    stk.push(j-1);
                    l=j+1;
                }
                else{
                    stk.push(j+1);
                    stk.push(h);
                    h=j-1;
                }
            
            }
            if(stk.empty()){
                return;
            }
            else{
                h=stk.top();
                stk.pop();
                l=stk.top();
                stk.pop();
            }
        }
    }

    int main()
    { 
        cout<<"enter the size of array ";
        int n;
        cin>>n;

        int *arr=new int[n];
        cout<<"enter the array ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        iterativeQS(arr,0,n-1);
        cout<<"sorted array\n";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<"  ";
        }
        return 0;
    }
