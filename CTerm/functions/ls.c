#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

const char *LS_HELP = "List all the directories in the present working directory";
const char *LS_SYNTAX = "Usage: ls [optional: directory]";

void ls(int argc, char **args) {
    DIR *d;
    struct dirent *dir;
    char *path;
    int len, flag = 1;

    if (argc == 1) {
        len = strlen(args[0]);
        path = (char *)malloc(sizeof(char) * len);
        if (path != NULL) {
            strcpy(path, args[0]);
        }
    } else if (argc == 0) {
        path = strdup("./");
    } else {
        printf("Error: invalid arguments provided\n%s\n%s", LS_HELP, LS_SYNTAX);
        flag = 0;
    }

    if (flag == 1) {
        d = opendir(path);
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                printf("\n%s", dir->d_name);
            }
            closedir(d);
        } else {
            printf("Error: Directory %s does not exist", path);
        }
    }
}