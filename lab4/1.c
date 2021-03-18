#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dictionary
{
    char *word, *translation, *example;
};

int cmp (const void  *a, const void *b) {
    struct dictionary *first = (struct dictionary*) a;
    struct dictionary *second = (struct dictionary*) b;
    
    return strcmp(first->word, second->word);
}

void printInfo (struct dictionary arr[], int size, char *request) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(request, arr[i].word) == 0) {
            printf("Translation: %s\n", arr[i].translation);
            found = 1;
        }
    }

    if (found == 0) printf("There is no translation for this word\n");
}

int main() {
    system("clear");

    struct dictionary arr[6];

    char buffer[256];
    int size = 0;
    for (int i = 0; i < 5; i++) {
        printf("Do you want to enter data? (y/n)\n");
        scanf("%s", buffer);
        system("clear");

        if (strcmp(buffer, "y") == 0) {
        size++;
        printf("Enter the word: ");    
        scanf("%s", buffer);
        arr[i].word = calloc(strlen(buffer + 1), sizeof(char));
        strcpy(arr[i].word, buffer);

        printf("Enter the translation: ");    
        scanf("%s", buffer);
        arr[i].translation = calloc(strlen(buffer + 1), sizeof(char));
        strcpy(arr[i].translation, buffer);

        printf("Enter the example: ");    
        scanf("%s", buffer);
        arr[i].example = calloc(strlen(buffer + 1), sizeof(char));
        strcpy(arr[i].example, buffer);

        system("clear");
        } else break;
    }
    
    qsort(arr, size, sizeof(struct dictionary), cmp);

    printf("Enter the word which translation you want to find: ");
    char request[256];
    scanf("%s", request);

    printInfo(arr, size, request);
    
    for (int i = 0; i < size; i++) {
        free(arr[i].word);
        free(arr[i].translation);
        free(arr[i].example);
    }
    free(arr);
}