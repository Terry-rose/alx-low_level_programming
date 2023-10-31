#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_separator(char c, const char *separators) {
    while (*separators) {
        if (*separators == c) {
            return 1;
        }
        separators++;
    }
    return 0;
}

int count_words(char *str, const char *separators) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (is_separator(*str, separators)) {
            if (in_word) {
                in_word = 0;
                count++;
            }
        } else {
            in_word = 1;
        }
        str++;
    }

    if (in_word) {
        count++;
    }

    return count;
}

char **strtow(char *str) {
    const char *separators = " \t\n";
    int num_words = 0;
    int word_count = 0;
    char **words = NULL;

    if (str == NULL || *str == '\0') {
        return NULL;
    }

    num_words = count_words(str, separators);

    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    while (*str) {
        if (!is_separator(*str, separators)) {
            int word_length = 0;
            char *word_start = str;

            while (*str && !is_separator(*str, separators)) {
                word_length++;
                str++;
            }

            words[word_count] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_count] == NULL) {
                for (int i = 0; i < word_count; i++) {
                    free(words[i]);
                }
                free(words);
                return NULL;
            }

            strncpy(words[word_count], word_start, word_length);
            words[word_count][word_length] = '\0';
            word_count++;
        } else {
            str++;
        }
    }

    words[word_count] = NULL;

    return words;
}

void free_words(char **words) {
    if (words) {
        for (int i = 0; words[i] != NULL; i++) {
            free(words[i]);
        }
        free(words);
    }
}

int main(void) {
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL) {
        printf("Failed\n");
        return 1;
    }
    print_tab(tab);
    free_words(tab);
    return 0;
}

