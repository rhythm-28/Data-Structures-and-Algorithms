// To create a queue class using 2 stacks

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int top = s1.top();
        s1.pop();
        return top;
    }

    int front()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
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