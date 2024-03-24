#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left_child = NULL;
    node *right_child = NULL;
};
struct BT
{
    node *root = NULL;
    void add_root(int val)
    {
        node *new_node = new node();
        new_node->val = val;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        root = new_node;
    }
    bool add_child(int val1, int val2, node *p, bool *found)
    {
        if (*found == true)
            return *found;
        if (p == NULL)
            return false;
        if (p->val == val1)
        {
            if (p->left_child == NULL)
            {
                node *temp = new node();
                temp->val = val2;
                temp->left_child = NULL;
                temp->right_child = NULL;
                p->left_child = temp;
                *found = true;
                return *found;
            }
            else if (p->right_child == NULL)
            {
                node *temp = new node();
                temp->val = val2;
                temp->left_child = NULL;
                temp->right_child = NULL;
                p->right_child = temp;
                *found = true;
                return *found;
            }
        }
        else
        {
            add_child(val1, val2, p->left_child, found);
            add_child(val1, val2, p->right_child, found);
            return *found;
        }
    }
    void In_Order_Traversal(node *p)
    {
        if (!p)
            return;
        In_Order_Traversal(p->left_child);
        cout << p->val << " ";
        In_Order_Traversal(p->right_child);
    }
    void Pre_Order_Traversal(node *p)
    {
        if (!p)
            return;
        cout << p->val << " ";
        Pre_Order_Traversal(p->left_child);
        Pre_Order_Traversal(p->right_child);
    }
    void Post_Order_Traversal(node *p)
    {
        if (!p)
            return;
        Pre_Order_Traversal(p->left_child);
        Pre_Order_Traversal(p->right_child);
        cout << p->val << " ";
    }
};
int main()
{
    int n;
    cin >> n;
    BT *new_BT = new BT();
    for (int i = 0; i < n; i++)
    {
        int parent_val, child_val;
        cin >> parent_val >> child_val;
        if (i == 0)
        {
            new_BT->add_root(parent_val);
        }
        bool flag = false;
        if (!new_BT->add_child(parent_val, child_val, new_BT->root, &flag))
        {
            cout << "Could not add node" << endl;
        }
    }
    new_BT->In_Order_Traversal(new_BT->root);
    cout << endl;
    new_BT->Pre_Order_Traversal(new_BT->root);
    cout << endl;
    new_BT->Post_Order_Traversal(new_BT->root);
    return 0;
}