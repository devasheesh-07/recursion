#include<iostream> 
using  namespace std;  
// cek array is sorted or not 
bool insorted(int *arr, int n){
   
   if(n==0 || n==1){
    return true; 
   } 
   if(arr[0]>arr[1]) 
    return false; 
   else{
    bool ans = insorted(arr+1, n-1);   
    return ans;
    }

}
int main()  
{  
 cout<<"etret value"<<endl;
 int n; 
 cin>>n; 
 int arr[n]; 
 for(int i=0;i<n; i++){
    cin>>arr[i]; 
 } 
 bool show= insorted(arr, n); 
 if(show){
   cout<<"Array is Sorded"<<endl;
 } 
 else 
 cout<<"not sorted"<<endl;
return 0;

}