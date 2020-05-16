#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
	int VALUE;
	struct node *NEXT;
} ITEM;

ITEM startItem, *lastItem;

void printQueue () {
	ITEM *printItem = startItem.NEXT;
	while (printItem != NULL) {
		printf ("%d ",printItem->VALUE);
		printItem = printItem->NEXT;
	}
}

void addToQueue (int val) {
	ITEM *newItem = (ITEM*) malloc (sizeof(ITEM));
	newItem->VALUE = val;
	newItem->NEXT = NULL;
	lastItem->NEXT = newItem;
	lastItem = newItem;
}

void processQueue () {
	//This function process (output) and remove the current first item in queue
	printf ("%d ",startItem.NEXT->VALUE);
	ITEM *doneItem = startItem.NEXT;
	startItem.NEXT = doneItem->NEXT;
	free (doneItem);
}

//Calculate the queue size
int queueSize() {
	ITEM *currentItem = startItem.NEXT;
	int size = 0;
	while (currentItem != NULL) {
		size++;
		currentItem = currentItem->NEXT;
	}
	return size;
}

int main() {
	startItem.VALUE = 0; 
	startItem.NEXT = NULL;
	lastItem = &startItem;
	
	//Input a queue
	int n;
	printf ("Input N: "); scanf ("%d",&n);
	for (int i=0;i<n;i++) {
		int newVal;
		scanf ("%d",&newVal);
		addToQueue (newVal);
	}
	
	//Print the queue
	printQueue();
	printf ("\n");

	//Process one Item and print the after queue
	processQueue();
	printf ("\n");
	printQueue();
	printf ("\n");

	//Calculate queue size
	int size = queueSize();
	printf ("%d",size);

	printf ("\nEnd of Program, exit now.\n");
	return 0;
}
