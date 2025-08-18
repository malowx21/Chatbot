#ifndef CHATBOT_H
#define CHATBOT_H

#include "intention.h"

// Compte combien de mots-clés d’un intent apparaissent dans l’input
int count_intent(char *input, Intention *intents);

// Retourne l’index de l’intent qui correspond le mieux à l’input
int index_max_intent(char *input, Intention intents[], int intent_count);

// Affiche la meilleure réponse d’un intent
void best_answer(Intention *intents);

#endif
