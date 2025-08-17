#include <ctype.h>


/*This function helps to know what the user want to say */
void lowercase(char *input){
    int index=0;
    while (input[index] != '\0'){
        input[index]= tolower(input[index]);
        index++;

    }

}