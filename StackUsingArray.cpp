#include <iostream>
using namespace std;
const int MAX=5;
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
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
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
    return 0;
}
