%{
    #include <stdio.h>
%}
%%
If|else|while|do|switch|case|break|for|default
    {
        printf("Keyword");
    }
IF|ELSE|WHILE|DO|SWITCH|CASE|BREAK|FOR|DEFAULT
    {
        printf("Keyword");
    }
[A-Za-z]+[A-Za-z0-9_]*
    {
        printf("Identifier");
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

Compilation:
lex lexanalysis.l
        cc lex.yy.c -
    ll
            ./
        a.out
            If
                Keyword
                    FOR
                        Keyword
                            Abc123_def identifier
