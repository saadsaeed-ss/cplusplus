#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class Cqueue
{
private:
    node *rear;
    int count;
public:
    Cqueue()
    {
        rear=NULL;
        count=0;
    }

    void add(int val)
    {
        node *newer = new node;
        newer->data=val;
        if(rear==NULL)
            rear=newer;
        else
            newer->link=rear->link;
            rear->link=newer;
            rear=newer;
            cout<<"\nEntered value is "<<newer->data<<endl;
    }
     void remove_val()
    {
        node *temp=rear->link;
        if(rear==rear->link)
        {
            int out=temp->data;
            delete temp;
            rear=NULL;
            cout<<"Deleted value is : "<<out<<endl;
            return;
        }
        rear->link=temp->link;
        int out=temp->data;
        cout<<"Deleted value is : "<<out<<endl;
        delete temp;
        return;
    }
    void remove_odd()
    {
        node *temp=rear->link;
        node *prev=temp;
        if(rear==rear->link && temp->data%2!=0)
        {
            int out=temp->data;
            delete temp;
            rear=NULL;
            return;
        }
        while(temp!=rear)
        {
            if(temp->data%2!=0)
            {
                if(rear->link==temp)
                {
                    int out=temp->data;
                    rear->link=temp->link;
                    delete temp;
                    temp=rear->link;
                }
                else
                {
                    int out=temp->data;
                    prev->link=temp->link;
                    delete temp;
                    temp=prev->link;
                }
            }
            else
            {
                prev=temp;
                temp=temp->link;
            }
        }
        if(rear->data%2!=0)
        {
            prev->link=rear->link;
            delete rear;
            rear=prev;
        }
    }
void display()
    {
        node *current=rear->link;
        cout<<"\nValues are "<<endl;
        while(current!=rear)
        {
            cout<<current->data<<"\t";
            current=current->link;
        }
        cout<<current->data<<"\t";
        cout<<endl;
    }
    bool isempty()
    {
        if(rear==NULL)
            return true;
        else
            return false;
    }

};
int main()
{
    Cqueue cq;
    int choice,val;
    int exit;
    exit=0;
    cout<<"\t\t\t*** Welcome to Link Implementation Of Cqueue ***"<<endl;
    cout<<"\t\tWhat you want to do"<<endl;
    while(true)
    {
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Delete"<<endl;
        cout<<"\t3.RemoveOdd"<<endl;
        cout<<"\t4.Display"<<endl;
        cout<<"\t5.Exit\n"<<endl;
        cout<<"Enter Choice here : "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the value : ";
            cin>>val;
            cq.add(val);
            break;
        case 2:
            if(cq.isempty()==true)
                cout<<"\nContains no value yet"<<endl;
            else
                cq.remove_val();
            break;
        case 3:
            if(cq.isempty()==true)
                cout<<"\nContains no value yet"<<endl;
            else
                cq.remove_odd();
            break;
        case 4:
            if(cq.isempty()==true)
                cout<<"\nContains no value yet"<<endl;
            else
            cq.display();
            break;
        case 5:
            exit=1;
            break;
        default:
            cout<<"\nWrong choice\n";
        }
        if(exit==1)
            break;
    }
    return 0;
}
