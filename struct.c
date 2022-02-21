#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct {
    string name;
    int id;
    long mobile;
    string email;
    string courses[2];
} canditates;


int main(void) {
    canditates canditate[2];
    int i,j;
    string query;

    for(i=0;i<2;i++)
    {
        canditate[i].name = get_string("Name: ");
        canditate[i].id = get_int("ID: ");
        canditate[i].mobile = get_long("Mobile: ");
        canditate[i].email = get_string("E-mail: ");

        for(j=0;j<2;j++)
        {
            canditate[i].courses[j] = get_string("Enter your Course: ");
        }
    }

    printf("Entered details are: \n");

    for(i=0;i<2;i++)
    {
        printf("%i ", i+1);
        printf("\t Name: %s\n", canditate[i].name);
        printf("\t ID: %i\n", canditate[i].id);
        printf("\t Mobile: %li\n", canditate[i].mobile);
        printf("\t E-mail: %s\n", canditate[i].email);

        printf("\t Courses: \n");
        for(j=0;j<2;j++)
        {
            printf("\t -> %s\n",canditate[i].courses[j]);
        }
    }
    
    query = get_string("Enter a name to search: ");
    
    
    
}