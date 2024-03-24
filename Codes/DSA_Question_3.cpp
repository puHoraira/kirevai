#include <bits/stdc++.h>
using namespace std;
void rec(int ind,int k,int count_a,stack<char>prev){
    if(ind==k){
        if(count_a>=4){
            while(prev.size()>0){
                cout<<prev.top();
                prev.pop();
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<3;i++){
        stack<char>new_stack=prev;
        new_stack.push('A'+i);
        if(i==0)rec(ind+1,k,count_a+1,new_stack);
        else rec(ind+1,k,count_a,new_stack);
    }
}
int main()
{
    int k;
    cin>>k;
    stack<char>new_stack;
    rec(0,k,0,new_stack);
}