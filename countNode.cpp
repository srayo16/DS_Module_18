#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int countNodeMeh(Node *root)
{
    int sz = 0;
    if (root == NULL)
        return sz;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotio ja kaj ase
        // cout << f->val << " ";
        sz++;

        // 3. childern gulu ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return sz;
}
int countNode(Node *root)
{
    if (root == NULL)
        return 0;

    int l = countNode(root->left);
    int r = countNode(root->right);

    return l + r + 1;
}
int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    // connection

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    h->right = i;
    b->right = d;
    d->left = f;
    d->right = g;

    int sz = countNodeMeh(root);
    int sz1 = countNode(root);
    cout << sz << endl;
    cout << sz1 << endl;

    return 0;
}