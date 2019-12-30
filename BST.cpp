#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

class bst
{
private:
    node *root;
public:
    bst()
    {
        root==NULL;
    }
    node*   return_root()
    {
        return root;
    }
    void insert_node(int val)
    {
        node *parent;
        node *newer=new node;
        newer->data=val;
        newer->left=NULL;
        newer->right=NULL;
        if(root==NULL)
            root=newer;
        else
        {
            node *current=root;
            while(current!=NULL)
            {
                parent=current;
                if(newer->data>current->data)
                    current=current->right;
                else
                    current=current->left;
            }
            if(newer->data>parent->data)
                parent->right=newer;
            else
                parent->left=newer;
        }
    }

    void preorder(node *temp)
    {
        if(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            if(temp->left!=NULL)
                preorder(temp->left);
            if(temp->right!=NULL)
                preorder(temp->right);
        }
        else
            cout<<"\nTree is empty"<<endl;
    }
    void inorder(node *temp)
    {
        if(temp!=NULL)
        {
            if(temp->left!=NULL)
                inorder(temp->left);
            cout<<temp->data<<"\t";
            if(temp->right!=NULL)
                inorder(temp->right);
        }
        else
            cout<<"\nTree is empty"<<endl;
    }
    void postorder(node *temp)
    {
        if(temp!=NULL)
        {
            if(temp->left!=NULL)
                postorder(temp->left);
            if(temp->right!=NULL)
                postorder(temp->right);
            cout<<temp->data<<"\t";
        }
        else
            cout<<"\nTree is empty"<<endl;
    }
};

int main()
{
 bst list;
 list.insert_node(5);
 list.insert_node(10);
 list.insert_node(12);
 list.insert_node(7);
 node *temp=list.return_root();
 list.postorder(temp);
 return 0;
}
