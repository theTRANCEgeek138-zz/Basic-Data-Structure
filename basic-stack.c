#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
		int VALUE;
		struct StackNode *LOWERNODE;
		struct StackNode *UPPERNODE;
} SNODE;


void setNodeData (SNODE *targetNode,int targetValue,SNODE *lowNode,SNODE *upNode) {
		targetNode->VALUE = targetValue;
		targetNode->LOWERNODE = lowNode;
		targetNode->UPPERNODE = upNode;
}

int main() {
	SNODE *topNode = NULL;
	printf ("Input N: ");
	int n; scanf ("%d",&n);

	for (int i=0;i<n;i++){
			printf ("no. %d: ",i);
			int inVal; scanf ("%d",&inVal);

			SNODE *newNode = (SNODE*) malloc (sizeof(SNODE));
			setNodeData (newNode,inVal,topNode,NULL);
			if (topNode != NULL) topNode->UPPERNODE = newNode;
			topNode = newNode;
	}

	SNODE *currentNode = topNode;
	while (currentNode != NULL) {
		printf ("%d ",currentNode->VALUE);
		currentNode = currentNode->LOWERNODE;
	}

	printf ("\nEnd of program. Exit!");
	return 0;
}
