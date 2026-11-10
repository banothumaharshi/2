
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ip[100];
int pos = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void error()
{
    printf("Syntax error at position %d\n", pos);
    exit(1);
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (ip[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (ip[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if (ip[pos] == '(')
    {
        pos++;
        E();

        if (ip[pos] == ')')
            pos++;
        else
            error();
    }
    else if (isalpha((unsigned char)ip[pos]))
    {
        pos++;

        while (isalnum((unsigned char)ip[pos]))
            pos++;
    }
    else
    {
        error();
    }
}

int main()
{
    printf("Enter a string: ");
    scanf("%99s", ip);

    E();

    if (ip[pos] == '\0')
        printf("String accepted\n");
    else
        error();

    return 0;
}
