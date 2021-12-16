#include <stdio.h>
#include <stdlib.h>


int main()
{
	char* ptr;

	printf("%p\n", &ptr);	// 포인터 ptr의 주소값
	printf("%p\n", ptr);	// 포인터 ptr이 가지고 있는 값(쓰레기 주소)
	printf("%c\n", *ptr);	// 쓰레기 주소에 현재 있는 값()

	ptr = (char *)malloc(sizeof(char));
	*ptr = 'A';
	printf("ptr has -> '%c'\n", *ptr);

	// 아래 세줄을 주석을 풀고 실행시키면 leaks가 메모리 누수를 표시합니다.
	//ptr = (char *)malloc(sizeof(char));
	//*ptr = 'B'; 
	//printf("ptr has -> '%c'\n", *ptr);

	while(1) // free 해주지 않으면 영원히 서랍속으로, leaks에도 나오지 않음. 지금은 덮어썼으니까 나오는데
		;
}
