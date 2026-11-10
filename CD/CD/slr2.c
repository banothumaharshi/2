
#include <stdio.h>
#include <string.h>

#define MAX 100

int action[6][3] = {
    {3, -3, -3},
    {0, 0, 999},
    {0, 5, -5},
    {0, -2, -2},
    {0, 0, -1},
    {0, 0, -4}};

int gotot[6][3] = {
    {1, 2, 0},
    {0, 0, 0},
    {0, 0, 4},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

int getcol(char c)
{
    if (c == 'a')
        return 0;
    if (c == 'b')
        return 1;
    if (c == '$')
        return 2;

    return -1;
}

void print(int st[], int top)
{
    int i;

    for (i = 0; i <= top; i++)
        printf("%d", st[i]);
}

void printprod(int r)
{
    switch (r)
    {
    case 1:
        printf("Reduce S -> AB");
        break;

    case 2:
        printf("Reduce A -> a");
        break;

    case 3:
        printf("Reduce A -> epsilon");
        break;

    case 4:
        printf("Reduce B -> b");
        break;

    case 5:
        printf("Reduce B -> epsilon");
        break;
    }
}

int main()
{
    char in[MAX] = "ab$";
    int st[MAX];
    int top = 0;
    int ip = 0;

    st[0] = 0;

    printf("Input: %s\n\n", in);
    printf("%-20s %-15s %s\n",
           "Stack", "Input", "Action");

    while (1)
    {
        int state;
        int col;
        int act;

        state = st[top];
        col = getcol(in[ip]);

        if (col == -1)
        {
            printf("Invalid input\n");
            return 0;
        }

        act = action[state][col];

        print(st, top);
        printf("%-15s %-15s ",
               "", in + ip);

        if (act == 0)
        {
            printf("Error\n");
            break;
        }

        if (act == 999)
        {
            printf("String accepted\n");
            break;
        }

        if (act > 0)
        {
            printf("Shift %d\n", act);

            top++;
            st[top] = act;
            ip++;
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
                rhslen = 2;
            }
            else if (r == 2)
            {
                lhs = 1;
                rhslen = 1;
            }
            else if (r == 3)
            {
                lhs = 1;
                rhslen = 0;
            }
            else if (r == 4)
            {
                lhs = 2;
                rhslen = 1;
            }
            else
            {
                lhs = 2;
                rhslen = 0;
            }

            top = top - rhslen;
            pre = st[top];

            top++;
            st[top] = gotot[pre][lhs];
        }
    }

    return 0;
}
