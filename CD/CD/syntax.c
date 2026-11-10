
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char op, name[20], temp[20];
    struct node *l, *r;
};

char s[100];
int p = 0, count = 0;

struct node *create(char op, char *name, struct node *l, struct node *r)
{
    struct node *n = calloc(1, sizeof(struct node));
    n->op = op;
    if (name)
        strcpy(n->name, name);
    n->l = l;
    n->r = r;
    return n;
}

struct node *expr();

struct node *factor()
{
    while (s[p] == ' ')
        p++;

    if (s[p] == '-')
    {
        p++;
        return create('~', NULL, factor(), NULL);
    }

    if (s[p] == '(')
    {
        p++;
        struct node *n = expr();
        p++;
        return n;
    }

    char a[20];
    int i = 0;
    while (isalnum(s[p]) || s[p] == '_')
        a[i++] = s[p++];
    a[i] = '\0';

    return create(0, a, NULL, NULL);
}

struct node *term()
{
    struct node *n = factor();
    while (s[p] == '*' || s[p] == '/')
    {
        char op = s[p++];
        n = create(op, NULL, n, factor());
    }
    return n;
}

struct node *expr()
{
    struct node *n = term();
    while (s[p] == '+' || s[p] == '-')
    {
        char op = s[p++];
        n = create(op, NULL, n, term());
    }
    return n;
}

char *generate(struct node *n)
{
    if (!n->op)
        return n->name;

    char a[20], b[20], t[20];
    strcpy(a, generate(n->l));

    if (n->op == '~')
        sprintf(t, "t%d", ++count),
            printf("%s = -%s\n", t, a);
    else
    {
        strcpy(b, generate(n->r));
        sprintf(t, "t%d", ++count);
        printf("%s = %s %c %s\n", t, a, n->op, b);
    }

    strcpy(n->temp, t);
    return n->temp;
}

int main()
{
    char lhs[20];
    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);

    char *eq = strchr(s, '=');
    if (!eq)
        return printf("Invalid expression\n"), 0;

    strncpy(lhs, s, eq - s);
    lhs[eq - s] = '\0';
    p = eq - s + 1;

    struct node *root = expr();

    printf("\nThree Address Code:\n");
    printf("%s = %s\n", lhs, generate(root));
    return 0;
}
