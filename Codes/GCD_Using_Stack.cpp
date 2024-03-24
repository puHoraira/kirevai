#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    stack<int>new_stack;
    new_stack.push(num1);
    new_stack.push(num2);
    while(new_stack.top()!=0){
        int val1=new_stack.top();
        new_stack.pop();
        int val2=new_stack.top();
        new_stack.pop();
        new_stack.push(val1);
        new_stack.push(val2%val1);
    }
    new_stack.pop();
    cout<<new_stack.top()<<endl;
}