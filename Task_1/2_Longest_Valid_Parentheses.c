int length(char *s)
{
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int longestValidParentheses(char* s) 
{
    int size = length(s);
    int ans = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i < size; i++)
    {
        if(s[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if(left == right)
        {
            if((2 * left ) > ans)
            {
                ans = 2 * left;
            }
        }
        else if(right > left)
        {
            left = 0;
            right = 0;
        }
    }    
    left = 0;
    right = 0;

    for(int i = size - 1; i >= 0; i--)
    {
        if(s[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if(left == right)
        {
            if((2 * left) > ans)
            {
                ans = 2 * left;
            }
        }
        if(left > right)
        {
            left = 0;
            right = 0;
        }
    } 
    return ans;
}