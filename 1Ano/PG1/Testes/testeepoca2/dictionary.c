#include <stdio.h>

typedef int LettersCount['Z' - 'A' + 1];

#define MAX_WORD_SIZE 20
#define MAX_WORDS 5000

typedef struct {
    int nchars;
    char word[MAX_WORD_SIZE];
} Word;

typedef struct {
    int nwords;
    Word words[MAX_WORDS];
} Dictionary;

void word_letters_count(Word w, LettersCount lc) {
    for (int i = 0; i < w.nchars; i++) {
        char c = w.word[i];
        if (c >= 'A' && c <= 'Z') {
            lc[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            lc[c - 'a']++;
        }
    }
}

int words_with_nchars(Dictionary *dic, int num_chars) {
    int count = 0;

    for (int i = 0; i < dic->nwords; i++) {
        if (dic->words[i].nchars == num_chars) {
            count++;
        }
    }

    return count;
}

int main() {
    
    Dictionary myDictionary;
    myDictionary.nwords = 4;

    Word word1 = {6, "banana"};
    Word word2 = {5, "apple"};
    Word word3 = {7, "orange"};
    Word word4 = {5, "grape"};

    myDictionary.words[0] = word1;
    myDictionary.words[1] = word2;
    myDictionary.words[2] = word3;
    myDictionary.words[3] = word4;

    int result = words_with_nchars(&myDictionary, 5);
    printf("Number of words with 5 characters: %d\n", result);

    return 0;
}