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

void insert(struct node *tmp, struct node *first) {
    struct node *itr = first;
    while (itr != NULL)
    {
        if (strcmp(tmp->info.word, itr->info.word) < 0) {
            tmp->next = itr;
            tmp->prev = itr->prev;
            if (itr->prev == NULL) {
                first = tmp;
            } else {
                itr->prev->next = tmp;
            }
            itr->prev = tmp;
            break;
        } 
        itr = itr->next;
    }
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

                if (strcmp(word, first->info.word) >= 0) {
                    last->next = NULL;
                    last->prev = first;
                    first->next = last;

                    memoryAllocation(last, word, translation, example);
                    system("clear");
                    continue;
                } else {
                    memoryAllocation(last, first->info.word, first->info.translation, first->info.example);
                    memoryAllocation(first, word, translation, example);

                    last->prev = first;
                    last->next = NULL;
                    first->next = last;

                    system("clear");
                    continue;
                }
            }

            struct node *tmp = malloc(sizeof(struct node));
            memoryAllocation(tmp, word, translation, example);

            struct node *itr = first;
            while (itr != NULL)
            {
                if (strcmp(tmp->info.word, itr->info.word) < 0) {
                    tmp->next = itr;
                    tmp->prev = itr->prev;
                    if (itr->prev == NULL) {
                        first = tmp;
                    } else {
                        itr->prev->next = tmp;
                    }
                    itr->prev = tmp;
                    break;
                } 
                itr = itr->next;
            }

            itr = last;
            while (itr != NULL)
            {
                if (strcmp(tmp->info.word, itr->info.word) >= 0) {
                    tmp->prev = itr;
                    tmp->next = itr->next;
                    printf("%s %s %s\n", tmp->next->info.word, tmp->prev->info.word, itr->next->info.word);
                    if (itr->next == NULL) {
                        last = tmp;
                    } else {
                        itr->next->prev = tmp;
                    }
                    itr->next = tmp;
                    
                    break;
                } 

                itr = itr->prev;
            }
            itr = first;
            printf("%s %s %s", itr->info.word, itr->next->info.word, itr->next->next->info);
            
        } else break;
    }
    
    /*printf("Enter the word which translation you want to find: ");
    char request[256];
    scanf("%s", request);*/
    

}
/* last->prev = NULL;
                    last->next = first;
                    first->prev = last;
                    memoryAllocation(last, first->info.word, first->info.translation, first->info.example);
                    struct dictionary new = first->info;
                    first->info = last->info;
                    last->info = new;
                    */