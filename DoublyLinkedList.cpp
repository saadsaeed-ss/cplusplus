#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next,*prev;
};

class doublylist
{
private:
    node *head;
public:
    doublylist()
    {
        head=NULL;
    }
    void addfirst(int val)
    {
        node *newer=new node;
        newer->data=val;
        newer->prev=NULL;
        if(head==NULL)
        {
            head=newer;
            newer->next=NULL;
        }

        else
        {
            newer->next=head;
            head->prev=newer;
        }
        head=newer;
        cout<<val<<" added"<<endl;
    }
    void addlast(int val)
    {
        if(head==NULL)
        {
            addfirst(val);
            return;
        }
        else
        {
            node *newer=new node;
            newer->data=val;
            newer->next=NULL;
            node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            newer->prev=temp;
            temp->next=newer;
            cout<<val<<" added"<<endl;
        }
    }

    void insertafter(int sval,int val)
    {
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==sval)
            {
                node *newer=new node;
                newer->data=val;
                newer->next=temp->next;
                newer->prev=temp;
                temp->next=newer;
                if(newer->next==NULL)
                {
                    cout<<val<<" added"<<endl;
                    return;
                }
                else
                {
                    node *succ=newer->next;
                    succ->prev=newer;
                    cout<<val<<" added"<<endl;
                    return;
                }
            }
            temp=temp->next;
        }
    }

    void insertbefore(int sval,int val)
    {
        node *temp=head;
        node *prev=temp;
        while(temp!=NULL)
        {
            if(temp->prev==NULL && temp->data==sval)//this func is to add value before head.
            {
                node *newer=new node;
                newer->data=val;
                newer->prev=NULL;
                newer->next=temp;
                temp->prev=newer;
                head=newer;
                cout<<val<<" added"<<endl;
                return;
            }
            else if(temp->data==sval)//This fun is to add value anywhere in list except in the front.
            {
                node *newer=new node;
                newer->data=val;
                newer->next=temp;
                newer->prev=prev;
                temp->prev=newer;
                prev->next=newer;
                cout<<val<<" added"<<endl;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void deletenode(int val)
    {
        node *temp=head;
        node  *prev=head;
        while(temp!=NULL)
        {
            if(temp->data==val && temp->prev==NULL)//This is for the first value to delete
            {
                head=temp->next;
                head->prev=NULL;
                cout<<"\n"<<val<<" deleted"<<endl;
                delete temp;
                return;
            }
            else if(temp->data==val && temp->next==NULL)//This is for the last value to delete
            {
                prev->next=NULL;
                cout<<"\n"<<val<<" deleted"<<endl;
                delete temp;
                return;
            }
            else if(temp->data==val)//This is for the vallue to be deleted from center
            {
                prev->next=temp->next;
                node *succ=temp->next;
                succ->prev=prev;
                cout<<"\n"<<val<<" deleted"<<endl;
                delete temp;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        cout<<"\nValue not found Sorry\n";
    }
    void display()
    {
        node *temp=head;
        cout<<"\nValues are : ";
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
    bool isempty()
    {
        if(head==NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    doublylist dlist;
    int choice,val,sval,exit;
    exit=0;
    cout<<"***Welcome to Doubly Linked List***"<<endl;
    cout<<"What you want to do : "<<endl;
    while(true)
    {
        cout<<"1.AddFirst"<<endl;
        cout<<"2.AddLast"<<endl;
        cout<<"3.InsertAfter"<<endl;
        cout<<"4.InsertBefore"<<endl;
        cout<<"5.Delete"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter the value you want to add at the front : ";
            cin>>val;
            dlist.addfirst(val);
            break;
        case 2:
            cout<<"\nEnter the value you want to add in the end : ";
            cin>>val;
            dlist.addlast(val);
            break;
        case 3:
            cout<<"\nEnter the key value : ";
            cin>>sval;
            cout<<"\nEnter the value you want to add after: ";
            cin>>val;
            dlist.insertafter(sval,val);
            break;
        case 4:
            cout<<"\nEnter the key value : ";
            cin>>sval;
            cout<<"\nEnter the value you want to add before: ";
            cin>>val;
            dlist.insertbefore(sval,val);
            break;
        case 5:
            if(dlist.isempty())
            {
                cout<<"\nthere is no vallue to delete :)"<<endl;
            }
            else
            {
                cout<<"\nEnter the value you want to delete: ";
                cin>>val;
                dlist.deletenode(val);
            }
            break;
        case 6:
            dlist.display();
            break;
        case 7:
            exit=1;
            break;
        }
        if(exit==1)
            break;
    }
    return 0;
}
