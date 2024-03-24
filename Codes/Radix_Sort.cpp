#include <bits/stdc++.h>
using namespace std;
void count_sort_digit(long long n,long long arr[],long long exp){
    vector<long long>ans[10];
    vector<long long>ans2[10];
    for(long long i=0;i<n;i++){
        long long val=(abs(arr[i])/exp)%10;
        if(arr[i]>=0)ans[val].push_back(arr[i]);
        else ans2[val].push_back(arr[i]);
    }
    long long ind=0;
    for(long long i=9;i>=0;i--){
        for(auto &x:ans2[i]){
            arr[ind]=x;
            ind++;
        }
    }
    for(long long i=0;i<10;i++){
        for(auto &x:ans[i]){
            arr[ind]=x;
            ind++;
        }
    }
}
void radix_sort(long long n,long long arr[]){
    long long max_exp=0;
    for(long long i=0;i<n;i++){
        long long val=abs(arr[i]);
        long long temp=0;
        while(val){
            if(temp==0)temp=1;
            else temp*=10;
            val/=10;
        }
        max_exp=max(max_exp,temp);
    }
    long long exp=1;
    while(exp<=max_exp){
        count_sort_digit(n,arr,exp);
        exp*=10;
    }
}
int main(){
    long long n;
    cin>>n;
    long long arr[n];
    for(auto &x:arr)cin>>x;
    radix_sort(n,arr);
    for(auto &x:arr)cout<<x<<" ";
    cout<<endl;
}