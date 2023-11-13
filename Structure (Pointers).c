#include <stdio.h>

// Define the structure
struct Student {
    char name[50];
    int classNumber;
    char section;
};

int main() {
    // Create an instance of the structure
    struct Student student1;

    // Create pointers to access the structure members
    char *namePtr = student1.name;
    int *classNumberPtr = &student1.classNumber;
    char *sectionPtr = &student1.section;

    // Input data for the student using pointers
    printf("Enter student name: ");
    scanf("%s", namePtr);

    printf("Enter class number: ");
    scanf("%d", classNumberPtr);

    printf("Enter section: ");
    scanf(" %c", sectionPtr);

    // Displaying entered information using pointers
    printf("\nStudent Information:\n");
    printf("Name: %s\n", namePtr);
    printf("Class: %d\n", *classNumberPtr);
    printf("Section: %c\n", *sectionPtr);

    return 0;
}
