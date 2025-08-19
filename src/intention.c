/*Group of key-words that are associated to a specific answer*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intention.h"
#include "delete.h"


#define MAX_INTENTS 50  
void load_intention(char *filename, Intention intents[], int *intent_count){

    FILE *file= fopen(filename, "r");
    if (file==NULL){
        printf("Impossible d'ouvrir ce fichier");
        *intent_count=0;
        return;

    }
    char line[1024];
    Intention *current = NULL;
    *intent_count=0;

    while (fgets(line, sizeof(line), file))  {
        // printf("Debug: ligne lue -> '%s'\n", line);
        delete(line);
        // printf("Debug: ligne lue -> '%s'\n", line);
        if (strlen(line)== 0){
            continue;
        }
        else if (strncmp(line,"intent_name:",12)==0){
            // printf("rijal\n");
            int index = *intent_count;
            current = &intents[index];
            (*intent_count)++;
            current->name = malloc(strlen(line + 13) + 1); // +1 pour le '\0'
            if (!current->name) {
                printf("Erreur malloc pour le nom de l'intention\n");
                exit(1);
            }
            strcpy(current -> name ,(line + 13));
            current -> keywords = NULL;
            current -> answers = NULL;
            current -> keyword_score =0;
            current -> answer_score =0;
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
            char *temp2= strtok(line+9, "/");
            while (temp2){
            current -> answers =realloc(current->answers, sizeof(char*)*(current->answer_score+1));
            current -> answers[current->answer_score++]= strdup(temp2);
            temp2=strtok(NULL,"/");
            }
        }
    }
    fclose(file);
}

// void load_intention(char *filename, Intention intents[], int *intent_count){
//     FILE *file= fopen(filename, "r");
//     if (file==NULL){
//         printf("Impossible d'ouvrir ce fichier");
//         *intent_count=0;
//         return;
//     }
    
//     char line[1024];
//     Intention *current = NULL;
//     *intent_count=0;
//     int line_number = 0;  // ← Ajoutez un compteur de lignes

//     while (fgets(line, sizeof(line), file))  {
//         line_number++;  // ← Incrémentez à chaque ligne
//         printf("Ligne %d: '%s'\n", line_number, line);  // ← Debug amélioré
        
//         delete(line);
        
//         if (strlen(line)== 0){
//             printf("Ligne vide ignorée\n");
//             continue;
//         }
//         else if (strncmp(line,"intent_name:",12)==0){
//             printf("Nouvelle intention détectée\n");
//             if (*intent_count >= MAX_INTENTS) {  // ← Ajoutez une sécurité
//                 printf("ERREUR: Trop d'intentions!\n");
//                 break;
//             }
            
//             int index = *intent_count;
//             current = &intents[index];
//             (*intent_count)++;
            
//             printf("Current pointer: %p, Index: %d\n", (void*)current, index);  // ← Debug du pointeur
//             current->name = malloc(strlen(line + 13) + 1); // +1 pour le '\0'
//             if (!current->name) {
//                 printf("Erreur malloc pour le nom de l'intention\n");
//                 exit(1);
//             }
//             strcpy(current -> name ,(line + 13));
//             current -> keywords = NULL;
//             current -> answers = NULL;
//             current -> keyword_score =0;
//             current -> answer_score =0;
            
//             printf("Intention '%s' créée\n", current->name);
//         }
//         else if (current == NULL) {  // ← Sécurité importante!
//             printf("ERREUR: Aucune intention courante!\n");
//             continue;
//         }
//         else if (strncmp(line, "keywords:" , 9) ==0){
//             printf("Keywords détectés pour '%s'\n", current->name);  // ← Debug
//             char *temp = strtok(line+10, ",");
//             while (temp){
//                 printf("Keyword: %s\n", temp);  // ← Debug
//                 char **new_keywords = realloc(current->keywords, sizeof(char*)*(current->keyword_score+1));
//                 if (!new_keywords) {
//                     printf("Erreur realloc keywords\n");
//                     exit(1);
//                 }
//                 current->keywords = new_keywords;
//                 current->keywords[current->keyword_score++] = strdup(temp);
//                 temp = strtok(NULL, ",");
//             }
//         }
//         else if (strncmp(line,"answers:", 8)==0){
//             printf("Answers détectés pour '%s'\n", current->name);  // ← Debug
//             char *temp2 = strtok(line+9, "/");
//             while (temp2){
//                 printf("Answer: %s\n", temp2);  // ← Debug
//                 char **new_answers = realloc(current->answers, sizeof(char*)*(current->answer_score+1));
//                 if (!new_answers) {
//                     printf("Erreur realloc answers\n");
//                     exit(1);
//                 }
//                 current->answers = new_answers;
//                 current->answers[current->answer_score++] = strdup(temp2);
//                 temp2 = strtok(NULL, "/");
//             }
//         }
//         else {
//             printf("Ligne non reconnue: %s\n", line);  // ← Capture les lignes non traitées
//         }
//     }
//     fclose(file);
//     printf("Chargement terminé. %d intentions chargées.\n", *intent_count);
// }

void free_intents(Intention intents[], int intent_count) {
    for (int i = 0; i < intent_count; i++) {
        free(intents[i].name); 
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

