#define SIZE 10

struct Stack 
{
    char *arr;
    int top;
    int size;
};

void createStack(struct Stack *stack)
{
    stack->arr = (char *)malloc(SIZE * sizeof(char));
    stack->top = -1;
    stack->size = SIZE;
}

int isEmpty(struct Stack *stk) 
{
    return (stk->top == -1);
}

void push(struct Stack *stack, char element) 
{
    if ((stack->top) == (stack->size - 1)) 
    {
        stack->size = stack->size * 2;
        stack->arr = (char *)realloc(stack->arr, stack->size * sizeof(char));
    }

    stack->top++;
    stack->arr[stack->top] = element;
}

void pop(struct Stack *stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stack is empty.");
    }
    else 
    {
        // printf("Popped", stack->arr[stack->top]);
        stack->top--;
    }
}

char top(struct Stack *stack) 
{
    if (isEmpty(stack)) 
    {
        return -1;
    } 
    return (stack->arr[stack->top]);
}

bool isValid(char* s) 
{
    struct Stack myStack;
    createStack(&myStack);

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(&myStack, s[i]);
        }
        else
        {
            if(isEmpty(&myStack)) 
            {
                return false;
            }
            else
            {
                if((s[i] == ')' && top(&myStack) == '(') || (s[i] == '}' && top(&myStack) == '{') 
                || (s[i] == ']' && top(&myStack) == '['))
                {
                    pop(&myStack);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(isEmpty(&myStack) == 0) 
    {
        return false;
    }
    return true;
}