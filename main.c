#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intention.h"
#include "delete.h"
#include "chatbot.h"
#include "lowercase.h"

#define MAX_INTENTS 50
#define MAX_INPUT 1024

int main() {
    // printf("Debug: Démarrage du programme.\n"); // <-- Ajoutez cette ligne

    Intention intents[MAX_INTENTS];
    int intent_count = 0;

    // printf("Debug: Chargement des intentions...\n"); // <-- Debug
    load_intention("intention.txt", intents, &intent_count);
    // printf("Debug: %d intentions chargées.\n", intent_count); // <-- Debug

    char input[MAX_INPUT];
    printf("Welcome to ENSIMAG chatbot  ! Write 'quit' to quit.\n");

    while (1) {
        printf("\nYou: ");
        if (!fgets(input, sizeof(input), stdin)) {
            // printf("Debug: Fin de lecture (EOF).\n"); // <-- Debug
            break;
        }

        // printf("Debug: Input reçu: '%s'\n", input); // <-- Debug
        delete(input);
        lowercase(input);
        // printf("Debug: Input traité: '%s'\n", input); // <-- Debug

        if (strcmp(input, "quit") == 0) {
            printf("Chatbot: Good bye !\n");
            break;
        }

        int idx = index_max_intent(input, intents, intent_count);
        // printf("Debug: Intention trouvée à l'index %d\n", idx); // <-- Debug
        if (idx >= 0) {
            best_answer(&intents[idx]);
        } else {
            printf("Chatbot: I don't understand.\n");
        }
    }

    free_intents(intents, intent_count);
    // printf("Debug: Programme terminé.\n"); // <-- Debug
    return 0;
}