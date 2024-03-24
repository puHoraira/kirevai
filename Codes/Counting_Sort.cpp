#include <bits/stdc++.h>
using namespace std;
void counting_sort(int n,int arr[]){
    int r=0;
    for(int i=0;i<n;i++)if(arr[i]>r)r=arr[i];
    int hash[r+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int ind=0;
    for(int i=0;i<=r;i++){
        while(hash[i]--){
            arr[ind]=i;
            ind++;
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    counting_sort(n,arr);
    for(auto &x:arr)cout<<x<<" ";
    cout<<endl;
    return 0;
}