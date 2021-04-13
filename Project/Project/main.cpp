#include "main.h"
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
//#include "heap.h"

using namespace std;

int main() {
	char c;
	int n, flag, min;

	HEAP* heap;
	ElementT element;
	FILE* ifile, * ofile;
	int j, number;

	heap = NULL;

	while (1) {
		c = nextCommand(&n, &flag);
		switch (c) {
		case 's': //STOP
		case 'S':
			//printf("COMMAND: %c\n", c);
			exit(0);
		case 'c': //CREATE 
		case 'C':
			//printf("COMMAND: %c %d\n", c, n);
			heap = heapInit(n);
			break;
		case 'r': //Read
		case 'R':
			//printf("COMMAND: %c %d\n", c, flag);
			ifile = fopen("HEAPinput.txt", "r");

			//Check file is valid
			if (!ifile) {
				printf("Error: cannot open file for reading\n");
				break;
			}

			//Reads first line of file for size 
			fscanf(ifile, "%d", &n);
			if ((heap == NULL) || (heap->capacity < n)) { //n is the first value in the heap which is the size of the heap 
				printf("Error: heap overflow\n");
				break;
			}

			//goes through element in the HEAPinput.txt 
			heap->size = 0;
			for (j = 1; j <= n; j++) {
				fscanf(ifile, "%d", &number);
				element = (ElementT)malloc(sizeof(ELEMENT));
				element->key = number;
				heap->elements[j] = element;
				heap->size++;
			}

			BuildHeap(heap);

			//print number of minHeapify calls ????????????????????????????????????????????????????????
			if (flag == 1) {
				printBuildHeapifyCalls();
			}
			else {
				resetHeapifyCount();
			}

			fclose(ifile);
			break;

		case 'w': //Write
		case 'W':
			//printf("COMMAND: %c\n", c);

			//checks if heap has been initialized 
			if (heap == NULL) {
				printf("Error: cannot write\n");
				break;
			}
			heapWrite(heap);
			break;

		case 'd': //delete minimum 
		case 'D':
			//printf("COMMAND: %c %d\n", c, flag);

			//checks if there is a heap
			if ((heap == NULL) || (heap->size < 1)) { //n is the first value in the heap which is the size of the heap 
				printf("Error: heap is NULL or empty\n");
				break;
			}

			min = ExtractMin(heap);
			printf("Deleted key: %d\n", min);

			if (flag == 1) {
				printExtractHeapifyCalls();
			}
			else {
				resetHeapifyCount();
			}
			break;

		case 'i': //insert
		case 'I':
			//printf("COMMAND: %c %d\n", c, flag);
			if ((heap == NULL) || (heap->capacity == heap->size)) { //n is the first value in the heap which is the size of the heap 
				printf("Error: heap is NULL or full\n");
				break;
			}

			//create ELEMENT
			element = (ElementT)malloc(sizeof(ELEMENT)); //memory allocation
			element->key = flag; //setting input to the key value of ElementT
			Insert(heap, element);

			break;

		case 'k': //Key decrease
		case 'K':
			//printf("COMMAND: %c %d %d\n", c, n, flag);
			if ((heap == NULL) || (flag > heap->size) || (flag < heap->size)) { //n is the first value in the heap which is the size of the heap 
				printf("Error: invalid call to DecreaseKey\n");
				break;
			}
			DecreaseKey(heap, n, flag);

			break;
		case 'p': //Print
		case 'P':
			//printf("COMMAND: %c\n", c);

			//checks if heap has been initialized 
			if (heap == NULL) {
				printf("Error: cannot print\n");
				break;
			}

			//calls heapPrint in heap.cpp
			heapPrint(heap);
			break;
		default:
			break;
		}
	}
	exit(0);
}