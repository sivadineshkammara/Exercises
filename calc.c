/*
 For refreshing of C Im writing a program that does.
  Calculator using +, -, *, /, %.
  Celsius to Fahrenheit converter.
  Fahrenheit to Celsius converter.
  Area of a square.
  Area of a rectangle.
  Area of a triangle.
  Area of a circle.
*/

/*formulas:
    Celsius to Fahrenheit: (C * 9/5) + 32
    Fahrenheit to Celsius: (F - 32) * 5/9
    Area of Square: side * side
    Area of Rectangle: length * breadth
    Area of Triangle: (base * height)/2
    Area of Circle: pi * radius * radius
    celcius to fahrenheit = (c*9/5)+32
    fahrenheit to celcius = (F-32)*5/9
*/

#include<stdio.h>

//Functions proto-types:
void calculator(void);
void temperatureConverter(void);
void findArea(void);

// Global variables.
static const float PI = 3.14f;

//Functions to read Values:
void readTwoValues(int* a, int* b){
   while(1){
        printf("Enter value of a: ");
        if(scanf("%d", a)==1) break;
        printf("Invalid value.\n");
        while(getchar()!='\n');
   }
    while(1){
        printf("Enter value of b: ");
        if(scanf("%d", b)==1) break;
        printf("Invalid value.\n");
        while(getchar()!='\n');
   }
}
void readFloat(float *val, const char *text){
    while(1){
        printf("\nEnter the %s: ", text);
        if(scanf("%f", val) == 1) break;
        printf("\n###-Invalid value Entered-###\n\n");
        while(getchar()!='\n');
    }
}

