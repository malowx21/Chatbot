#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intention.h"
#include "delete.h"
#include "chatbot.h"

#define MAX_INTENTS 50
#define MAX_INPUT 1024

int main() {
    Intention intents[MAX_INTENTS];
    int intent_count = 0;

    load_intention("intents.txt", intents, &intent_count);

    char input[MAX_INPUT];

    printf("Bienvenue au chatbot ENSIMAG ! Tapez 'quit' pour sortir.\n");

    while (1) {
        printf("\nVous: ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; // EOF
        }

        delete(input);  // supprime le \n
        lowercase(input);

        if (strcmp(input, "quit") == 0) {
            printf("Chatbot: Au revoir !\n");
            break;
        }

        int idx = index_max_intent(input, intents, intent_count);
        best_answer(&intents[idx]);
    }

    free_intentions(intents, intent_count);

    return 0;
}
