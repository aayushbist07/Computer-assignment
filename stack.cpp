#include<iostream>
using namespace std;

#define Max_size 5

template<class T>
class Stack
{
private:
    T arr[Max_size];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(T value)
    {
        if(top == Max_size - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = value;
        }
    }

    void pop()
    {
        if(top == -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Deleted Element = " << arr[top] << endl;
            top--;
        }
    }

    void display()
    {
        cout << "Stack Elements are:" << endl;
        if(top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack<int> s1;

    s1.pop();      // Underflow
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.display();

    s1.pop();

    s1.display();

    return 0;
}