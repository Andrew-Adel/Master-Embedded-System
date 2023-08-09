#include "stdio.h"

void EX_5(){
	char in;
	printf("Enter an alphabet: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &in);
	if ((in >= 97 && in <= 122) || (in >= 65 && in <= 90))
		printf("%c is an alphabet", in);
	else
		printf("%c is not an alphabet", in);

}
