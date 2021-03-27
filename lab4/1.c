#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define system(clear) system("cls")

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
    int L = 0, R = size + 1;
    while (R - L > 1)
    {
        int m = (L + R) / 2;
        if (arr[m].word > request) R = m;
        else L = m;
    }
    
    if (arr[L].word == request) printf("Translation: %s\n", arr[L].translation);
    else printf("There is no translation for this word\n");
}

int isIn (char buffer[], struct dictionary arr[], int size) {
    for (int j = 0; j < size; j++) {
            if (strcmp(buffer, arr[j].word) == 0) return j + 1;
        }
    
    return 0;
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
        printf("Enter the word: ");    
        scanf("%s", buffer);

        if (isIn(buffer, arr, i)) {
            int flag = isIn(buffer, arr, i) - 1;
            printf("Enter the translation: ");    
            scanf("%s", buffer);
            arr[flag].translation = realloc(arr[flag].translation, sizeof(arr[flag].translation)+2+sizeof(buffer));
            strcat(arr[flag].translation, ", ");
            strcat(arr[flag].translation, buffer);

            printf("Enter the example: ");    
            scanf("%s", buffer);
            arr[flag].example = realloc(arr[flag].example, sizeof(arr[flag].example)+2);
            strcat(arr[flag].example, ", ");
            strcat(arr[flag].example, buffer);
            i--;
        } else {
            size++;
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
        }

        system("clear");
        } else break;
    }
    
    //qsort(arr, size, sizeof(struct dictionary), cmp);

    printf("%d", size);

    for (int i = 0; i < size; i++) {
        printf("%s\n%s\n%s\n\n", arr[i].word, arr[i].translation, arr[i].example);
    }

    /* printf("Enter the word which translation you want to find: ");
    char request[256];
    scanf("%s", request);

    printInfo(arr, size, request);*/
    
    for (int i = 0; i < size; i++) {
        free(arr[i].word);
        free(arr[i].translation);
        free(arr[i].example);
    } 
}