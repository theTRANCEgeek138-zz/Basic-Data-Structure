#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
		int VALUE;
		struct stackNode *LOWER;
} SNODE;

SNODE *topNode = NULL;

//Add Node to the top of the stack
void addNode (int addVal) {
	SNODE *newNode = (SNODE*) malloc (sizeof(SNODE));
	newNode->VALUE = addVal;
	newNode->LOWER = topNode;
	//Set the new node as the top Node
	topNode = newNode;
}

void printStack() {
	SNODE *printNode = topNode;
	while (printNode != NULL) {
		printf ("%d ",printNode->VALUE);
		printNode = printNode->LOWER;
	}
}

int main() {
	//Input	
	printf ("Input N: ");
	int n; scanf ("%d",&n);
	for (int i=0;i<n;i++){
			printf ("no. %d: ",i);
			int val; scanf ("%d",&val);
			addNode (val);
	}
	//Output
	printStack();

	printf ("\nEnd of program. Exit now.\n");
	return 0;
}
