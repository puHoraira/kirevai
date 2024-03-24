#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int ch;
    Node *next;
};
struct Stack
{
    Node *head = NULL;
    Node *tail = NULL;
    void push(int ch)
    {
        Node *temp = new Node();
        temp->ch = ch;
        if (head == NULL)
        {
            head = temp;
            head->next = NULL;
            tail = head;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    int pop()
    {
        Node *temp = head;
        head = head->next;
        return temp->ch;
    }
};
int main()
{
    string str1;
    cin >> str1;
    Stack *new_stack = new Stack();
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
        {
            new_stack->push(str1[i] - '0');
        }
        else
        {
            int res1 = new_stack->pop();
            int res2 = new_stack->pop();
            if (str1[i] == '+')
            {
                new_stack->push(res1+res2);
            }
            if (str1[i] == '-')
            {
                new_stack->push(res2-res1);
            }
            if (str1[i] == '*')
            {
                new_stack->push(res1*res2);
            }
            if (str1[i] == '/')
            {
                new_stack->push(res2/res1);
            }
            if (str1[i] == '^')
            {
                new_stack->push(pow(res2,res1));
            }
        }
    }
    cout<<new_stack->pop()<<endl;
}