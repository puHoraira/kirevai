#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
struct SinglyLinkedList
{
    Node *head = NULL;
    Node *tail = NULL;
    void insert_at_last(int x)
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
    void insert_at_first(int x)
    {
        Node *temp = new Node();
        // Node* temp=(Node*)malloc(sizeof(Node));
        temp->val = x;
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
    void delete_first_element()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No element to delete" << endl;
            return;
        }
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            free(temp);
        }
        else
        {
            head = head->next;
            free(temp);
        }
    }
    void delete_last_element()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No element to delete" << endl;
            return;
        }
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            free(tail);
            tail = temp;
        }
    }
    void delete_element(int x)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No element to delete" << endl;
            return;
        }
        if (head->val == x && head == tail)
        {
            head = NULL;
            tail = NULL;
            free(temp);
            return;
        }
        // if(temp->next==NULL)then (temp->next->val) will give error
        if (head->val == x)
        {
            head = head->next;
            free(temp);
            return;
        }
        while (temp->next && temp->next->val != x)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Element Not Found" << endl;
            return;
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    void print_linkedlist()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    SinglyLinkedList *new_list = new SinglyLinkedList();
    int n;
    cin >> n;
    while (n--)
    {
        cout << "1.Insert At First\n2.Insert At Last\n3.Delete First Element\n4.Delete Last Element\n5.Delete Element\n6.Print Linked List\n";
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            int temp2;
            cin >> temp2;
            new_list->insert_at_first(temp2);
        }
        else if (temp == 2)
        {
            int temp2;
            cin >> temp2;
            new_list->insert_at_last(temp2);
        }
        else if (temp == 3)
        {
            new_list->delete_first_element();
        }
        else if (temp == 4)
        {
            new_list->delete_last_element();
        }
        else if (temp == 5)
        {
            int temp2;
            cin >> temp2;
            new_list->delete_element(temp2);
        }
        else
        {
            new_list->print_linkedlist();
        }
    }
    return 0;
}