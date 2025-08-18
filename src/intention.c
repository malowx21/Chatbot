/*Group of key-words that are associated to a specific answer*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intention.h"
#include "delete.h"



void load_intention(char *filename, Intention intents[], int *intent_count){

    FILE *file= fopen(filename, "r");
    if (file==NULL){
        printf("Impossible d'ouvrir ce fichier");
        *intent_count=0;
        return;

    }
    char line[1000];
    Intention *current = NULL;
    *intent_count=0;

    while (fgets(line, sizeof(line), file))  {
        delete(line);
        if (strlen(line)== 0){
            continue;
        }
        else if (strncmp(line,"intent_name:",12)==0){
            int index = *intent_count;
            current = &intents[index];
            *intent_count++;
            strcpy(current -> name ,(line + 13));
            current -> keywords =NULL;
            current -> answers = NULL;
            current -> keyword_score=0;
            current -> answer_score=0;


        }
        else if (strncmp(line,"keywords:", 9)==0){
            char *temp= strtok(line+10, ",");
            while (temp){
                current -> keywords =realloc(current->keywords, sizeof(char*)*(current->keyword_score+1));
                current -> keywords[current->keyword_score++]= strdup(temp);
                temp=strtok(NULL,",");
            }
        }
        else if (strncmp(line,"answers:", 8)==0){
            char *temp2= strtok(line+9, ",");
            while (temp2){
            current -> answers =realloc(current->answers, sizeof(char*)*(current->answer_score+1));
            current -> answers[current->answer_score++]= strdup(temp2);
            temp2=strtok(NULL,",");
            }
        }
    }
    fclose(file);
}


void free_intents(Intention intents[], int intent_count) {
    for (int i = 0; i < intent_count; i++) {
        for (int j = 0; j < intents[i].keyword_score; j++) {
            free(intents[i].keywords[j]); 
        }
        free(intents[i].keywords); 
        for (int j = 0; j < intents[i].answer_score; j++) {
            free(intents[i].answers[j]);
        }
        free(intents[i].answers); 
    }
}

