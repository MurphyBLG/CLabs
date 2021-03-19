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

void memoryAllocation(struct node *elem, char *word, char *translation, char *example) {
    elem->info.word = calloc(strlen(word + 1), sizeof(char));
    strcpy(elem->info.word, word); 
    elem->info.translation = calloc(strlen(translation + 1), sizeof(char));
    strcpy(elem->info.translation, translation);
    elem->info.example = calloc(strlen(example + 1), sizeof(char));
    strcpy(elem->info.example, example);
}

void insert(struct node *tmp, struct node **first, struct node **last) {
    int inserted = 0;
            
    struct node *itr = *first;
    
    while (itr != NULL) {
        if (strcmp(tmp->info.word, itr->info.word) < 0) {
            tmp->next = itr;
            tmp->prev = itr->prev;
            if (itr->prev == NULL) {
                *first = tmp;
            } else {
                itr->prev->next = tmp;
            }
            itr->prev = tmp;
            inserted = 1;
            break;
        } 
        itr = itr->next;
    }
    if (inserted == 0) {
        itr = *last;
        while (itr != NULL) {
            if (strcmp(tmp->info.word, itr->info.word) >= 0) {
                tmp->prev = itr;
                tmp->next = itr->next;
                if (itr->next == NULL) {
                    *last = tmp;
                } else {
                    itr->next->prev = tmp;
                }
                itr->next = tmp;
                break;
            } 
            itr = itr->prev;
        }
    }
}

void printInfo(char request[], struct node *first) {
    struct node *f = first;
    while (f != NULL)
    {
        if (strcmp(f->info.word, request) == 0) {
            printf("Translation: %s\n", f->info.translation);
            return;
        }
        f = f->next;
    }
    printf("There is no translation for this word\n");
}

int main() {
    system("clear");
    
    struct node *first = NULL, *last = NULL;

    char word[256], translation[256], example[256], choice[25];
    for (int i = 0; i < 5; i++) {
        printf("Do you want to enter data? (yes/no)\n");
        scanf("%s", choice);
        system("clear");

        if (strcmp(choice, "yes") == 0) {
            printf("Enter the word: ");  
            scanf("%s", word);

            printf("Enter the translation: "); 
            scanf("%s", translation);

            printf("Enter the example: ");  
            scanf("%s", example);     

            if (first == NULL) {
                first = (struct node*) malloc(sizeof(struct node));

                first->prev = NULL;
                first->next = last;

                memoryAllocation(first, word, translation, example);
                system("clear");
                continue;
            }

            if (last == NULL) {
                last = (struct node*) malloc(sizeof(struct node));

                last->next = NULL;
                last->prev = first;
                first->next = last;

                if (strcmp(word, first->info.word) >= 0) {
                    memoryAllocation(last, word, translation, example);
                    system("clear");
                    continue;
                } else {
                    memoryAllocation(last, first->info.word, first->info.translation, first->info.example);
                    memoryAllocation(first, word, translation, example);

                    system("clear");
                    continue;
                }
            }

            struct node *tmp = malloc(sizeof(struct node));
            memoryAllocation(tmp, word, translation, example);

            insert(tmp, &first, &last);   
            system("clear");        
        } else break;
    }

    printf("Enter the word which translation you want to find: ");
    char request[256];
    scanf("%s", request);

    printInfo(request, first);

    struct node *f = first;
    while (f != NULL)
    {
        free(f->prev);
        free(f->info.word);
        free(f->info.translation);
        free(f->info.example);
        f = f->next;
    }
    free(first);
    free(last);
    free(f);
}

/* printf("TMP: %x %s %x\n", tmp->prev, tmp->info.word, tmp->next);
printf("ITR: %x %s %x\n", itr->prev, itr->info.word, itr->next);*/


/* printf("\n");
struct node *f = first;
while (f != NULL)
{
    printf("%x %s %x\n", f->prev, f->info.word, f->next);
    f = f->next;
}
printf("\n");*/