#include <stdio.h>
#include <string.h>

typedef struct s_phonebook
{
        char name[20];
        int age;
        char number[12];
}ph_book;

int Yes; //메뉴입력
int max = 0; // 총 인원
int add_info(void); //추가
int search_info(void); //검색
int Update_info(void); //수정
int delet_info(void); //삭제
int all_info(void); //목록
struct s_phonebook p[100];

int main()
{
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
    
        return 0;
}

int add_info()
{
    printf("Input Name: ");
    scanf("%s", p[max].name);
    getchar();
    
    while (1){
        printf("Input Age: "); 
        scanf("%d", &p[max].age);
        getchar();
        
        if( p[max].age > 0 ){
            break;

        } else {
            printf("! Enter a Number, Try Again\n");
            getchar();
        }
    }
    
    printf("Input Phone Number: ");
    scanf("%s", p[max].number);
    getchar();
    
    max++;

    printf("Done.\n");
    return 0;
}

int search_info() 
{
    char who[20];
    int j = 0;
    printf("\n***** Search *****\n");
    printf("Search for name: ");
    scanf("%s", who);
    
    while( j <= max ){
        if ( strcmp(who,p[j].name) == 0 ){
            printf("Name: %s\nAge: %d\nPhone Number: %s\n", p[j].name, p[j].age, p[j].number);
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
    char nna[20];
    char nnu[12];
    int z = 0;
    int j;
    int cho;

    printf("\n***** Update *****\n");
    printf("Update for name: ");
    scanf("%s", tmp_na);
    
    while(z < max){
        if( strcmp(tmp_na,p[z].name) == 0 ){
            printf("Update %s's data\n", tmp_na);
            printf("1. name\n2. age\n3. number\n");
            printf("Choose the item: ");
            scanf("%d", &cho);
            
            switch(cho){
                case 1:
                    printf("New Name: ");
                    scanf("%s", nna);
                    strcpy(p[z].name, nna);
                    break;
                case 2:
                    printf("New age: ");
                    scanf("%d", &j);
                    p[z].age = j;
                    break;
                case 3:
                    printf("New Number: ");
                    scanf("%s", nnu);
                    strcpy(p[z].number, nnu);
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

int delet_info()
{
    char tmp_nu[20];
    char tmp1 = {0,};
    char tmp2 = {0,};
    int z = 0;
    
    printf("\n***** Delet *****\n");
    printf("Delet for name: ");
    scanf("%s", tmp_nu);
    
    while( z <= max ){ 
        if( strcmp(tmp_nu,p[z].name) == 0 ){
            while( z < max ){
                strcpy(p[z].name, p[z+1].name);
                p[z].age = p[z+1].age;
                strcpy(p[z].number, p[z+1].number);
                z++;
            }
            strcpy(p[max-1].name, &tmp1);
            p[max-1].age = '\0';
            strcpy(p[max-1].number, &tmp2);
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
            printf("No. %d\nName: %s\nAge: %d\nPhone Number: %s\n", j+1, p[j].name, p[j].age, p[j].number);
            printf("\n");
            j++;
        }
        printf("Done.\n");
    }
    return 0;
}


