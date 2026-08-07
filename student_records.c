/* 
Student Records Management:
    Problem Statement:
        A coaching institute wants to store information about students.
    Each student has:
        ID
        Name
        Marks in Mathematics
        Marks in Physics
        Marks in Chemistry
    Your task is to:
        Create a structure to represent a student.
        Store information for 5 students.
        Calculate:
        Total marks
        Average marks
        Print the topper's details.
        Print all students who scored an average greater than 80.
        Restrictions
    You must use:
        Structures
        Arrays
        Functions
    You must not use:
        Dynamic memory
        File handling

    methods-> read input, valid marks, 
*/

#include <stdio.h>

#define MAX_COUNT 5

typedef struct{
    int maths;
    int physics;
    int chemistry;
} Marks;

typedef struct{
    int student_id;
    char student_name[50];
    Marks subject_marks;
    int total_marks;
} Students;

typedef struct{
    float average_marks;
    int highest_marks;
    int lowest_marks;
}ClassStatistics;

//function declarations.
void read_students(Students *s);
void print_students(Students *s);

    // void validate_marks(int marks);
void update_min_max_average_marks(Students *s, ClassStatistics *m);
void print_students_score(ClassStatistics m);

//function implementation.
void read_students(Students *s){
    
    for (int i=0; i<MAX_COUNT; i++){
        Students *current_student = s+i;
        printf("\nEnter student ID: ");
        scanf("%d", &current_student->student_id);
        
        printf("Enter student name: ");
        scanf(" %[^\n]s", current_student->student_name);

        printf("Enter marks in Maths: ");
        scanf("%d", &current_student->subject_marks.maths);
        printf("Enter marks in Physics: ");
        scanf("%d", &current_student->subject_marks.physics);
        printf("Enter marks in Chemistry: ");
        scanf("%d", &current_student->subject_marks.chemistry);
    }
}
void print_students(Students *s){
    for (int i=0; i<MAX_COUNT; i++){
        Students *current_student = s+i;
        printf("\nStudent ID is: %d\n", current_student->student_id);
        printf("Student Name is: %s\n", current_student->student_name);
        printf("Marks in Maths: %d\n", current_student->subject_marks.maths);
        printf("Marks in Physics: %d\n", current_student->subject_marks.physics);
        printf("Marks in Chemistry: %d\n", current_student->subject_marks.chemistry);
        printf("Total marks of %s : %d\n", current_student->student_name, current_student->total_marks);
    }
}

void update_min_max_average_marks(Students *s, ClassStatistics *m){
    int total = 0;
    int highest = 0;
    int lowest = 1000;

    for (int i=0; i<MAX_COUNT; i++){
        Students *current_student = s+i;
        current_student->total_marks = current_student->subject_marks.maths+current_student->subject_marks.physics+current_student->subject_marks.chemistry;
        total += current_student->total_marks;
        if(i==0){lowest = current_student->total_marks;}
        if(highest < current_student->total_marks){
            highest = current_student->total_marks;
        }if(lowest > current_student->total_marks){
            lowest = current_student->total_marks;
        }
    }

    m->highest_marks = highest;
    m->lowest_marks = lowest;
    m->average_marks = (float)total/MAX_COUNT;

}

void print_students_score(ClassStatistics m){
    printf(
        "\nHighest Marks: %d"
        "\nLowest Marks : %d"
        "\nClass Average  : %.2f\n",
        m.highest_marks,m.lowest_marks,m.average_marks
    );
}

int main(){
    Students student[MAX_COUNT];
    ClassStatistics class_marks;
    read_students(student);
    update_min_max_average_marks(student, &class_marks);
    print_students(student);
    print_students_score(class_marks);
    return 0;
}
