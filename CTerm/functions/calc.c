#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const char* CALC_HELP = "Perform simple mathematical operations on two numbers";
const char* CALC_SYNTAX = "Usage: calc [first-number] [operator] [second-number]";

int isoperator(char);
double calculate (double, double, char);

void calc(int argc, char **args) {
    if (*args[0] == '?') {  // Help
        printf("%s\n%s", CALC_HELP, CALC_SYNTAX);
    } else {
        if (argc != 3) {    // Validate number of args
            printf("Error: 3 arguments needed, %d provided\n%s", argc, CALC_SYNTAX);
        } else {
            char *end, o;
            double a, b;
            o = *args[1];
            if (isoperator(o) == 0) {   // Check if a valid operator is sent
                end = NULL;
                a = strtod(args[0], &end);
                if (*end == '\0') {     // validate the first number
                    end = NULL;
                    b = strtod(args[2], &end);
                    if (*end == '\0') {     // validate the second number
                        printf("%lf %c %lf = %lf", a, o, b, calculate(a, b, o));
                    } else {
                        printf("ERROR: %s not recognized as a number", end);
                    }
                } else {
                    printf("ERROR: %s not recognized as a number", end);
                }
            } else {
                printf("%c not recognized as an operator", o);
            }
        }
    }
}

/* Checking if the character is an operator. */
int isoperator(char o) {
    switch (o) {
        case '+': return 0;
        case '-': return 0;
        case '*': return 0;
        case '/': return 0;
        case '^': return 0;
        default: return -1;
    }
}

double calculate (double a, double b, char o) {
    switch (o) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
}