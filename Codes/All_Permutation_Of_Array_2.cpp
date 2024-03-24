#include <bits/stdc++.h>
using namespace std;
#define ll long long
void rec(ll ind,ll size,ll curr[],ll arr[]){
    if(ind==size){
        for(ll i=0;i<size;i++){
            cout<<curr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(ll i=0;i<size;i++){
        ll find=arr[i];
        bool found=false;
        for(ll j=0;j<ind;j++){
            if(curr[j]==find){
                found=true;
                break;
            }
        }
        if(found)continue;
        curr[ind]=find;
        rec(ind+1,size,curr,arr);
    }
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(auto &x:a)cin>>x;
    ll curr[n]={-1};
    rec(0,n,curr,a);
    return 0;
}