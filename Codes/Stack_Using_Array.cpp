#include <bits/stdc++.h>
using namespace std;
int stack_arr[100001];
struct Stack{
    int size=-1;
    void push(int x){
        size++;
        stack_arr[size]=x;
    }
    int peek(){
        if(size==-1){
            cout<<"No element to peek"<<endl;
            return 0;
        }
        return stack_arr[size];
    }
    void pop(){
        if(size==-1){
            cout<<"Nothing to pop"<<endl;
            return;
        }
        size--;
    }
};
int main(){
    cout<<"Number of operations"<<endl;
    int n;
    cin>>n;
    Stack* new_stack=new Stack();
    while(n--){
        cout<<"1.Push\n2.Peek\n3.Pop"<<endl;
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            new_stack->push(x);
        }
        else if(op==2){
            int res=new_stack->peek();
            if(res){
                cout<<res<<endl;
            }
        }
        else{
            new_stack->pop();
        }
    }
}