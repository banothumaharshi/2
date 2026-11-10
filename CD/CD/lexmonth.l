%{
    #include <stdio.h>
    int year;
    void leap();
%}

%%
jan|mar|may|july|aug|oct|dec
    {
        printf("31 days");
    }

april|june|sep|nov
    {
        printf("30 days");
    }

feb
    {
        leap();
    }

[a-zA-Z]*
    {
        printf("invalid");
    }
%%

int main()
{
    yylex();
    return 0;
}

void leap()
{
    printf("Enter year: ");
    scanf("%d", &year);

    if (year % 4 == 0)
        printf("29 days");
    else
        printf("28 days");
}

int yywrap()
{
    return 1;
}

Compilation:lex daysinamonth.l
            cc lex.yy.c -ll
            ./a.out
            jan
            31 days
            june
            30 days
            feb
            enter year 
            1984 
            29 days
