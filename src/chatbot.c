#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "comparaison.h"
#include "lowercase.h"
#include "intention.h"
#include "chatbot.h"

/*This function will calculate the number of first occurence of each keyword of each intent_name*/
int count_intent(char *input, Intention *intents){
    int count= 0;
    for (int index=0; index< intents->keyword_score; index++){
        while (strstr(input,intents->keywords[index])!= NULL){
            count++;
        }
    }
    return count;
}



int index_max_intent(char *input, Intention intents[], int intent_count){
    int minimum = -1;
    int result;
    for (int i=0; i< intent_count; i++){
        if (count_intent(input, &intents[i])> minimum ) {
            minimum=  count_intent(input, &intents[i]);
            result=i;

        }        
    }
    return result;

}

void best_answer(Intention *intents){
    if ( intents->answer_score==0){
        printf("I don't have an answer to your question\n");       
    }
    else{
        printf("%s\n", intents->answers[0]);    
    }
}

