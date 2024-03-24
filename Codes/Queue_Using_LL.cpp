#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
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