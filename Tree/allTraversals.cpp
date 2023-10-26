#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left of:" << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right of:" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}

void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int CountnumberofNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = CountnumberofNodes(root->left);
    int rightCount = CountnumberofNodes(root->right);

    return leftCount + rightCount + 1;
}

int HeightofTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = HeightofTree(root->left) + 1;
    int rightHeight = HeightofTree(root->right) + 1;

    return max(leftHeight, rightHeight);
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
    {
        return;
    }

    q.push(root);

    while (q.size() > 0)
    {
        int n = q.size();
        while (n > 0)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            n--;
        }
        cout << endl;
    }
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    // Example Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Inorder Traversal: ";
    InorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    PostorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    PreorderTraversal(root);
    cout << endl;

    cout << "Number of Nodes in Tree: ";
    int count = CountnumberofNodes(root);
    cout << count << endl;

    cout << "Height of the Tree: ";
    int height = HeightofTree(root);
    cout << height << endl;

    cout << "Level Order Traversal: ";
    cout << endl;
    LevelOrderTraversal(root);

    return 0;
}
