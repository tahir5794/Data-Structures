#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{   //defining a structure of name student it will store each student's data
    char name[20];
    int roll;
    int obtained;
    int outof;
    float percent;
} student;
typedef struct
{   // defining a structure named subject which will represent as a award of each subject
    char subject[20]; // declaring a variable name which stores name of the subject.
    student students[2]; // declaring an array of structures of type student where each index will represent a student's data.
} subject;

void sort(subject arr[], int n);
void swap(student *students, student *largest);
void display(subject subjects[], int);
void input( subject subjects[], int n);
void search( subject subjects[], int n);

int main(void)
{
    int n = 2; // number of subjects

    subject subjects[n]; //declaring  array of structures of type subject where each index will represent a subject.

    input(subjects, n); //taking input details of students in different subjects.

    sort(subjects, n); // sorting the award of each subject as per students percentage
   
    display(subjects, n); // displaying each award

    search(subjects, n); // searching records of a specific student
}

void input(subject subjects[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Subject Name: ");
        scanf("%s", &subjects[i].subject);

        for (int j = 0; j < 2; j++)
        {
            printf("Name: ");
            scanf("%s", &subjects[i].students[j].name);
            printf("Roll Number: ");
            scanf("%i", &subjects[i].students[j].roll);
            printf("Marks Otained: ");
            scanf("%i", &subjects[i].students[j].obtained);
            printf("Total Marks: ");
            scanf("%i", &subjects[i].students[j].outof);
            subjects[i].students[j].percent = ((float) subjects[i].students[j].obtained / subjects[i].students[j].outof) * 100;
        }
    }

}

void sort(subject subjects[], int n)
{
    int largest_indx;
    for(int k = 0; k < n; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            largest_indx = i;
            for (int j = i + 1; j < 2; j++)
            {
                if (subjects[k].students[i].percent < subjects[k].students[j].percent && subjects[k].students[j].percent > subjects[k].students[largest_indx].percent)
                {
                    largest_indx = j;
                }
            }
            // swapping the Roll numbers as per percentage.
            int temp = subjects[k].students[i].roll;
            subjects[k].students[i].roll = subjects[k].students[largest_indx].roll;
            subjects[k].students[largest_indx].roll = temp;

            swap(&subjects[k].students[i], &subjects[k].students[largest_indx]);
        }
    }
}

void swap(student *students, student *largest)
{
    student temp = *students;
    *students = *largest;
    *largest = temp;
}

void display(subject subjects[], int n)
{
    for (int i = 0; i < n; i++)
    {   
        printf("\n\nSubject: %s\n\n", subjects[i].subject);
        printf("SNo. \t Name \t Roll No. \t Max Marks \t Obtained Marks \t Percentage\n\n");
        for(int j = 0; j < 2; j++)
        {
            printf("%i \t %s \t   %i \t\t   %i\t\t\t%i \t\t    %.2f%%\n", j + 1, subjects[i].students[j].name, subjects[j].students[j].roll, subjects[i].students[j].outof, subjects[i].students[j].obtained, subjects[i].students[j].percent);
        }
    }
}

void search(subject subjects[], int n)
{   
    char search[20];
    int search_indx, count = 0, t_obtained = 0, total = 0;
    float total_percent;

        printf("\nSEARCH RESULTS\n");
    printf("\nEnter a name: ");
    scanf("%s", &search);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(strcmp(subjects[i].students[j].name, search)==0)
            {   
                
                search_indx = j;
                if(count == 0)
                {
                    printf("\n\n=> Name: %s", subjects[i].students[j].name);
                    printf("\n=> Roll No.: %i", subjects[i].students[j].roll);
                    count++;
                }
                break;
                
            }
        }
        printf("\n=> %s: %i out of %i", subjects[i].subject, subjects[i].students[search_indx].obtained, subjects[i].students[search_indx].outof);
        t_obtained =t_obtained + subjects[i].students[search_indx].obtained;
        total = total + subjects[i].students[search_indx].outof;
    }
    total_percent = ((float) t_obtained / total) * 100;
    printf("\n=> Total: %i out of %i", t_obtained, total);
    printf("\n=> Total Percentage: %.2f %%", total_percent);

    if(total_percent >= 90)
    {
        printf("\n=> Remarks: Excellent! Keep it up.");
    }
    else if (total_percent < 90 && total_percent >= 75)
    {
        printf("\n=> Remarks: Very Good! You can do more better.");
    }
    else if (total_percent < 75 && total_percent >= 60)
    {
        printf("\n=> Remarks: Good! But needs to improve.");
    }
    else if (total_percent < 60 && total_percent >= 40)
    {
        printf("\n=> Remarks: Poor! Needs to work hard. ");
    }
    else
    {
        printf("\n=> Remarks: Fail! Try again.");
    }
}