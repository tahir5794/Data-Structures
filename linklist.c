#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} mynode;

int main(void)
{
    mynode *temp, *n, *list = NULL;
    int size;
    printf("Enter number of nodes you want: ");
    scanf("%i", &size); // Taking input the number of nodes we want in our linked list

    for (int i = 0; i < size; i++)
    {
        // Storing data in our a node and add that node to our linked list on each iteration of FOR loop.

        n = malloc(sizeof(mynode)); // Allocating memory to our node
        printf("Enter data in the node: ");
        scanf("%i", &n->data);
        n->next = NULL;
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            temp->next = n;
        }
        temp = n;
    }

    // PRINTING OUR LINKED LIST

    printf("\nElements in our Linked List are:\n");
    temp = list;
    while (temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->next;
    }

    free(n);
}