//Function to perform calculator operations.
void calculate(char op){
    int a,b;
    readTwoValues(&a,&b);

    switch(op){
        case '+':
            printf("The sum of %d and %d is: %d\n\n", a,b,a+b);
            break;
        case '-':
            printf("The difference of %d and %d is: %d\n\n", a,b,a-b);
            break;
        case '*':
            printf("The product of %d and %d is: %d\n\n", a,b,a*b);
            break;
        case '/':
            if(b == 0){
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            printf("The quotient of %d and %d is: %d\n\n", a,b,a/b);
            break;
        case '%':
            if(b == 0){
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            printf("The remainder of %d and %d is: %d\n\n", a,b,a%b);
            break;

    }
}

void calculator(){
    int option;

    while(1){
        printf(
            "***Choose the Function***\n"
            "1. Addition of two numbers\n"
            "2. Substraction of two numbers\n"
            "3. Multplication of two numbers\n"
            "4. Division of two numbers\n"
            "5. Find the Remainder\n"
            "6. Exit\n"
        );

        while(1){
            printf("Your Choice is: ");
            if(scanf("%d", &option) == 1) break;
            printf("***\nInvalid option***\n\n");
            while(getchar()!='\n');

        }
        // printf("\n");

        switch(option){
            case 1:
                calculate('+');
                break;
            case 2:
                calculate('-');
                break;
            case 3:
                calculate('*');
                break;
            case 4:
                calculate('/');
                break;
            case 5:
                calculate('%');
                break;
            case 6:
                return;
            default:
                printf("***Please enter a valid option***\n\n");
                break;
        }
    }

}


//Fuunctions for temperature converter.
void convertCelciusToFahrenheit(){
    float celciusVal;
    const char *text = "Celcius_Value";
    // printf("\nEnter the temperature in Celcius: ");
    readFloat(&celciusVal, text);
    printf("Converted temperature is: %.2fF\n\n", (celciusVal*9/5)+32);
}

void convertFahrenheitToCelcius(){
    float fahrenheitVal;
    const char *text = "Fahrenheit_Value";
    // printf("\nEnter the temperature in Celcius: ");
    readFloat(&fahrenheitVal, text);
    printf("Converted temperature is: %.2fC\n\n", (fahrenheitVal-32)*5/9);
}

void temperatureConverter(){
    int choice;
    while(1){
        printf(
            "\n***Choose the Function***\n"
            "1. Celcius to Fahrenheit\n"
            "2. Fahrenheit to Celcius\n"
            "3. Exit\n"
        );

        while(1){
            printf("Your Choice is: ");
            if(scanf("%d", &choice) == 1) break;
            printf("\nInvalid choice!!!\n");
            while(getchar()!='\n');
        }

        switch(choice){
            case 1:
                convertCelciusToFahrenheit();
                break;
            case 2:
                convertFahrenheitToCelcius();
                break;
            case 3:
                return;
            default:
                printf("Please Enter a valid option!!!");
        }
    }
}

//Functions for calculating and printing the area of select shapes.
void areaOfSquare(){
    float side;
    const char *text = "Side of Suare";
    readFloat(&side, text);
    printf("\nThe Area of Square is: %.2fsq mtrs\n", side*side);
}

void areaOfRectangle(){
    float length,breadth;
    const char *textLength = "Length of Rectangle";
    const char *textBreadth = "Breadth of Rectangle";

    readFloat(&length, textLength);
    readFloat(&breadth, textBreadth);
    printf("The Area of the Rectangle is: %.2fsq mtrs\n", length*breadth);
}
void areaOfTriangle(){
    float base,height;
    const char *textBase = "Base of the Triangle";
    const char *textHeight = "Height of the Triangle";
    
    readFloat(&base, textBase);
    readFloat(&height, textHeight);

    printf("The Area of the Triangle is: %.2fsq mtrs\n", 0.5*base*height);
}
void areaOfCircle(){
    float radius;
    const char *textRadius = "Radius of the Circle";
    
    readFloat(&radius, textRadius);

    printf("The area of the circle is: %.2f\n\n", PI*radius*radius);
}

void findArea(){
    int shape;

    while(1){
        printf(
            "\n-----Chose your shape-----\n"
            "1. Square\n"
            "2. Rectangle\n"
            "3. Triangle\n"
            "4. Circle\n"
            "5. Exit\n"
        );
        while(1){
            printf("\nYour choice: ");
            if(scanf("%d", &shape)==1)break;

            printf("Invalid Shape!!\n\n");
            while(getchar()!='\n');
        }

        switch(shape){
            case 1:
                areaOfSquare();
                break;
            case 2:
                areaOfRectangle();
                break;
            case 3:
                areaOfTriangle();
                break;
            case 4:
                areaOfCircle();
                break;
            case 5:
                return;
            default:
                printf("***Please enter a valid option***\n\n");
                break;
        }
    }
}

void optionsFunc(int *temp){
    
    printf(
        "\n*****Enter your choice*****\n"
        "1. Calculator.\n"
        "2. Temperature Converter.\n"
        "3. Area Finder.\n"
        "4. Exit\n\n"
        
    );

    while(1){
        printf("Your Choice is: ");
        if(scanf("%d", temp)==1) break;

        printf("Invalid Value\n\n");
        while(getchar()!='\n');
    }
}

void mainMenu(int *choice){
    int temp = *choice;
    while(temp != 4 ){
        switch(temp){
            case 1:
                calculator();
                break;
            case 2:
                temperatureConverter();
                break;
            case 3:
                findArea();
                break;
            default:
                printf("****Please enter a valid option.****\n\n");
                return;
        }
        
        optionsFunc(&temp);
        // printf("====%d=====%d====\n", temp, *choice);

    }
}

int main(){
    int choice;

    while(1){
        optionsFunc(&choice);
        switch(choice){
            case 1:
                calculator();
                break;
            case 2:
                temperatureConverter();
                break;
            case 3:
                findArea();
                break;
            case 4:
                printf("\n###..Closing the program..###\n\n");
                return 1;
            default:
                printf("\n****Invalid option.****\n\n");
        }
    }



    return 0;
}