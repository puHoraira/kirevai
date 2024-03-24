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
    int pop(){
        Node* temp=head;
        if(head==NULL){
            cout<<"Nothing to pop"<<endl;
            return -1;
        }
        if(head==tail){
            int val=head->val;
            head=NULL;
            tail=NULL;
            free(temp);
            return val;
        }
        int val=head->val;
        head=head->next;
        free(temp);
        return val;
    }
};
struct Queue{
    Node *head = NULL;
    Node *tail = NULL;
    void push(int x)
    {
        Node *temp = new Node();
        temp->val = x;
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
            tail = head;
        }
        else
        {
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }
    int pop()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
        if (head == tail)
        {
            int val=head->val;
            head = NULL;
            tail = NULL;
            free(temp);
            return val;
        }
        else
        {
            int val=head->val;
            head = head->next;
            free(temp);
            return val;
        }
    }
};
int main()
{
    string str1;
    cin>>str1;
    Queue* new_queue=new Queue();
    Stack* new_stack=new Stack();
    int length=str1.size();
    for(int i=0;i<length;i++){
        new_queue->push(str1[i]);
        new_stack->push(str1[i]);
    }
    for(int i=0;i<length/2;i++){
        char ch1=(char)new_queue->pop();
        char ch2=(char)new_stack->pop();
        if(ch1!=ch2){
            cout<<"Not Palindrome"<<endl;
            return 0;
        }
    }
    cout<<"Palindrome"<<endl;
    return 0;
}