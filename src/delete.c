#include "delete.h"
#include <string.h>



/* This function is important because when we use fgets in C, automatically the input
the input will contain \n at the end, therefore the comparison won't be correct.Thus we
need to remove it.*/

void delete(char *input) {
    int index = 0;
    while (input[index] != '\0') {
        if (input[index] == '\n' || input[index] == '\r') {
            input[index] = '\0';
            break;
        }
        index++;
    }
}
