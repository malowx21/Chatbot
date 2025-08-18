#ifndef INTENTION_H
#define INTENTION_H

typedef struct {   
    char *name;
    char **keywords;
    char **answers;
    int keyword_score;
    int answer_score;
} Intention;


void load_intention(char *filename, Intention intents[], int *intent_count);
void free_intents(Intention intents[], int intent_count);
#endif