
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ip[100];
int pos = 0;

void S();
void L();
void Lprime();

void error()
{
    printf("Syntax error and string not accepted!\n");
    exit(0);
}

void S()
{
    if (ip[pos] == '(')
    {
        pos++;
        L();

        if (ip[pos] == ')')
            pos++;
        else
            error();
    }
    else if (ip[pos] == 'a')
    {
        pos++;
    }
    else
    {
        error();
    }
}

void L()
{
    S();
    Lprime();
}

void Lprime()
{
    if (ip[pos] == ',')
    {
        pos++;
        S();
        Lprime();
    }
}

int main()
{
    printf("Enter string: ");
    scanf("%99s", ip);

    S();

    if (ip[pos] == '\0')
        printf("String is accepted\n");
    else
        error();

    return 0;
}
