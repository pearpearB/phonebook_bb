#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ph_book{
    struct ph_book *next;
    char *name;
    int age;
    char *number;
};

void addLast(struct ph_book *target)
{
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

int delet_node(struct ph_book *target, char *target_name)
{
    struct ph_book *Delet = target->next;
    struct ph_book *Bool = target->next;
    bool b;
   
    while(Delet->next!= NULL)
    {

    //    if(Delet->name == target_name){   // !!! : tomato만 나옴
    //        target->next = Delet->next; 
    //        free(Delet);
    //    }
       
        if(Delet->next->name == target_name){
            Delet->next =  Delet->next->next;
    //        free(Delet);   // !!! !!! : 여기서 SIGABRT 안 뜸!!왜??
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
    delet_node(head, "taeho");

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
       free(curr);   // !!! : 여기서 SIGABRT??
       curr = next;
   }

    free(head);

while(1)   // leaks 확인을 위한 와일문
{

}

    return 0;
}
    
