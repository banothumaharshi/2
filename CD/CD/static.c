#include <stdio.h>

int x = 10;
static int y = 20;

int main()
{
    static int z = 30;

    printf("%d %d %d\n", x, y, z);

    return 0;
}