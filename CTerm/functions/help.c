#include <stdio.h>

const char* HELP_HELP = "Shows the help and syntax for all/one command";
const char* HELP_SYNTAX = "help\nOR\nhelp [command-name]";

/**
 * This method will be defined in the function_call_map.h to make sure that the Map
 * object is accessed internally only.
 * This method needs the Map object to execute which is not possible with the standard
 * string arguments that we are using.
 */