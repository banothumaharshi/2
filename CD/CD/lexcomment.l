%{
    #include <stdio.h>
%}

%%
[/][/][a-zA-Z0-9]*
    {
        printf("%s", yytext);
    }

[a-zA-Z0-9]*
    {
        printf(" ");
    }

[/][*][a-zA-Z0-9]*[*][/]
    {
        printf("%s", yytext);
    }
%%

int main()
{
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}
Compilation:lex comments.l
            cc lex.yy.c -ll
            ./a.out
            Hello // world
            world
            hai /*friend*/
            friend
