#define SIZE 10

struct Stack
{
    int *arr;
    int size;
    int top;
};

void createStack(struct Stack *stk)
{
    stk->arr = (int*)malloc(SIZE * sizeof(int));
    stk->top = -1;
    stk->size = SIZE;
}

void push(struct Stack *stk, int ele)
{
    if((stk->size - 1) == stk->top)
    {
        stk->size = stk->size * 2;
        stk->arr = (int*)realloc(stk->arr, stk->size * sizeof(int));
    }
    ++stk->top;
    stk->arr[stk->top] = ele;
}

void pop(struct Stack *stk)
{
    if(stk->top == -1)
    {
        return;
    }
    stk->top--;
}

int top(struct Stack *stk)
{
    if(stk->top != -1)
    {
        return stk->arr[stk->top];
    }
    return -1;
}

int empty(struct Stack *stk)
{
    if(stk->top == -1) return 1;
    return 0;
}

int findLength(char *s)
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
    int size = findLength(s);  
    struct Stack stk;
    createStack(&stk);
    int ans = 0;
    push(&stk, -1);

    for(int i = 0; i < size; i++)
    {
        if(s[i] == '(')
        {
            push(&stk, i);
        }
        else
        {
            if(empty(&stk) == 0)
            {
                pop(&stk);
            }
            if(empty(&stk) == 0)
            {
                int currAns = i - top(&stk);
                if(currAns > ans)
                {
                    ans = currAns;
                }
            }
            else
            {
                push(&stk, i);
            }
        }
    }  
    return ans;
}