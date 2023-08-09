#include <stdio.h>
void EX_1(){
	int in;
	printf("Enter an integer you want to check: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &in);
	printf("%d is %s", in, in%2 == 1? "odd":"even");
}
