#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dictionary
{
    char *word, *translation, *example;
};

struct node {
    struct dictionary info;

    struct node *prev, *next;
};

int main() {
    system("clear");
    
    struct node *first = NULL, *last = NULL;

    char word[256], translation[256], example[256], choice;
    for (int i = 0; i < 5; i++) {
        printf("Do you want to enter data? (y/n)\n");
        scanf("%s", choice);
        system("clear");

        if (strcmp(choice, "y") == 0) {
        printf("Enter the word: ");    
        scanf("%s", word);

        printf("Enter the translation: ");    
        scanf("%s", translation);

        printf("Enter the example: ");    
        scanf("%s", example);

        if (first == NULL) {
            first = malloc(sizeof(struct node));
            last = first;

            first->prev = NULL;
            first->next = NULL;

            strcpy(first->info.word, word);
            strcpy(first->info.translation, translation);
            strcpy(first->info.example, example);
            continue;
        }

        struct node *tmp = malloc(sizeof(struct node));
        if ()

        system("clear");
        } else break;
    }
}