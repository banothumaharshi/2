%{
    #include <stdio.h>
    void units();
%}

% %
20 / [0 - 9] printf("Twenty");
30 / [0 - 9] printf("Thirty");
40 / [0 - 9] printf("Forty");
50 / [0 - 9] printf("Fifty");
60 / [0 - 9] printf("Sixty");
70 / [0 - 9] printf("Seventy");
80 / [0 - 9] printf("Eighty");
90 / [0 - 9] printf("Ninety");

10 printf("Ten");
11 printf("Eleven");
12 printf("Twelve");
13 printf("Thirteen");
15 printf("Fifteen");

1 [46789]
{
    units();
    printf("teen");
}

[1 - 9] units();
0 printf("Zero");
% %

void units()
{
    switch (yytext[yyleng - 1]) {
        case '1':
            printf("One");
            break;
        case '2':
            printf("Two");
            break;
        case '3':
            printf("Three");
            break;
        case '4':
            printf("Four");
            break;

        case '5':
            printf("Five");
            break;

        case '6':
            printf("Six");
            break;

        case '7':
            printf("Seven");
            break;

        case '8':
            printf("Eight");
            break;

        case '9':
            printf("Nine");
            break;
    }
}

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}