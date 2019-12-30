#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class Queue
{
private:
    node *front;
    node *rear;
public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void enqueue(int val)
    {
        node *newer = new node;
        newer->data=val;
        newer->link=NULL;
        if(front==NULL)
            front=newer;
        else
            rear->link=newer;
        rear=newer;
    }
void display()
    {
        node *current=front;
        cout<<"\nValues are "<<endl;
        while(current!=NULL)
        {
            cout<<current->data<<"\t"<<endl;
            current =current->link;
        }
        cout<<endl;
    }
    bool isempty()
    {
        if(front ==NULL)
            return true;
        else
            return false;
    }
    int dequeue()
    {
        node *temp=front;
        front=front->link;
        int out=temp->data;
        delete temp;
        if(front==NULL)
            rear=NULL;
        return out;
    }
};
int main()
{
    Queue q;
    int choice,val;
    int exit;
    exit=0;
    cout<<"\t\t\t*** Welcome to Link Implementation Of Queue ***"<<endl;
    cout<<"\t\tWhat you want to do"<<endl;
    while(true)
    {
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.Delete"<<endl;
        cout<<"\t3.Display"<<endl;
        cout<<"\t4.Exit\n"<<endl;
        cout<<"Enter Choice here : "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the value : ";
            cin>>val;
            q.enqueue(val);
            break;
        case 2:
            if(q.isempty()==true)
                cout<<"\nContains no value yet"<<endl;
            else
                q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
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

