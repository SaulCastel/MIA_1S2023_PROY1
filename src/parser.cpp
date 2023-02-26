#include <string.h>
#include "parser.h"
#include "mkdisk.h"

void parse(char *input){
    char *tokens = strtok(input, " ");
    if(strcasecmp(tokens, "mkdisk") == 0){
        mkdisk(tokens);
    }
}