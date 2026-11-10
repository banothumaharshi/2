% {
    #include <stdio.h>
% }

% % 
"+"?[0-9]+
    {
        printf("%s: positive integers", yytext);
    }

-[0-9]+
    {
        printf("%s: negative integers", yytext);
    }

-[0-9]+\.[0-9]+
    {
        printf("%s: negative real numbers", yytext);
    }

"+"?[0-9]+\.[0-9]+
{
    printf("%s: positive real numbers", yytext);
}
% %

    int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

Compilation:lex noformat.l
            cc lex.yy.c -ll
            ./a.out 
            24 positive integer 
            +24.12 positive real number 
            -24 negative integer 
            -24.12 negative real number