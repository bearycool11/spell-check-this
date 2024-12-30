#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Loads the dictionary into memory. Returns true if successful.
bool load_dictionary(const char *dictionary_file);

// Checks if a word is in the dictionary. Returns true if the word is valid.
bool check_word(const char *word);

// Unloads the dictionary from memory. Returns true if successful.
bool unload_dictionary(void);

#endif // SPELLCHECKER_H
