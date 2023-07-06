#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <dlfcn.h>
#include <string.h>

char* dll(char* pathname, void** dp,int libs) {

	char* (*getname)(void);
	char* name;

	dp[libs] = dlopen(pathname, RTLD_LAZY);
	if (!dp[libs]) {
		fputs(dlerror(), stderr);
		exit(1);
	}

	getname = dlsym(dp[libs], "get");
	if(!getname) {
		fputs(dlerror(), stderr);
		exit(1);
	}

	name = (*getname)();
	
	return name;

}

int main() {
	int func = 0;
	int a, b, result, libs = 0;

	char* pathname = (char*)malloc(sizeof(char) * 32);
	char** funcname = (char**)malloc(0);
	void** dps = (void**)malloc(0);;
	int(*function)(int, int);

	puts("Enter the lib (./libname.so) or q to continue: \n");

	while (1) {
		fgets(pathname, 31, stdin);
		pathname[strcspn(pathname, "\n")] = '\0';

		if (pathname[0] == 113)
			break;

		libs++;
		funcname = (char**)realloc(funcname, sizeof(char*) * libs);
		dps = (void**)realloc(dps, libs * sizeof(void**));
		funcname[libs - 1] = dll(pathname, dps, libs - 1);

		system("clear");
	}

	do {

		for (int i = 0; i < libs; i++) {
			printf("enter the %d, for %s: \n", i, funcname[i]);
		}
		puts("press 5 for exit\n");
		scanf("%d", &func);
		getchar();

		if (func == 5)
			break;

		system("clear");
		puts("enter the first term: ");
		scanf("%d", &a);
		getchar();
		puts("enter the second term: ");
		scanf("%d", &b);
		getchar();

		function = dlsym(dps[func], funcname[func]);
		result = function(a, b);

		printf("answer = %d\n ", result);

	} while (1);


	for (int i = 0; i < libs; i++) {
		dlclose(dps[i]);
	}

	return 0;

}