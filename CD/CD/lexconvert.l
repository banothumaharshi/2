%{
#include <stdio.h>
#include <string.h>
%}

%%
[0-9]*\.[0-9]+
{
    char *p = strchr(yytext, '.');
    *p = '\0';
    printf("Integer part: %s\n", yytext);
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