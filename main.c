#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "functions.h"

int main() {

	char exit = 1;
	int func = 0;
	int a, b, result;

	do {

		puts("press 1 for sum\n"
			"press 2 for sub\n"
			"press 3 for mul\n"
			"press 4 for div\n"
			"press 5 for exit\n");
		scanf("%d", &func);
		getchar();

		switch (func) {

		case 1:
			system("clear");
			puts("enter the first term: ");
			scanf("%d", &a);
			getchar();
			puts("enter the second term: ");
			scanf("%d", &b);
			getchar();

			result = sum(a, b);
			printf("answer = %d\n", result);
			break;

		case 2:
			system("clear");
			puts("enter the first term: ");
			scanf("%d", &a);
			getchar();
			puts("enter the second term: ");
			scanf("%d", &b);
			getchar();

			result = sub(a, b);
			printf("answer = %d\n", result);
			break;

		case 3:
			system("clear");
			puts("enter the first term: ");
			scanf("%d", &a);
			getchar();
			puts("enter the second term: ");
			scanf("%d", &b);
			getchar();

			result = mult(a, b);
			printf("answer = %d\n", result);
			break;

		case 4:
			system("clear");
			puts("enter the first term: ");
			scanf("%d", &a);
			getchar();
			puts("enter the second term: ");
			scanf("%d", &b);
			getchar();

			result = divide(a, b);
			printf("answer = %d\n", result);
			break;

		case 5:
			exit = 0;
			break;
		}

	} while (exit);

	return 0;

}