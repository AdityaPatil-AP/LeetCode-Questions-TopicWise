class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
               
        unordered_set<string> myset(bank.begin(), bank.end());
        
        if(myset.count(end) == 0)
            return -1;
        
        queue<string> q;
        
        q.push(start);
        
        int steps = 0;
        
        while(q.empty() == false)
        {
            int size = q.size();
            
            while(size--)
            {
                string curr = q.front();
                
                q.pop();
                
                if(curr == end)
                    return steps;
                
                myset.erase(curr);
                
                for(int i = 0; i < 8; i++)
                {
                    string temp = curr;
                    
                    temp[i] = 'A';
                    
                    if(myset.count(temp))
                        q.push(temp);
                    
                    temp[i] = 'C';
                    
                    if(myset.count(temp))
                        q.push(temp);
                    
                    temp[i] = 'G';
                    
                    if(myset.count(temp))
                        q.push(temp);
                    
                    temp[i] = 'T';
                    
                    if(myset.count(temp))
                        q.push(temp);
                }
            }
            
            steps++;
        }
        
        return -1;
    
    }
};