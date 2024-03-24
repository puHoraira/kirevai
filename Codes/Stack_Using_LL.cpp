#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
};
struct Stack{
    Node* head=NULL;
    Node* tail=NULL;
    void push(int x){
        Node* temp=new Node();
        temp->val=x;
        if(head==NULL){
            head=temp;
            head->next=NULL;
            tail=head;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    int peek(){
        if(head==NULL){
            cout<<"Nothing to peek"<<endl;
            return 0;
        }
        return head->val;
    }
    void pop(){
        Node* temp=head;
        if(head==NULL){
            cout<<"Nothing to pop"<<endl;
            return;
        }
        if(head==tail){
            head=NULL;
            tail=NULL;
            free(temp);
            return;
        }
        head=head->next;
        free(temp);
    }
};
int main()
{
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