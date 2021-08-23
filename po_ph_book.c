#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_phonebook
{
        char *name;
        int age;
        char *number;
}ph_book;

int Yes; //메뉴입력
int max = 0; // 총 인원
int add_info(void); //추가
int search_info(void); //검색
int Update_info(void); //수정
int delet_info(void); //삭제
int all_info(void); //목록 
struct s_phonebook *p[100];

int main()
{
    int i = 0; // 말록 프리
    
    while(1){
        printf("***** MENU *****\n");
        printf("1. Insert\n2. Search\n3. Update\n4. Delet\n5. Print All\n6. Exit\n");
        printf("Choose the item: ");
        scanf("%d", &Yes);

        if(Yes == 6) break;

        switch(Yes)
        {
            case 1:
                add_info();
                break;

            case 2:
                search_info();
                break;
            
            case 3:
                Update_info();
                break;
                
            case 4:
                delet_info();
                break;
                
            case 5:
                all_info();
                break;

            default:
                printf("! Try Again.\n");
                break;
        }

    }
        while ( i < max){
            free(p[i]->name);
            free(p[i]->number);
            i++;
        }

        free(p);
        
        return 0;
}

int add_info()
{
    p[max] = malloc(sizeof(ph_book));
    
    char na[20] = {0,};
    //na = (char *)malloc(sizeof(char) * strlen(na) +1); //? 스캔에프 글자수만큼 받고 시퍼여

    p[max]->name = malloc(sizeof(char) * strlen(na) +1);
    p[max]->number = malloc(sizeof(char) * 12);
    
    printf("Input Name: ");
    scanf("%s", na);
    strcpy(p[max]->name, na);

    getchar();
    
    while (1){
        printf("Input Age: "); 
        scanf("%d", &p[max]->age);
        getchar();
        
        if( p[max]->age > 0 ){
            break;

        } else {
            printf("! Enter a Number, Try Again\n");
            getchar();
        }
    }
    
    printf("Input Phone Number: ");
    scanf("%s", p[max]->number);
    getchar();
    
    max++;

    printf("Done.\n");

    return 0;
}

int search_info() //2명 넣었을 때 1결과나오고 결과없음 뜸 2 결과 없음뜸 ,,,if 문제인듯
{
    char who[20];
    int j = 0;
    printf("\n***** Search *****\n");
    printf("Search for name: ");
    scanf("%s", who);
    
    while( j <= max ){
        if ( strcmp(who,p[j]->name) == 0 ){
            printf("Name: %s\nAge: %d\nPhone Number: %s\n", p[j]->name, p[j]->age, p[j]->number);
        }
        else{
            printf("! No Result\n");
            break;
        }
        j++;
    }
    
    printf("Done.\n");
    return 0;
}

int Update_info()
{
    char tmp_na[20];
    char new_na[20];
    char new_nu[12];
    int z = 0;
    int new_age;
    int cho;

    printf("\n***** Update *****\n");
    printf("Update for name: ");
    scanf("%s", tmp_na);
    
    while(z < max){
        if( strcmp(tmp_na,p[z]->name) == 0 ){
            printf("Update %s's data\n", tmp_na);
            printf("1. name\n2. age\n3. number\n");
            printf("Choose the item: ");
            scanf("%d", &cho);
            
            switch(cho){
                case 1:
                    printf("New Name: ");
                    scanf("%s", new_na);
                    p[max]->name = NULL;
                    p[max]->name = malloc(sizeof(char) * strlen(new_na) +1);
                    strcpy(p[z]->name, new_na);
                    break;
                case 2:
                    printf("New age: ");
                    scanf("%d", &new_age);
                    p[z]->age = new_age;
                    break;
                case 3:
                    printf("New Number: ");
                    scanf("%s", new_nu);
                    strcpy(p[z]->number, new_nu);
                    break;
                default:
                    printf("Try Again.\n");
                    break;
            }

        }
        z++;
    }
    
    printf("Done.\n");
    return 0;
}

int delet_info() // !!! : 한명 넣고 살제할때 튕김 & 2명일때 1삭제잘됨 2삭제되고 결과없음,,, if 문제인듯
{
    char tmp_na[20];
    char tmp1 = {0,};
    char tmp2 = {0,};
    int z = 0;
    
    printf("\n***** Delet *****\n");
    printf("Delet for name: ");
    scanf("%s", tmp_na);
    
    while( z <= max ){ 
        if( strcmp(tmp_na,p[z]->name) == 0 ){
            while( z < max ){
                strcpy(p[z]->name, p[z+1]->name);
                p[z]->age = p[z+1]->age;
                strcpy(p[z]->number, p[z+1]->number);
                z++;
            }
            strcpy(p[max-1]->name, &tmp1);
            p[max-1]->age = '\0';
            strcpy(p[max-1]->number, &tmp2);
        }
        else{
            printf("! No Result\n");
            break;
        }
        z++;
    }
    max--;
    printf("Done.\n");
    return 0;
}

int all_info()
{
    int j = 0;
    printf("\n***** Print All *****\n");
    printf(">>Total: %d<<\n", max);

    if( max == 0){
        printf("! EMPTY, Go to Insert.\n");
    }
    
    else{
        while( j < max ){
            printf("No. %d\nName: %s\nAge: %d\nPhone Number: %s\n", j+1, p[j]->name, p[j]->age, p[j]->number);
            printf("\n");
            j++;
        }
        printf("Done.\n");
    }
    return 0;
}