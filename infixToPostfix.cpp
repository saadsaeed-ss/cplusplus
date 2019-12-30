#include <iostream>
#include <cstring>
using namespace std;

const int MAX=100;
bool prcd(char,char);
class Stack
{
private:
    char item[MAX];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    void push(char ch)
    {
        item[++top]=ch;
    }

    char pop()
    {
        return item[top--];
    }

    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    char stacktop()
    {
        return item[top];
    }
};

int main()
{
    Stack stk;
    string exp,post;
    cout<<"Enter the infix expression : ";
    cin>>exp;

    for(int i=0;i<exp.length();i++)
    {
       char symb=exp[i];
       if(symb>='A' && symb<='Z')
            post.append(1,symb);
       else
       {
           while(!stk.isempty()&& prcd(stk.stacktop(),symb))
           {
               char topstack=stk.pop();
               post.append(1,topstack);
           }
           if(stk.isempty() || symb!=')')
            stk.push(symb);
           else
            stk.pop();
       }
    }
    while(!stk.isempty())
       {
           char symba=stk.pop();
           post.append(1,symba);
       }

    cout<<"Your postfix stirng is : "<<post<<endl;
    return 0;
}

bool prcd(char top,char symb)
{
    if(top=='(' || symb=='(')
        return false;
    if(symb==')')
        return true;
    if(symb=='$')
        return false;
    if(top=='$')
        return true;
    if((top=='*' || top=='/') && (symb=='*' || symb=='/'))
        return true;
    if(symb=='+' || symb=='-')
        return true;
    else
        return false;
}
