#include <stdio.h>
#include <stdlib.h>

struct ph_book{
    struct ph_book *next;
    char *name;
    int age;
    char *number;
};

int main()
{
    int i = 1;
    
    struct ph_book *head = malloc(sizeof(struct ph_book));

    struct ph_book *ph_book1 = malloc(sizeof(struct ph_book));
    head->next = ph_book1;
    ph_book1->name = "jueun";
    ph_book1->age = 27;
    ph_book1->number = "01099995555";
    
    struct ph_book *ph_book2 = malloc(sizeof(struct ph_book));
    ph_book1->next = ph_book2;
    ph_book2->name = "taeho";
    ph_book2->age = 25;
    ph_book2->number = "01042424242";

    ph_book2->next = NULL;

    struct ph_book *curr = head->next;

    while (curr != NULL)
    {
        printf("phonebook %d.\n", i);
        printf("name : %s\n", curr->name);
        printf("age : %d\n", curr->age);
        printf("number : %s\n", curr->number);
        curr = curr->next;
        i++;
    }

    free(ph_book2);
    free(ph_book1);
    free(head);

    return 0;
}
    
