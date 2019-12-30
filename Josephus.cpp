#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};
class josephus
{
private:
    node *rear;
    node *temp,*first,*prev;
    int counter;
public:
    josephus()
    {
        rear=NULL;
        counter=0;
    }
    void add(int val)
    {
       node*newer=new node;
        newer->data=val;
        if(rear==NULL)
            rear=newer;
        else
            newer->link=rear->link;
        rear->link=newer;
        rear=newer;
        counter++;
    }
    void display()
    {
        node *current=rear->link;
        while(current!=rear)
        {
            cout <<current->data<<"\t";
            current=current->link;
        }
        cout <<current->data<<endl;
    }
    int length()
    {
        return counter;
    }
    int rem()
    {
        int out=temp->data;
        prev->link=first;
        delete temp;
        counter--;
        return out;
    }
    void start()
    {
        first=rear->link;
        prev=temp=first;
    }

    void next()
    {
        prev=temp;
        temp=first;
        first=first->link;
    }
    void escape()
    {
        cout<<first->data<<" Escaped"<<endl;
    }
};

int main()
{
    int m,n,d,i;
    josephus li;
    cout <<"Enter total num of values : "<<endl;
    cin >>n;
    cout <<"enter nth value to delete : "<<endl;
    cin >>m;
    for(i=1;i<=n;i++)
    {
        cout <<"enter data :"<<endl;
        cin >>d;
        li.add(d);
    }
    li.display();
    li.start();
    while(li.length()>1)
    {
        for(i=1;i<=m;i++)
            li.next();
        cout <<li.rem()<<"deleted"<<endl;
    }
    li.escape();
    return 0;
}
