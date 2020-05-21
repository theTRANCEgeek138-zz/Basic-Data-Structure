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

//Create new Root node
NODE *ndRoot(int rtVal) {
	NODE *newRoot = ndalloc();
	newRoot->VALUE = rtVal;
	newRoot->PAR = NULL;
	newRoot->NXSIB = NULL;
	newRoot->FCHD = NULL;
	return newRoot;
}

//Add a child to to a node, next to the last existing sibling
NODE *addChildtoLast (NODE *targetNode,int val) {
	//If targetNode's pointer is NULL, consider this as an error, return NULL
	if (targetNode == NULL) return NULL;

	NODE *newNode = ndalloc();
	newNode->VALUE = val;
	//Set newNode relatives
	newNode->PAR = targetNode;
	newNode->FCHD = NULL;
	//Find the closest sibling
	NODE *nearestSib = targetNode->FCHD;
	if (nearestSib == NULL) 
		//If first child pointer is NULL, newNode is the first child
		targetNode->FCHD = newNode;
	else {
		while (nearestSib->NXSIB != NULL) nearestSib = nearestSib->NXSIB;
		nearestSib->NXSIB = newNode;
	}
	newNode->NXSIB = NULL;
	return newNode;
}

//Add a child to a node, next to specified child node
NODE *addChildtoPos (NODE *targetNode,NODE *siblingNode,int val) {
	NODE *newNode = ndalloc(); 
	newNode->VALUE = val;
	//Set new node relatives
	newNode->PAR = targetNode;
	newNode->FCHD = NULL;
	if (siblingNode != NULL) {
		newNode->NXSIB = siblingNode->NXSIB;
		siblingNode->NXSIB = newNode;
	} else {
		//If siblingNode pointer is NULL, it means the new node is added to 1st child position
		newNode->NXSIB = targetNode->FCHD;
		targetNode->FCHD = newNode;
	}
	return newNode;
}

NODE *addChildrtoNode (NODE *parentNode,int childrNum) {
	NODE firstChild;
	firstChild.NXSIB = NULL;
	NODE *currentNode = &firstChild;
	for (int i=0;i<childrNum;i++) {
		NODE *newNode = ndalloc();
		//Input node value
		printf ("Node no.%d: ",i);
		int ndVal;scanf ("%d",&ndVal);
		newNode->VALUE = ndVal;
		newNode->PAR = parentNode;
		currentNode->NXSIB = newNode;
		currentNode = newNode;
	}
	return firstChild.NXSIB;
}

int main() {
	//Initiate startNode
	startNode = NULL;
	printf ("%d",startNode->VALUE);
	printf ("\nEnd of Program. Exit now\n");
	return 0;
}
