#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string ch;
    Node *next;
};
struct Stack
{
    Node *head = NULL;
    Node *tail = NULL;
    void push(string ch)
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
    string pop()
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
        if ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))
        {
            string temp = "";
            temp.push_back(str1[i]);
            new_stack->push(temp);
        }
        else
        {
            string second = new_stack->pop();
            string first = new_stack->pop();
            string temp = "(" + first + str1[i] + second + ")";
            new_stack->push(temp);
        }
    }
    cout << new_stack->pop() << endl;
}