class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        int i = 0;
        int j = 0;    
        unordered_map<int, int> mpp;
        int ans = 0;

        while(j < n)
        {
            if(mpp.find(s[j]) == mpp.end())
            {
                mpp[s[j]]++;
                ans = max(ans, j - i + 1);
            }
            else
            {
                while(mpp.find(s[j]) != mpp.end())
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0)
                    {
                        mpp.erase(s[i]);
                    }
                    i++;
                    if(mpp.find(s[j]) == mpp.end())
                    {
                        mpp[s[j]]++;
                        ans = max(ans, j - i + 1);
                        break;
                    }
                }
            }
            j++;
        }
        return ans;
    }
};