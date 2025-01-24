#include<iostream> 
using  namespace std;  


bool lenearscharr(int arr[] , int n, int k){
4
    if(n==0)
    return false;  
    if(arr[0]==k){
     return true; 
    }  
    else{

         bool reamain =  lenearscharr(arr+1,n-1, k);
        return  reamain;
    }
} 
int main(){

    int n; 
    cin>>n; 

    int  arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } 

    int  k; 
    cin>>k;  
    bool ans=  lenearscharr(arr,n, k); 

    if(ans) 
    cout<<"yes"<<endl; 
    else 
  cout<<"no"<<endl;

}