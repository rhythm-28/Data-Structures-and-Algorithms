// Implement a stack class using 1 queue

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    public:
        queue<int> q;
    Stack() {}

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        while (size > 1)
        {
            int front = q.front();
            q.pop();
            q.push(front);
            size--;
        }
    }

    int pop()
    {
        int front = q.front();
        q.pop();
        return front;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

void input(Stack &s, int n)
{
    int d, i;
    for (i = 0; i < n; i++)
    {
        cin >> d;
        s.push(d);
    }
}

void print(Stack s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    Stack s;
    int n;
    cin >> n;
    input(s, n);
    print(s, n);
    return 0;
}