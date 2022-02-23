#include <stdio.h>
#include <conio.h>


int main(void)
{
    int num[5], i, smallest_indx;
    printf("Enter elements of array:\n");
    for(i=0; i < 5; i++)
    {   
        printf(" >>> ");
        scanf("%i", &num[i]);
    }
    printf("unsorted array: |");
    for(i=0; i<5; i++)
    {
        printf(" %i |", num[i]);
    }

    for (i = 0; i < 5; i++)
    {
        
        smallest_indx = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (num[i] > num[j] && num[j] < num[smallest_indx])
            {
                smallest_indx = j;
            }
        }

        int temp = num[i];
        num[i] = num[smallest_indx];
        num[smallest_indx] = temp;
    }

    printf("\nSorted array: |");
    for(i=0; i<5; i++)
    {
        printf(" %i |", num[i]);
    }

}
