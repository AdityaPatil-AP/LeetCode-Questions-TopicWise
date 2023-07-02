class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;
        int j = 0;
        bool goingDown = false;
        int i = 0;
        vector<string> ans(numRows);
        while (j < s.size())
        {
            if (i == 0 || i == numRows - 1)
            {
                goingDown = !goingDown;
            }

            ans[i] += s[j];

            j++;
            i += (goingDown) ? 1 : -1;
        }
        string answer = "";
        for (auto it : ans)
        {
            answer += it;
        }

        return answer;

        // Sort by Row...
        //         if(numRows == 1) return s;
        //         vector<string> storage(min(numRows, (int)s.size()));
        //         bool goingDown = false;
        //         int currRow = 0;
        //         for(char c : s){
        //             storage[currRow] += c;
        //             if(currRow == 0 || currRow == (numRows - 1)){
        //                 goingDown = !goingDown;
        //             }
        //             currRow += (goingDown) ? 1 : -1;
        //         }
        //         string res = "";
        //         for(auto row : storage){
        //             res += row;
        //         }

        //         return res;

        // Visit by Row..
        //         if(numRows == 1) return s;

        //         int cyclelen = (2 * numRows) - 2;
        //         int n = s.size();
        //         string res = "";

        //         for(int i = 0;i < numRows;i++){
        //             for(int j = 0;(j + i) < n;j += cyclelen){
        //                 res += s[j + i];
        //                 if(i != 0 && i != (numRows - 1) && (j + cyclelen - i) < n){
        //                     res += s[j + cyclelen - i];
        //                 }
        //             }
        //         }
        //         return res;
    }
};