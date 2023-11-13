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

    // Input data for the student
    printf("Enter student name: ");
    scanf("%s", student1.name);

    printf("Enter class number: ");
    scanf("%d", &student1.classNumber);

    printf("Enter section: ");
    scanf(" %c", &student1.section);

    // Displaying entered information
    printf("\nStudent Information:\n");
    printf("Name: %s\n", student1.name);
    printf("Class: %d\n", student1.classNumber);
    printf("Section: %c\n", student1.section);

    return 0;
}
