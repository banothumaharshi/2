#include <stdio.h>

int main()
{
    char str[50];
    const char *keywords[] = {
        "if", "else", "while", "do", "switch",
        "case", "default", "continue", "return",
        "goto", "for", "break"};
    int n = sizeof(keywords) / sizeof(keywords[0]);
    int i, j, found = 0;
    printf("Enter a word: ");
    scanf("%49s", str);
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (str[j] == keywords[i][j] && str[j] != '\0')
            j++;
        if (str[j] == '\0' && keywords[i][j] == '\0')
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("%s is a flow control keyword\n", str);
    }
    else
    {
        if ((str[0] >= 'A' && str[0] <= 'Z') ||
            (str[0] >= 'a' && str[0] <= 'z') ||
            (str[0] == '_'))
        {

            found = 1;

            for (i = 1; str[i] != '\0'; i++)
            {
                if (!((str[i] >= 'A' && str[i] <= 'Z') ||
                      (str[i] >= 'a' && str[i] <= 'z') ||
                      (str[i] >= '0' && str[i] <= '9') ||
                      (str[i] == '_')))
                {
                    found = 0;
                    break;
                }
            }

            if (found)
                printf("\n%s is a valid identifier", str);
            else
                printf("\n%s is not a valid identifier", str);
        }
        else
        {
            printf("\n%s is not a valid identifier", str);
        }
    }

    return 0;
}