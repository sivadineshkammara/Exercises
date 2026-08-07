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
// #define AVERAGE_MARKS 80 // for now I'm using total score/no.of students for average marks.

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
} Student;

typedef struct{
    float average_marks;
    int highest_marks;
    int lowest_marks;
}ClassStatistics;


//function declarations.
void read_students(Student *s);
void print_students(Student *s);

void validate_marks(int marks);
void validate_student_id(int id);
int find_topper(Student *s);

void operations_on_marks(Student *s, ClassStatistics *m);
float calculate_average(Student *s);
int find_highest_marks(Student *s);
int find_lowest_marks(Student *s);
void print_classStatics(ClassStatistics m, Student *s);

//operations on student records.
void validate_marks(int marks){
    if (marks<0 || marks>100){
        printf("Invalid Marks!!\n");
        return;
    }
}

void validate_student_id(int id){
    if (id<0){
        printf("Invalid Student ID!!\n");
        return;
    }
}

int find_topper(Student *s){
    int topper_index = 0;
    for (int i=1; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        if (current_student->total_marks > s[topper_index].total_marks){
            topper_index = i;
        }
    }
    return topper_index;
}

//function implementation.
void read_students(Student *s){
    
    for (int i=0; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        printf("\nEnter student ID: ");
        scanf("%d", &current_student->student_id);
        validate_student_id(current_student->student_id);

        printf("Enter student name: ");
        scanf(" %[^\n]s", current_student->student_name);

        printf("Enter marks in Maths: ");
        scanf("%d", &current_student->subject_marks.maths);
        validate_marks(current_student->subject_marks.maths);
        printf("Enter marks in Physics: ");
        scanf("%d", &current_student->subject_marks.physics);
        validate_marks(current_student->subject_marks.physics);
        printf("Enter marks in Chemistry: ");
        scanf("%d", &current_student->subject_marks.chemistry);
        validate_marks(current_student->subject_marks.chemistry);
    }
}
void print_students(Student *s){
    for (int i=0; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        printf("\nStudent ID is: %d\n", current_student->student_id);
        printf("Student Name is: %s\n", current_student->student_name);
        printf("Marks in Maths: %d\n", current_student->subject_marks.maths);
        printf("Marks in Physics: %d\n", current_student->subject_marks.physics);
        printf("Marks in Chemistry: %d\n", current_student->subject_marks.chemistry);
        printf("Total marks of %s : %d\n", current_student->student_name, current_student->total_marks);
    }
}

float calculate_average(Student *s){
    int total = 0;
    for (int i=0; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        current_student->total_marks = current_student->subject_marks.maths+current_student->subject_marks.physics+current_student->subject_marks.chemistry;
        total += current_student->total_marks;
    }

    return (float)total/MAX_COUNT;

}
int find_highest_marks(Student *s){
    int highest = s->total_marks;

    for (int i=1; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        if(highest < current_student->total_marks){
            highest = current_student->total_marks;
        }
    }

    return highest;
}
int find_lowest_marks(Student *s){
    int lowest = s->total_marks;

    for (int i=1; i<MAX_COUNT; i++){
        Student *current_student = s+i;
        if(lowest > current_student->total_marks){
            lowest = current_student->total_marks;
        }
    }

    return lowest;
}

void operations_on_marks(Student *s, ClassStatistics *m){
    m->average_marks = calculate_average(s);
    m->highest_marks = find_highest_marks(s);
    m->lowest_marks = find_lowest_marks(s);
}

void print_classStatics(ClassStatistics m, Student *s){
    printf(
        "\nHighest Marks: %d"
        "\nLowest Marks : %d"
        "\nClass Average  : %.2f\n",
        m.highest_marks,m.lowest_marks,m.average_marks
    );

    printf("\nNames of all Students who scored more than average marks: \n");
    for (int i=0; i<MAX_COUNT; i++){
        Student *current = s+i;
        if((float)current->total_marks > m.average_marks){
            printf("=> %s\n", (s+i)->student_name);
        }
    }
}

int main(){
    Student student[MAX_COUNT];
    ClassStatistics class_marks;
    
    read_students(student);
    operations_on_marks(student, &class_marks);
    // print_students(student);
    int topper_index = find_topper(student);
    
    printf(
        "\nTopper of the class is %s with %d total marks.\n", 
        student[topper_index].student_name, student[topper_index].total_marks
    );
    print_classStatics(class_marks, student);
    return 0;
}
