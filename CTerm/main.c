#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "function_call_map.h"

#include "./functions/calc.c"
#include "./functions/pwd.c"
#include "./functions/exitcterm.c"
#include "./functions/changedir.c"
#include "./functions/ls.c"

const int MAPLEN = 5;

/* Initialize the mapping of functions */
void init_maps(Map *map[]) {
    map[0] = map_function("CALC", CALC_HELP, CALC_SYNTAX, calc);
    map[1] = map_function("PWD", PWD_HELP, PWD_SYNTAX, pwd);
    map[2] = map_function("EXIT", EXIT_HELP, EXIT_SYNTAX, exitcterm);
    map[3] = map_function("CD", CD_HELP, CD_SYNTAX, changedir);
    map[4] = map_function("LS", LS_HELP, LS_SYNTAX, ls);
}

int main() {
    char *cmd;
    Map *map[MAPLEN];

    printf("CTerm v1.0\n");
    
    init_maps(map);

    /* Loop will continue to run until the user types "EXIT" */
    do {
        printf("\n> ");
        cmd = to_uppercase(getln());
        /* Calling the function that is mapped to the string cmd. */
        call(&*cmd, map, MAPLEN);
    } while (strcmp(cmd, "EXIT"));
    
    return 0;
}
