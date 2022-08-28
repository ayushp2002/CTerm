#include <stdio.h>
#include <unistd.h>

const char* PWD_HELP = "Shows the current directory active in CTerm";
const char* PWD_SYNTAX = "Usage: pwd";

void pwd (int argc, char **args) {
    printf("Present Working Directory: %s", getcwd(NULL, 0));
}