#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int VALUE;
	struct element *FCHD; //First child Node pointer
	struct element *NXSIB;//Next sibling Node pointer
	struct element *PAR;  //Parent Node pointer
} NODE;

NODE *startNode;

//Quick memory allocating function for "NODE" type
NODE *ndalloc() {
	return (NODE*) malloc(sizeof(NODE));
}

//Create new empty Root node with a value
NODE *ndRoot(int rtVal) {
	NODE *newRoot = ndalloc();
	newRoot->VALUE = rtVal;
	newRoot->PAR = NULL;
	newRoot->NXSIB = NULL;
	newRoot->FCHD = NULL;
	return newRoot;
}

//Add children to Node
NODE *addChildrtoNode (NODE *targetNode,int childrNum) { //targetNode aka rootNode, parentNode
	NODE firstChild;
	firstChild.NXSIB = NULL;
	NODE *currentNode = &firstChild;
	//Create childrNum childrens for targetNode
	for (int i=0;i<childrNum;i++) {
		NODE *newNode = ndalloc();
		//Input node value
		printf ("Node no.%d: ",i);
		int ndVal;scanf ("%d",&ndVal);
		//Set relatives
		newNode->VALUE = ndVal;
		newNode->PAR = targetNode;
		currentNode->NXSIB = newNode;
		currentNode = newNode;
	}
	return firstChild.NXSIB; //Return the pointer to first child
}

//Create a Tree/Sub-tree, recursively
NODE *RcreateTree (NODE *targetNode,int childrNum) { //targetNode aka rootNode, parentNode
	//If childrNum = 0 (no children will be created), return NULL
	if (childrNum == 0) return NULL;
	NODE firstChild; firstChild.NXSIB = NULL;
	NODE *currentNode = &firstChild;
	//Create childrNum children for targetNode
	for (int i=0;i<childrNum;i++) {
		NODE *newNode = ndalloc();
		//Input node value
		printf ("Node no.%d: ",i);
		int ndVal;scanf ("%d",&ndVal);
		//Set relatives
		newNode->VALUE = ndVal;
		newNode->PAR = targetNode;
		currentNode->NXSIB = newNode;
		currentNode = newNode;
	}

	//Create a new sub-tree rooted by children no.0 -> no. (childrNum-1)
	currentNode = firstChild.NXSIB;
	for (int i=0;i<childrNum;i++) {
		printf ("Child no.%d:\n",i);
		printf ("How many child(s): "); int ndChildr;scanf("%d",&ndChildr);
		//Create Sub-tree for current node
		RcreateTree (currentNode,ndChildr);
		//Move to the next sibling node
		currentNode = currentNode->NXSIB;
	}
}

int main() {
	//Initiate startNode
	startNode = NULL;
	
	printf ("\nEnd of Program. Exit now\n");
	return 0;
}
