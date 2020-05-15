/*
	Double Ended Queue is the type of queue data structure that allows adding an Item to a queue 
	in the first position and the last position.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queueItem {
	int VALUE;
	struct queueItem *NEXT;
}ITEM;

ITEM startItem,*lastItem;

void printQueue() {
	ITEM *printItem = startItem.NEXT;
	while (printItem != NULL) {
		printf ("%d ",printItem->VALUE);
		printItem = printItem->NEXT;
	}
}

//Add an item to the first position
void addItemFirst (int inVal) {
	ITEM *newItem = (ITEM*) malloc (sizeof(ITEM));
	newItem->VALUE = inVal;
	newItem->NEXT = startItem.NEXT;
	startItem.NEXT = newItem;
}

//Add an item to the last position
void addItemLast (int inVal) {
	ITEM *newItem = (ITEM*) malloc (sizeof(ITEM));
	newItem->VALUE = inVal;
	newItem->NEXT = NULL;
	lastItem->NEXT = newItem;
	lastItem = newItem;
}

//Print and remove Item from queue (Processing a Queue)
void processQueue() {
	ITEM *targetItem = startItem.NEXT;
	printf ("%d",targetItem->VALUE);
	startItem.NEXT = targetItem->NEXT;
	free (targetItem);
}

int main() {
	startItem.VALUE = -1;
	startItem.NEXT = NULL;
	lastItem = &startItem;
	
	//Input
	printf ("Input N: ");
	int n; scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		int val; 
		printf ("Item no. %d: ",i); scanf ("%d",&val);
		addItemLast (val);
	}
	//Output
	printQueue();
	
	printf ("\nEnd of Program. Exit now.\n");
	return 0;
}
