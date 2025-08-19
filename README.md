# ENSIMAG Chatbot

## Overview
A simple C-based chatbot designed to answer questions about ENSIMAG. It detects user intent using keywords and provides appropriate responses.

This project gave me hands-on experience with the basics of artificial intelligence, particularly in natural language processing and intent recognition.

## Features
- Intent recognition via keyword matching
- Console-based interactive chatbot
- Automatic input preprocessing (lowercase conversion)
- Default response if no intent is found
- Exit by typing `quit`

## Project Structure
```bash
├─ include/ # Header files
│ ├─ chatbot.h
│ ├─ delete.h
│ ├─ intention.h
├─ src/ # Implementation files
│ ├─ chatbot.c
│ ├─ delete.c
│ ├─ intention.c
├─ main.c 
├─ Makefile # Build instructions
└─ intention.txt # Intents, keywords, and answers
```


## Usage
Compile and run the chatbot:
```bash
make
./chatbot
```


## Exampme of interaction
```bash

Welcome to the ENSIMAG chatbot! Type 'quit' to exit.

You: hello
Hello, I am the ENSIMAG chatbot. How can I help you?

You: programs
ENSIMAG offers programs in computer science, applied mathematics, and finance. Do you want me to detail one of the tracks?

You: quit
Goodbye!

```
## Improvement to add 

Implement more advanced natural language processing techniques to understand user input better.

Add support for multiple answers per intent with random selection.

Improve the keyword matching algorithm to allow partial matches and fuzzy matching.

Enhance the chatbot’s learning capabilities by allowing dynamic addition of new intents and responses.