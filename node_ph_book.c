#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *next;
    char *name;
    int age;
    char *number;
}node;

int max = 0; //총 전화번호부 개수
int add_Node();
int delet_Node();
int print_Node();
int exit_Node();

int main()
{
    int menu;
    node *head = malloc(sizeof(node));

    while(1)
    {
        printf("******* MENU *******\n");
        printf("1. INSERT\n");
        printf("2. DELET\n");
        printf("3. ALL PRINT\n");
        printf("4. Exit\n");
        printf("Choose the item: ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
                add_Node(head);
                break;

            case 2:
                delet_Node(head);
                break;

            case 3:
                print_Node(head);
                break;

            case 4:
                exit_Node(head);
                break;

            default:
                printf("! Try Again.\n");
                break;
        }

    }

    return 0;
}

int add_Node(node *target)
{
    char tmp_name[20];
    char tmp_number[12];

    node *new_book = malloc(sizeof(node));
    node *add_Last = target->next;

    new_book->name = malloc(sizeof(char)*strlen(tmp_name)+1);
    new_book->name = malloc(sizeof(char)*strlen(tmp_number)+1);

    printf("\n******* Insert *******\n");

    if(target->next == NULL) 
    {
        target->next = new_book;
    }
    else
    {
        while(add_Last->next != NULL)     
        {
            add_Last = add_Last->next;
        }

        add_Last->next = new_book;
    }

    printf("Input Name: ");
    scanf("%s", tmp_name);
    strcpy(new_book->name, tmp_name); 
    getchar();

    while (1)
    {
        printf("Input Age: ");
        scanf("%d", &new_book->age);
        getchar();

        if( new_book->age > 0 )
        {
            break;
        } 
        else 
        {
            printf("! Enter a Number, Try Again\n");
            getchar();
        }
    }

    printf("Input Phone Number: ");
    scanf("%s", tmp_number);
    strcpy(new_book->number, tmp_number); 
    getchar();

// ??? : segmentation fault

    new_book->next = NULL;

    max++;

    printf("Done.\n");

    return 0;

}

int delet_Node(node *target)
{
    node *Delet = target->next; 
    node *tmp = Delet->next;
    char tmp_name[20];
    int i = 0;
    
// ??? : segmentation fault

    printf("\n******* Delet *******\n");

    if(target->next == NULL)
    {
        printf("! EMPTY, Go to Insert.\n");
    }

    printf("Delet for name: ");
    scanf("%s", tmp_name);

    while(Delet->next != NULL)
    {
        if(Delet->next->name == tmp_name)
        {
            Delet->next = tmp->next;
            free(tmp);
        }

        Delet = Delet->next;
    }

    max--;

    printf("Done.\n");

    return 0;

}

int print_Node(node *target)
{
    int i = 1; // 전화번호부 넘버

    node *curr = target->next;

    if(target->next == NULL)
    {
        printf("! EMPTY, Go to Insert.\n");
    }
    else
    {
        while (curr != NULL)
        {
            printf("*phonebook %d.\n", i);
            printf("name : %s\n", curr->name);
            printf("age : %d\n", curr->age);
            printf("number : %s\n", curr->number);
            curr = curr->next;
            i++;
        }

    }

    return 0;

}

int exit_Node(node *target)
{
    node *curr = target->next;    

    while(curr != NULL)
    {
        node *next = curr->next;
        free(curr);   
        curr = next;
    }

    free(target);

    exit(0);
}