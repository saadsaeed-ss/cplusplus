#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class singlylist
{
private:
    node  *head;
public:
    singlylist()
    {
        head=NULL;
    }
    void addfirst(int val)
    {
        node *newer=new node;
        newer->data=val;
        newer->link=head;
        head=newer;
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
            newer->link=NULL;
            node *temp=head;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newer;
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
                newer->link=temp->link;
                temp->link=newer;
                return;
            }
            temp=temp->link;
        }
        cout<<"\nValue not found"<<endl;
    }
    void insertbefore(int sval,int val)
    {
        node  *temp=head;
        node *prev=temp;
        while(temp!=NULL)
        {
            if(head->data==sval)
            {
                node *newer=new node;
                newer->data=val;
                newer->link=head;
                head=newer;
                return;
            }
            else if(temp->data==sval)
            {
                node *newer=new node;
                newer->data=val;
                newer->link=temp;
                prev->link=newer;
                return;
            }
            prev=temp;
            temp=temp->link;
        }
        cout<<"\nValue Not Found"<<endl;
    }

    void deletenode(int val)
    {
        node *temp=head;
        node *prev=temp;
        while(temp!=NULL)
        {
            if(head->data==val)
            {
                head=head->link;
                delete temp;
                cout<<"\n"<<val<<" deleted"<<endl;
                return;
            }
            else if(temp->data==val)
            {
                prev->link=temp->link;
                delete temp;
                cout<<"\n"<<val<<" deleted"<<endl;
                return;
            }
            prev=temp;
            temp=temp->link;
        }
    }
    void delafter(int sval)
    {
        node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==sval && temp->link!=NULL)
            {
                node *succ=temp->link;
                temp->link=succ->link;
                cout<<"\n"<<succ->data<<" deleted"<<endl;
                delete succ;
                return;
            }
            temp=temp->link;
        }
        cout<<"\nValue not found"<<endl;
    }
    void delbefore(int sval)
    {
        node *temp=head;
        node *bprev,*prev=temp;
        while(temp!=NULL)
        {
            if(temp->data==sval && prev==head)
            {
                head=temp;
                cout<<"\n"<<prev->data<<" deleted"<<endl;
                delete prev;
                return;
            }
            else if(temp->data==sval)
            {
                bprev->link=prev->link;
                cout<<"\n"<<prev->data<<" deleted"<<endl;
                delete prev;0
                return;
            }
            bprev=prev;
            prev=temp;
            temp=temp->link;
        }
        cout<<"\nValue not found\n";
    }
    void display()
    {
        node *temp=head;
        cout<<"Values are : ";
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            temp=temp->link;
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
    singlylist slist;
    int choice,val,sval,exit;
    exit=0;
    cout<<"***Welcome to Sinlgy Linked List***"<<endl;
    cout<<"What you want to do : "<<endl;
    while(true)
    {
        cout<<"1.AddFirst"<<endl;
        cout<<"2.AddLast"<<endl;
        cout<<"3.InsertAfter"<<endl;
        cout<<"4.InsertBefore"<<endl;
        cout<<"5.Delete"<<endl;
        cout<<"6.DeleteAfter"<<endl;
        cout<<"7.DeleteBefore"<<endl;
        cout<<"8.Display"<<endl;
        cout<<"9.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter the value you want to add at the front : ";
            cin>>val;
            slist.addfirst(val);
            break;
        case 2:
            cout<<"\nEnter the value you want to add in the end : ";
            cin>>val;
            slist.addlast(val);
            break;
        case 3:
            cout<<"\nEnter the key value : ";
            cin>>sval;
            cout<<"\nEnter the value you want to add after: ";
            cin>>val;
            slist.insertafter(sval,val);
            break;
        case 4:
            cout<<"\nEnter the key value : ";
            cin>>sval;
            cout<<"\nEnter the value you want to add before: ";
            cin>>val;
            slist.insertbefore(sval,val);
            break;
        case 5:
            if(slist.isempty())
            {
                cout<<"\nthere is no vallue to delete :)"<<endl;
            }
            else
            {
                cout<<"\nEnter the value you want to delete: ";
                cin>>val;
                slist.deletenode(val);
            }
        case 6:
            if(slist.isempty())
            {
                cout<<"\nthere is no vallue to delete :)"<<endl;
            }
            else
            {
                cout<<"\nEnter the key value to delete after val : ";
                cin>>val;
                slist.delafter(val);
            }
            break;
        case 7:
            if(slist.isempty())
            {
                cout<<"\nthere is no vallue to delete :)"<<endl;
            }
            else
            {
                cout<<"\nEnter the key value to delete before val: ";
                cin>>val;
                slist.delbefore(val);
            }
            break;
        case 8:
            slist.display();
            break;
        case 9:
            exit=1;
            break;
        }
        if(exit==1)
            break;
    }
    return 0;
}
