#pragma warning(disable : 4996)
#include "util.h"

int nextCommand(int* n, int* f) {
	char c;

	//printf("BGN nextcommand\n");

	while (1) {
		scanf("%c", &c);
		while (c == '\n' || c == 't' || c == ' ') {
			scanf("%c", &c);
		}

		if (c == 'S' || c == 's') {
			//'S' for STOP
			break;
		}

		if (c == 'C' || c == 'c') {
			//'C' for CREATE need to read in "int n"
			scanf("%d", n);
			if (*n == 0) {
				printf("Warning in nextCommand: read in int %d\n", *n);
			}
			break;
		}

		if (c == 'r' || c == 'R') {
			//'R' for READ 
			scanf("%d", f);
			/*if (*f == 0) {
				printf("Warning in nextCommand: read in int %d\n", *f);
			}*/
			break;
		}

		if (c == 'p' || c == 'P') {
			//'P' for WRITE
			break;
		}

		if (c == 'w' || c == 'W') {
			//'W' for WRITE
			break;
		}

		if (c == 'i' || c == 'I') {
			scanf("%d", f);
			break;
		}

		if (c == 'd' || c == 'D') {
			//'D' for delete 
			scanf("%d", f);
			/*if (*f == 0) {
				printf("Warning in nextCommand: read in int %d\n", *f);
			}*/
			break;
		}

		if (c == 'k' || c == 'K') {
			//'D' for delete 
			scanf("%d %d", n, f);
			/*if (*f == 0) {
				printf("Warning in nextCommand: read in int %d\n", *f);
			}*/
			break;
		}

		printf("Warning in nextCommand: invalid input \n");
		break;
	}

	//printf("END nextcommand\n");

	return c;
}