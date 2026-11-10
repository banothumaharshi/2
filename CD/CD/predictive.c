#include <stdio.h>

char stack[100];
char input[100];
int top = -1, ip = 0;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

void firstfollow()
{
    printf("First(E) = { (, id }\n");
    printf("First(Q) = { +, e }\n");
    printf("First(T) = { (, id }\n");
    printf("First(R) = { *, e }\n");
    printf("First(F) = { (, id }\n");
}

int col(char ch)
{
    switch (ch)
    {
    case 'i':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    case '(':
        return 3;
    case ')':
        return 4;
    case '$':
        return 5;
    }
    return -1;
}

int row(char ch)
{
    switch (ch)
    {
    case 'E':
        return 0;
    case 'Q':
        return 1;
    case 'T':
        return 2;
    case 'R':
        return 3;
    case 'F':
        return 4;
    }
    return -1;
}

char *table[5][6] =
    {
        {"TQ", "", "", "TQ", "", ""},
        {"", "+TQ", "", "", "#", "#"},
        {"FR", "", "", "FR", "", ""},
        {"", "#", "*FR", "", "#", "#"},
        {"i", "", "", "(E)", "", ""}};

int main()
{
    int j;

    printf("Enter input ending with $: ");
    scanf("%99s", input);

    push('$');
    push('E');

    while (peek() != '$')
    {
        char x = peek();
        char a = input[ip];

        if (x == a)
        {
            pop();
            ip++;
        }
        else if (x >= 'A' && x <= 'Z')
        {
            int r = row(x);
            int c = col(a);

            if (r == -1 || c == -1 || table[r][c][0] == '\0')
            {
                printf("Invalid string\n");
                return 0;
            }

            pop();

            if (table[r][c][0] != '#')
            {
                int len = 0;

                while (table[r][c][len] != '\0')
                    len++;

                for (j = len - 1; j >= 0; j--)
                    push(table[r][c][j]);
            }
        }
        else
        {
            printf("\nInvalid string\n");
            return 0;
        }
    }

    if (input[ip] == '$')
        printf("\nValid string");
    else
        printf("\nInvalid string");

    return 0;
}