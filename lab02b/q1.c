// Program to store and print the name, ID, and age of a student using structure.

#include <stdio.h>
#include <string.h>
struct student {
    char name[50];
    int id;
    int age;
};

int main() {
    struct student s1;
    printf("Enter student name: ");
    // fgets is used so that space in the name can also be read
    fgets(s1.name, sizeof(s1.name), stdin);
    // To remove extra line that prints after student name because fgets also takes input of a new line
    s1.name[strcspn(s1.name, "\n")] = '\0';  
    printf("Enter student id: ");
    scanf("%d", &s1.id);
    printf("Enter student age: ");
    scanf("%d", &s1.age);

    printf("\nStudent name is %s\n", s1.name);
    printf("Student id is %d\n", s1.id);
    printf("Student age is %d\n", s1.age);

    return 0;
}
