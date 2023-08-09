#include "stdio.h"
#include "ctype.h"
void EX_2(){
	char in,lc;
	printf("Enter an alphabet: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &in);

	lc = tolower(in);
	if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
		printf("%c is a vowel.", in);
	else
		printf("%c is a consonant.", in);
}
