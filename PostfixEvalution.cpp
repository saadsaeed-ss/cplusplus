#include <iostream>
#include <cstring>
//#include <cmath>
using namespace std;
int calc(int,int,char);

const int MAX=50;

class Stack
{
private:
    int items[MAX];
    int top;
public:
    Stack()
    {
      top=-1;
    }
    void push(int val)
    {
        items[++top]=val;
    }
    int pop()
    {
        return items[top--];
    }

};
int main()
{
    Stack stk;
    string post;
    cout<<"Enter the postfix Exp : ";
    cin>>post;
    int i,op1,op2,res;
    char symb;
    for(i=0;i<post.length();i++)
    {
        symb=post[i];
        if(symb>='0' && symb<='9')
            stk.push(symb-'0');
        else
        {
            op2=stk.pop();
            op1=stk.pop();
            res=calc(op1,op2,symb);
            stk.push(res);
        }
    }
    cout<<"Result = "<<stk.pop()<<endl;
    return 0;
}

int calc(int op1,int op2, char op)
{
    int power(int,int);
    switch(op)
    {
    case'+':
        return op1+op2;
        break;
    case'-':
        return op1-op2;
        break;
    case'*':
        return op1*op2;
        break;
    case'/':
        return op1/op2;
        break;
    case'$':
        return power(op1,op2);
        break;
    default:
        cout<<"Wrong input"<<endl;
    }
}

int power(int op1,int op2)
    {
        int ans =1;
        for(int i=0;i<op2;i++)
        {
            ans=ans*op1;
        }

            return ans;
    }
