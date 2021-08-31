#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    node *next;
    char *name;
    int age;
    char *number;
}node;

void add_node(node *target)
{
    node *newbook = malloc(sizeof(node));
    node *Last = target->next;

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

int delet_node(char *target_name, node *target)
{
    node *Delet = target->next;
    node *tmp = target; 
    node *Bool = target->next;
    bool b;
   
    while(Delet->next!= NULL)
    {      
        if(Delet->next->name == target_name){
            Delet->next = tmp;
            Delet->next = Delet->next->next;
            free(tmp);  
        }

        Delet = Delet->next;    
    }

    while (Bool->next != NULL)
    {
        if(Bool->next->name != target_name){
            b = true;
        }
        else{
            b = false;
        }
        Bool = Bool->next;
    }

    printf(b ? "true" : "false");    
    printf("\n");

    return b;
}

int main()
{   
    int i = 1; // 전화번호부 수

    node *head = malloc(sizeof(node));

    node *ph_book1 = malloc(sizeof(node));
    head->next = ph_book1;
    ph_book1->name = "jueun";
    ph_book1->age = 27;
    ph_book1->number = "01099995555";
    
    node *ph_book2 = malloc(sizeof(node));
    ph_book1->next = ph_book2;
    ph_book2->name = "taeho";
    ph_book2->age = 25;
    ph_book2->number = "01042424242";

    ph_book2->next = NULL;

    add_node(head);
    delet_node("taeho", head);

    node *curr = head->next;

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
       node *next = curr->next;
       free(curr);   
       curr = next;
   }

    free(head);

    return 0;
}
    
