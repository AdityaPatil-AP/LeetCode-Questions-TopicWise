class MyQueue
{
public:
    stack<int> st1, st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        int top = st1.top();
        st1.pop();

        return top;
    }

    int peek()
    {
        return st1.top();
    }

    bool empty()
    {
        return (st1.size() == 0);
    }
};

/**
 * @brief
 *
 */
// *MyQueue *obj = new MyQueue();
// *obj->push(x);
// *int param_2 = obj->pop();
// *int param_3 = obj->peek();
// *bool param_4 = obj->empty();
// * /

class MyQueue
{
public:
    stack<int> st1, st2;
    int front;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (st1.empty())
        {
            front = x;
        }
        st1.push(x);
    }

    int pop()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int curr = st2.top();
        st2.pop();
        return curr;
    }

    int peek()
    {
        if (!st2.empty())
        {
            return st2.top();
        }

        return front;
    }

    bool empty()
    {
        return (st1.size() == 0 && st2.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */