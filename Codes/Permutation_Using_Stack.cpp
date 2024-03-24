#include <bits/stdc++.h>
using namespace std;
vector<stack<char>>ans;
void rec(int ind,int size,string str1,stack<char>prev){
    if(ind==size){
        ans.push_back(prev);
        return;
    }
    for(int i=0;i<size;i++){
        stack<char>new_stack=prev;
        new_stack.push(str1[i]);
        rec(ind+1,size,str1,new_stack);
    }
}
int main()
{
    int n;
    cin>>n;
    string str1;
    cin>>str1;
    stack<char>new_stack;
    rec(0,n,str1,new_stack);
    for(int i=0;i<ans.size();i++){
        while(ans[i].size()>0){
            cout<<ans[i].top();
            ans[i].pop();
        }
        cout<<endl;
    }
    return 0;
}