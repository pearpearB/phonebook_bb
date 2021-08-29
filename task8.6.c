#include <stdio.h>
#include <stdlib.h>

struct NODE{
    struct NODE *next;
    char *name;
    int age;
    char *number;
};

int main()
{
    struct NODE *head = malloc(sizeof(struct NODE));

    struct NODE *node1 = malloc(sizeof(struct NODE));
    head->next = node1;
    node1->name = "jueun";
    node1->age = 27;
    node1->number = "01099995555";
    
    struct NODE *node2 = malloc(sizeof(struct NODE));
    node1->next = node2;
    node2->name = "taeho";
    node2->age = 25;
    node2->number = "01042424242";

    node2->next = NULL;

    struct NODE *curr = head->next;

    while (curr != NULL)
    {
        printf("name : %s\n", curr->name);
        printf("age : %d\n", curr->age);
        printf("number : %s\n", curr->number);
        curr = curr->next;
    }

    free(node2);
    free(node1);
    free(head);

    return 0;
}
    
