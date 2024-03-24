#include <bits/stdc++.h>
using namespace std;
int max_element(int l,int r,int arr[]){
    if(l==r)return arr[l];
    int mid=(l+r)/2;
    int x=max_element(l,mid,arr);
    int y=max_element(mid+1,r,arr);
    if(x>y)return x;
    return y;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)cin>>x;
    cout<<max_element(0,n-1,arr)<<endl;
}