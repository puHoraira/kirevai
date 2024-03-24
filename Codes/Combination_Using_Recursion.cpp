#include <bits/stdc++.h>
using namespace std;
#define ll long long
void rec(ll ind,ll curr_size,ll comb_size,ll tot_size,ll curr[],ll arr[]){
    if(ind==tot_size){
        if(curr_size!=comb_size)return;
        for(ll i=0;i<curr_size;i++){
            cout<<curr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(curr_size==comb_size){
        for(ll i=0;i<curr_size;i++){
            cout<<curr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    curr[curr_size]=arr[ind];
    rec(ind+1,curr_size+1,comb_size,tot_size,curr,arr);
    rec(ind+1,curr_size,comb_size,tot_size,curr,arr);
}
int main()
{
    ll n,p;
    cin>>n>>p;
    ll a[n];
    for(auto &x:a)cin>>x;
    ll curr[p]={0};
    rec(0,0,p,n,curr,a);
    return 0;
}