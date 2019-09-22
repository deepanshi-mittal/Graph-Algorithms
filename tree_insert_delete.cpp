#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}node;

node *findmn(node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left)
        return findmn(root->left);
    else
        return root;
}

node *del(node *root,int d)
{
    node *temp;
    if(root==NULL)
    {
        cout<<"Nothing to delete\n";
    }
    else if(d<(root->data))
    {
        root->left=del(root->left,d);
    }
    else if(d>(root->data))
    {
        root->right=del(root->right,d);
    }
    else
    {
        if(root->left && root->right)
        {
            temp=findmn(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
        else
        {
            if(root->left==NULL)
            {
                root=root->right;
            }
            else if(root->right==NULL)
            {
                root=root->left;
            }
            free(temp);
        }
    }
    return root;
}

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
    cout<<endl;
    cout<<"Enter element to be deleted : ";
    int d;
    cin>>d;
    head=del(head,d);
    cout<<endl;
    inorder(head);
    return 0;
}