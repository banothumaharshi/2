
#include <stdio.h>
#include <string.h>

#define MAX 100

int action[12][6] = {
    {5, 0, 0, 4, 0, 0},
    {0, 6, 0, 0, 0, 999},
    {0, -2, 7, 0, -2, -2},
    {0, -4, -4, 0, -4, -4},
    {5, 0, 0, 4, 0, 0},
    {0, -6, -6, 0, -6, -6},
    {5, 0, 0, 4, 0, 0},
    {5, 0, 0, 4, 0, 0},
    {0, 6, 0, 0, 11, 0},
    {0, -1, 7, 0, -1, -1},
    {0, -3, -3, 0, -3, -3},
    {0, -5, -5, 0, -5, -5}
};

int gotot[12][3] = {
    {1, 2, 3},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1},
    {8, 2, 3},
    {-1, -1, -1},
    {-1, 9, 3},
    {-1, -1, 10},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}
};

int getcol(char *c)
{
    if (strcmp(c, "id") == 0)
        return 0;
    if (strcmp(c, "+") == 0)
        return 1;
    if (strcmp(c, "*") == 0)
        return 2;
    if (strcmp(c, "(") == 0)
        return 3;
    if (strcmp(c, ")") == 0)
        return 4;
    if (strcmp(c, "$") == 0)
        return 5;

    return -1;
}

int gotocol(char c)
{
    if (c == 'E')
        return 0;
    if (c == 'T')
        return 1;
    if (c == 'F')
        return 2;

    return -1;
}

void print(int st[], char symbol[], int top)
{
    int i;

    for (i = 0; i <= top; i++)
        printf("%c%d ", symbol[i], st[i]);
}

void printprod(int r)
{
    switch (r)
    {
    case 1:
        printf("Reduce E -> E+T");
        break;

    case 2:
        printf("Reduce E -> T");
        break;

    case 3:
        printf("Reduce T -> T*F");
        break;

    case 4:
        printf("Reduce T -> F");
        break;

    case 5:
        printf("Reduce F -> (E)");
        break;

    case 6:
        printf("Reduce F -> id");
        break;
    }
}

int main()
{
    char input[MAX][10];
    char symbol[MAX];
    int st[MAX];
    int n, i;
    int top = 0;

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX)
    {
        printf("Invalid number of tokens!\n");
        return 1;
    }

    printf("Enter tokens (id, +, *, (, )):\n");

    for (i = 0; i < n; i++)
        scanf("%9s", input[i]);

    strcpy(input[n], "$");

    st[0] = 0;
    symbol[0] = '$';

    i = 0;

    printf("\n%-20s %-15s %s\n",
           "Stack", "Input", "Action");

    while (1)
    {
        int state = st[top];
        int col = getcol(input[i]);
        int act;

        if (col == -1)
        {
            printf("Invalid input\n");
            break;
        }

        act = action[state][col];

        print(st, symbol, top);
        printf("%-15s %-15s ", "", input[i]);

        if (act == 0)
        {
            printf("String Rejected\n");
            break;
        }

        if (act == 999)
        {
            printf("String Accepted\n");
            break;
        }

        if (act > 0)
        {
            printf("Shift %d\n", act);

            top++;
            st[top] = act;
            symbol[top] = input[i][0];

            i++;
        }
        else
        {
            int r = -act;
            int lhs;
            int rhslen;
            int pre;

            printprod(r);
            printf("\n");

            if (r == 1)
            {
                lhs = 0;
                rhslen = 3;
            }
            else if (r == 2)
            {
                lhs = 0;
                rhslen = 1;
            }
            else if (r == 3)
            {
                lhs = 1;
                rhslen = 3;
            }
            else if (r == 4)
            {
                lhs = 1;
                rhslen = 1;
            }
            else if (r == 5)
            {
                lhs = 2;
                rhslen = 3;
            }
            else
            {
                lhs = 2;
                rhslen = 1;
            }

            top = top - rhslen;

            pre = st[top];

            top++;
            st[top] = gotot[pre][lhs];

            if (lhs == 0)
                symbol[top] = 'E';
            else if (lhs == 1)
                symbol[top] = 'T';
            else
                symbol[top] = 'F';
        }
    }

    return 0;
}
