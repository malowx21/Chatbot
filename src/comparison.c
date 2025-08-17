#include <string.h> 


char *search(char *big, char* small){
    if (*small =='\0' ){
        return *big;
    }
    for (int i=0; big[i]!='\0';i++){
        int j=0;
        while (small[j]!='\0' && small[j]==big[i+j]){
            j++;
        }
        if (small[j]=='\0'){
            return (char *)(big +i);
        }
    }
    return NULL;

}


void comparison(char *input, char *keys[] ){
    int score=0;
    for (int i=0; keys[i]!='\0'; i++){
        if (search(input, keys[i])!=NULL){
            score++;
        }

    }
    printf("The number of key words in input is : %d", score);
}


