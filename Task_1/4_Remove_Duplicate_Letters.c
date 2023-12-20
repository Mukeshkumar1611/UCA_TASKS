char* removeDuplicateLetters(char* s)
{
    int len = strlen(s);
    int freq[26] = {0};
    int vis[26] = {0};
    int count = 0;

    for(int i = 0; i < len; i++)
    {
        freq[s[i] - 'a']++;
        if(freq[s[i] - 'a'] == 1)
        {
            count++;
        }
    }
    
    char *ans = malloc(sizeof(char) * (count+2));
    ans[count+1] = '\0';
    ans[0] = '0';

    int i = 0;
    int j = 0;
    while(s[i] != '\0')
    {
        char ch = s[i];
        freq[ch - 'a']--;
        if(vis[ch - 'a'] == 1)
        {
            i++;
            continue;
        }

        while((ch < ans[j]) && (freq[ans[j] - 'a']))
        {
            vis[ans[j] - 'a'] = 0;    
            j--;
        }
        ans[j + 1] = ch;
        vis[ch - 'a'] = 1;
        j++;
        i++;
    }
    return (&ans[1]);
}
