class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // Reverse Polish Notation -> Postfix Notation.
        int ans = 0;

        stack<int> st;
        vector<char> operators = {'/', '*', '+', '-'};

        for (int i = 0; i < tokens.size(); i++)
        {
            string curr = tokens[i];

            if (curr == "+" || curr == "/" || curr == "*" || curr == "-")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                if (curr == "+")
                    st.push(first + second);
                if (curr == "-")
                    st.push(first - second);
                if (curr == "/")
                    st.push(first / second);
                if (curr == "*")
                    st.push(first * second);
            }
            else
            {
                int cur = stoi(curr);
                st.push(cur);
            }
        }

        return st.top();
    }
};