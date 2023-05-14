#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

typedef struct {
    char name[50];
    int roll_number;
    int marks[MAX_SUBJECTS];
    char grade;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student newStudent;

    printf("Enter name: ");
    scanf("%s", newStudent.name);

    printf("Enter roll number: ");
    scanf("%d", &newStudent.roll_number);

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &newStudent.marks[i]);
    }

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully.\n");
}

void calculateGrade(Student *student) {
    int totalMarks = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        totalMarks += student->marks[i];
    }

    float percentage = (float) totalMarks / MAX_SUBJECTS;

    if (percentage >= 90) {
        student->grade = 'A';
    } else if (percentage >= 80) {
        student->grade = 'B';
    } else if (percentage >= 70) {
        student->grade = 'C';
    } else if (percentage >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

void displayStudentInfo(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_number);

    printf("Marks: ");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("%d ", student->marks[i]);
    }
    printf("\n");

    printf("Grade: %c\n", student->grade);
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int rollNumber;
    int choice;
    while(choice != 4)
    {
        printf("\n-- Student Management System --\n");
        printf("1. Add Student\n");
        printf("2. Calculate Grades\n");
        printf("3. Display Student Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                for (int i = 0; i < studentCount; i++) {
                    calculateGrade(&students[i]);
                }
                printf("Grades calculated successfully.\n");
                break;
            case 3:
                
                printf("Enter roll number: ");
                scanf("%d", &rollNumber);

                int found = 0;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].roll_number == rollNumber) {
                        displayStudentInfo(&students[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
    
