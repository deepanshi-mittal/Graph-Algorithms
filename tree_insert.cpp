#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}node;

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<(root->data)<<" ";
    inorder(root->right);
}

node *insertk(int k,node *root)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->data=k;
    if(root==NULL)
    {
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else
    {
        if(k < (root->data))
        {
            root->left = insertk(k,root->left);
        }
        else if(k > (root->data))
        {
            root->right = insertk(k,root->right);
        }
        return root;
    }
}



int main()
{
    int n;
    cin>>n;
    node *head=NULL;
    while(n>0)
    {
        int k;
        cin>>k;
        head = insertk(k,head);
        cout<<"\n Elements in bst are : ";
        inorder(head);
        n--;
    }
    
    return 0;
}