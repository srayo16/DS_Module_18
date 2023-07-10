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

Node *inputIssue()
{
    int r;
    cin >> r;
    Node *root;
    queue<Node *> q;

    if (r == -1)
        root = NULL;
    else
        root = new Node(r);

    if (root)
        q.push(root);

    while (!q.empty())
    {
        // 1.ber kora
        Node *f = q.front();
        q.pop();

        // 2. jabotio kaj kora

        Node *lc, *rc;
        int l, r;
        cin >> l >> r;
        if (l == -1)
            lc = NULL;
        else
            lc = new Node(l);
        if (r == -1)
            rc = NULL;
        else
            rc = new Node(r);

        f->left = lc;
        f->right = rc;
        //  3. children rakha

        // q.push(lc);
        // q.push(rc);

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return root;
}

void levelOrderLR(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotio ja kaj ase
        cout << f->val << " ";

        // 3. childern gulu ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{
    Node *root = inputIssue();
    levelOrderLR(root);

    return 0;
}