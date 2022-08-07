// To create a queue class using 1 stack

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> s;
    Queue() {}

    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int top = s.top();
        s.pop();
        push(x);
        s.push(top);
    }

    int pop()
    {
        int top = s.top();
        s.pop();
        return top;
    }

    int front()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
    }
};

void input(Queue &b, int n)
{
    int i, data;
    for (i = 0; i < n; i++)
    {
        cin >> data;
        b.push(data);
    }
}

void print(Queue b)
{
    while (!b.empty())
    {
        cout << b.front() << " ";
        b.pop();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    Queue b;
    input(b, n);
    print(b);
    return 0;
}