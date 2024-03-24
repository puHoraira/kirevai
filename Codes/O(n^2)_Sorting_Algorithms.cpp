#include <bits/stdc++.h>
using namespace std;
void selection_sort(int n,int arr[]){
    for(int i=0;i<n;i++){
        int ind=i;
        int minimum=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<minimum){
                minimum=arr[j];
                ind=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
    }
}
void bubble_sort(int n,int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void insertion_sort(int n,int arr[]){
    for(int i=1;i<n;i++){
        for(int j=i;j>=1;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    //selection_sort(n,arr);
    //bubble_sort(n,arr);
    insertion_sort(n,arr);
    for(auto &x:arr)cout<<x<<" ";
    cout<<endl;
}