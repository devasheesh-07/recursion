#include<bits/stdc++.h> 
using  namespace std;  


bool lenearscharr(int arr[] ,int s,int e, int k){ 
  if(s>e)
   return false; 
// if(arr[mid]==k)
// return true;
 
int mid= s + (e-s)/2; 

if(arr[mid]==k)
return true;
if(arr[mid]<k){
    return lenearscharr(arr[], mid+1, e, k); 

}else 
     return lenearscharr(arr[], s,mid-1, k);
};
int main(){   
     int n; 
    cin>>n; 

    int  arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } 

    int k; 
    cin>>k;  
    bool ans=  lenearscharr(arr,0, n-1, k); 
    if(ans)
    cout<<"yes"<<endl; 
    else 
    cout<<"no"<<endl; 
    return 0;

}