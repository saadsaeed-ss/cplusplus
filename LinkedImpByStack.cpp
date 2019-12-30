#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class Stack
{
private:
    node *top;
public:
    Stack()
    {
        top=NULL;
    }
    void push(int val)
    {
        node *newer = new node;
        newer->data=val;
        newer->link=top;
        top=newer;
    }
    int pop()
    {
        node *temp=top;
        int out=temp->data;
        top=top->link;
        delete temp;
        return out;
    }
    void display()
    {
        node *current=top;
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
        if(top==NULL)
            return true;
        else
            return false;
    }

};

int main()
{
    Stack s;
    int choice,val;
    int exit;
    exit=0;
    cout<<"\t\t\t*** Welcome ***"<<endl;
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
            s.push(val);
            break;
        case 2:
            if(s.isempty()==true)
                cout<<"\nContains no value yet"<<endl;
            else
                s.pop();
            break;
        case 3:
            s.display();
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
