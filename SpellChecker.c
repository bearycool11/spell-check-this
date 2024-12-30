#include "SpellChecker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 1000

// Node structure for the linked list in each hash table bucket
typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node;

// Hash table
node *hash_table[HASH_SIZE];

// Hash function
unsigned int hash(const char *word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
        hash = ((hash << 5) + hash) + tolower(c);
    return hash % HASH_SIZE;
}

// Loads the dictionary into memory
bool load_dictionary(const char *dictionary_file) {
    FILE *file = fopen(dictionary_file, "r");
    if (!file) return false;

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%100s", word) != EOF) {
        node *new_node = malloc(sizeof(node));
        if (!new_node) return false;
        strcpy(new_node->word, word);
        unsigned int index = hash(word);
        new_node->next = hash_table[index];
        hash_table[index] = new_node;
    }
    fclose(file);
    return true;
}

// Checks if a word is in the dictionary
bool check_word(const char *word) {
    char lower_word[MAX_WORD_LENGTH + 1];
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[len] = '\0';

    unsigned int index = hash(lower_word);
    node *cursor = hash_table[index];
    while (cursor) {
        if (strcmp(cursor->word, lower_word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Unloads the dictionary from memory
bool unload_dictionary(void) {
    for (int i = 0; i < HASH_SIZE; i++) {
        node *cursor = hash_table[i];
        while (cursor) {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
