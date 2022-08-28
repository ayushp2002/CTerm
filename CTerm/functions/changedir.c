#include <stdio.h>
#include <unistd.h>

const char *CD_HELP = "Changes the current active directory in CTerm";
const char *CD_SYNTAX = "Usage: cd [directory-name]";

void changedir(int argc, char **args) {
    if (argc == 1) {
        if (chdir(args[0]) == 0) {
            printf("Changed working directory: %s", args[0]);
        } else {
            printf("Error: Cannot change directory");
        }
    } else {
        printf("%s\n%s", CD_HELP, CD_SYNTAX);
    }
}