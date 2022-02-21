#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(void)
{
    int num[5], i, selected, smallest, index;
    num[0] = 12;
    num[1] = 15;
    num[2] = 5;
    num[3] = 0;
    num[4] = 1;

    printf("unsorted array: |");
    for(i=0; i<5; i++)
    {
        printf("  %i |", num[i]);
    }

    for (i = 0; i < 5; i++)
    {
        selected = num[i];
        smallest = selected;
        index = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (selected < num[j])
            {
                continue;
            }
            else if (selected > num[j] && num[j] < smallest)
            {
                smallest = num[j];
                index = j;
            }
            else
            {
                continue;
            }
        }

        int temp = num[i];
        num[i] = smallest;
        num[index] = temp;
    }

    printf("\nSorted array: |");
    for(i=0; i<5; i++)
    {
        printf(" %i |", num[i]);
    }

}
