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
int end_info(void); // 나가기
struct s_phonebook *p[100];

int main()
{   
    while(1){
        printf("***** MENU *****\n");
        printf("1. Insert\n2. Search\n3. Update\n4. Delet\n5. Print All\n6. Exit\n");
        printf("ooh\n");
	printf("Choose the item: ");
        scanf("%d", &Yes);

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

             case 6:
                end_info();
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
    p[max] = malloc(sizeof(ph_book));
    
    char na[20];
    
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

int search_info() 
{
    char who[20];
    int j = 0;
    printf("\n***** Search *****\n");
    printf("Search for name: ");
    scanf("%s", who);
    
    while( j < max ){ // j <= max -> = : 포인터에 접근할 수 없으므로 segmentation fault 
        if ( strcmp(who,p[j]->name) == 0 ){
            printf("Name: %s\nAge: %d\nPhone Number: %s\n", p[j]->name, p[j]->age, p[j]->number);
            break;
        }
        j++;
    }

    if ( j == max ){  // 결과 없을 때 다 돌고 나오니까
        printf("! No Result.\n");
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
                    p[z]->name = realloc(p[z]->name, sizeof(char) * strlen(new_na) +1); // malloc은 한번 반환되면 다시 사용 불가, realloc으로 크기 바궈주기
                    
                    printf("New Name: ");
                    scanf("%s", new_na);

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
        break;
        }
        z++;
    }
    
    if( z > max){  
         printf("! No Result.\n"); 
    } 
    printf("Done.\n");
    return 0;
}

int delet_info() 
{
    char tmp_na[20];
    int z = 0;
    int new_max = max;
int j = 0;
    printf("\n***** Delet *****\n");
    printf("Delet for name: ");
    scanf("%s", tmp_na); 

    while( z < max ){ 
        if( strcmp(p[z]->name, tmp_na) == 0 ){
            while( z < max ){      
                p[z]= p[z+1];
                z++;
            }
            max--;
            p[max] = NULL;
            //free(p[max]->name); 세그먼트폴트
            //free(p[max]->number);
        }
        z++;
    }
printf("%d\n", z);
printf("%d\n", max);
printf("%s\n", p[max-1]->name);

    if( new_max == max) {
        printf("! No Result\n");
    }

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

int end_info()
{
    int i = 0;
             
    while ( i < max){
        free(p[i]->name);
        free(p[i]->number);
        i++;
        }
    
    // free(p); ??? : 오류, 구조체는 free 안해도 되나?

    exit(0);    
}
