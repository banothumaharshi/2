#include <stdio.h>
#include <stdlib.h>

struct Block
{
    int size, free;
    struct Block *next;
};

int main()
{
    int n, i, choice, p, found;
    struct Block *head = NULL, *temp, *prev, *best;

    printf("Enter total number of memory blocks: ");
    scanf("%d", &n);

    // Create heap blocks dynamically
    for (i = 0; i < n; i++)
    {
        temp = (struct Block *)malloc(sizeof(struct Block));

        printf("Enter block size: ");
        scanf("%d", &temp->size);

        temp->free = 1;
        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else
            prev->next = temp;

        prev = temp;
    }

    printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++)
    {
        int size;
        printf("\nEnter process size: ");
        scanf("%d", &size);

        temp = head;
        best = NULL;
        found = 0;

        while (temp != NULL)
        {
            if (temp->free && temp->size >= size)
            {

                if (choice == 1)
                {
                    best = temp;
                    break;
                }

                if (choice == 2 &&
                    (best == NULL || temp->size < best->size))
                    best = temp;

                if (choice == 3 &&
                    (best == NULL || temp->size > best->size))
                    best = temp;
            }
            temp = temp->next;
        }

        if (best != NULL)
        {
            best->free = 0;
            found = 1;
            printf("Process %d allocated to block of size %d\n",
                   i + 1, best->size);
        }

        if (!found)
            printf("Process %d cannot be allocated\n", i + 1);
    }

    printf("\nFinal Heap Memory Status:\n");

    temp = head;
    i = 1;

    while (temp != NULL)
    {
        printf("Block %d: Size = %d, Status = %s\n",
               i++, temp->size,
               temp->free ? "Free" : "Allocated");

        temp = temp->next;
    }

    // Release dynamically allocated heap blocks
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}