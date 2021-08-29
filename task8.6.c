#include <stdio.h>
#include <stdlib.h>

struct ph_book{
    struct ph_book *next;
    char *name;
    int age;
    char *number;
};

void addLast(struct ph_book *target)
{
int i = 0;
    struct ph_book *newbook = malloc(sizeof(struct ph_book));
    struct ph_book *Last = target->next;

    while(Last->next != NULL)     //Last로 접근하면 segmentation fault!
    {
        Last = Last->next;
    }

    Last->next = newbook;
    newbook->name = "tomato";
    newbook->age = 42;
    newbook->number = "01044442222";

    newbook->next = NULL;
}

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

    addLast(head);

    struct ph_book *curr = head->next;

    while (curr != NULL)
    {
        printf("*phonebook %d.\n", i);
        printf("name : %s\n", curr->name);
        printf("age : %d\n", curr->age);
        printf("number : %s\n", curr->number);
        curr = curr->next;
        i++;
    }

   curr = head->next;
   while(curr != NULL)
   {
       struct ph_book *next = curr->next;
       free(curr);
       curr = next;
   }

    free(head);

    return 0;
}
    
