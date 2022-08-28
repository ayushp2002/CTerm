#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Map is a struct that contains a function pointer and a char pointer.
 * @property {void} func - A pointer to a function that takes a char** and returns void.
 * @property {char} name - The name of the command.
 */
typedef struct {
    void (*func)(int, char**);
    char *name;
    const char *help, *syntax;
} Map;

/**
 * It takes a string and a function pointer as arguments, and returns a pointer to a Map struct
 * 
 * @param name The name of the function.
 * @param func The function to be called when the command is entered.
 * @param help The help string for the command
 * @param syntax The syntax string for the command
 * 
 * @return A pointer to a Map struct.
 */
Map *map_function(char *name, const char *help, const char *syntax, void (*func)(int, char**)) {
    Map *new_map = (Map *)malloc(sizeof(Map));
    new_map->name = strdup(name);
    new_map->func = func;
    new_map->help = help;
    new_map->syntax = syntax;
    return new_map;
}

/**
 * It takes a string and a map of functions and calls the function that is mapped to the command in the
 * string
 * 
 * @param cmd The command that the user entered.
 * @param map An array of pointers to Map structs.
 */
void call(char *cmd, Map *map[], int maplen) {
    char **tokens, **args, *str;
    int i = 0, tokencount = 0,found = 1;

    trim(cmd);
    /* Counting the number of tokens in the command. */
    if (cmd != NULL) {
        for (i = 0; cmd[i] != '\0'; i++) {
            if (cmd[i] == ' ' || cmd[i] == '\t') {
                tokencount++;
            }
        }
        tokencount++;
    }

    /* Allocating memory for the tokens and args arrays. */
    tokens = (char **)malloc(sizeof(char *) * tokencount);
    args = (char **)malloc(sizeof(char *) * (tokencount - 1));

    /* Tokenizing the string. */
    i = 0;
    str = strtok(cmd, " ");
    while (str != NULL) {
        tokens[i] = strdup(str);
        i++;
        str = strtok(NULL, " ");
    }

    /* Copying the tokens starting from index 1 into the args array. */
    for (i = 0; i < tokencount - 1; i++) {
        args[i] = strdup(tokens[i+1]);
    }

    /* Checking if the command is in the map. */
    for (i = 0; i < maplen; i++) {
        if (strcmp(map[i]->name, tokens[0]) == 0) {
            found = 0;
            break;
        }
    }
    
    /* Calling the function that is mapped to the command. */
    if (found == 0) {
        if (tokencount > 1 && *args[0] == '?') {   // Help
            printf("%s\n%s", map[i]->help, map[i]->syntax);
            if (strcmp(tokens[0], "EXIT") == 0) {
                strcpy(cmd, "");
            }
            
        } else {
            map[i]->func(tokencount-1, args);
        }
    } else {
        // printf("\"%s\" is not an executable command\nType \"help\" for viewing possible commands", tokens[0]);
        printf("\"%s\" is not an executable command", tokens[0]);
    }
    
}