# Modular Utility Console in C

A menu-driven console application written in C to strengthen core programming concepts through modular software design.

This project combines multiple independent utilities into a single application while emphasizing clean function design, input validation, modularity, and reusable code.

---

## Features

### Calculator

- Addition
- Subtraction
- Multiplication
- Division
- Modulus
- Division-by-zero handling
- Continuous menu navigation

### Temperature Converter

- Celsius → Fahrenheit *(Planned)*
- Fahrenheit → Celsius *(Planned)*

### Area Calculator

- Square
- Rectangle
- Triangle
- Circle

---

## Project Goals

The purpose of this project was **not** to build a calculator.

Instead, it was to practice:

- Function decomposition
- Input validation
- Menu-driven program design
- Pointer parameters
- Passing arguments by reference
- Code reuse
- Basic software architecture

---

## Concepts Practiced

### C Fundamentals

- Functions
- Function prototypes
- Variables
- Scope
- Loops
- Switch statements
- Constants
- Pointer parameters

### Input Handling

- Safe integer input
- Safe floating-point input
- Invalid input recovery using `getchar()`

### Software Engineering

- Separation of concerns
- Reusable helper functions
- Single Responsibility Principle
- Modular function design

---

## Project Structure

```
main()
│
├── Main Menu
│
├── Calculator
│     ├── readTwoValues()
│     └── calculate()
│
├── Temperature Converter
│
└── Area Calculator
      ├── Square
      ├── Rectangle
      ├── Triangle
      └── Circle
```

---

## Example

```
*****Enter your choice*****

1. Calculator
2. Temperature Converter
3. Area Finder
4. Exit

Your Choice: 3

Choose your shape

1. Square
2. Rectangle
3. Triangle
4. Circle

Enter base: 5
Enter height: 3

Area = 7.50 sq.m
```

---

## Future Improvements

- [ ] Split into multiple source files
- [ ] Add header files
- [ ] Introduce enums for menu options
- [ ] Generic input utility library
- [ ] Unit conversion module
- [ ] Scientific calculator
- [ ] Makefile support
- [ ] CMake support

---

## Lessons Learned

During this project I learned:

- Why modular code is easier to maintain
- How to validate user input correctly
- How pointer parameters allow functions to modify variables
- Why repeated code should be extracted into helper functions
- How menu-driven applications should be structured

---
## Final Version.
UtilityConsole/

├── src/

│   ├── main.c

│   ├── calculator.c

│   ├── geometry.c

│   ├── temperature.c

│   ├── input.c

│   └── menu.c

├── include/

│   ├── calculator.h

│   ├── geometry.h

│   ├── temperature.h

│   ├── input.h

│   └── menu.h

├── README.md

├── Makefile

└── LICENSE

---

## Build

Compile using GCC

```bash
gcc calc.c -o calc
```

Run

```bash
./calc
```

---

## Author

**Siva Dinesh Kammara**

M.Sc. Electromobility

Learning Journey toward Embedded Firmware Engineering