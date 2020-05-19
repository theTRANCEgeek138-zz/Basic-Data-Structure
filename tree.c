#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int VALUE;
	struct element *FCHD;
	struct element *NXSIB;
	struct element *PAR;
} NODE;

NODE startNode;

//Quick memory allocating function for "NODE" type
NODE *ndalloc() {
	return (NODE*) malloc(sizeof(NODE));
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

//Add a sibling to a node, next to specified sibling node
NODE *addSiblingtoPos (NODE *targetNode,NODE *siblingNode,int val) {
	//If targetNode's pointer is NULL, consider this as an error, return NULL
	if (targetNode == NULL) return NULL;

	NODE *newNode = ndalloc(); 
	newNode->VALUE = val;
	newNode->PAR = targetNode;
	newNode->FCHD = NULL;
	//Set new node relatives
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

//Create child(s) starts with target Node
void createChildr (NODE *targetNode,int childrNum) {
	for (int i=0;i<childrNum;i++) {
		printf ("Child no.%d's value: ",i);
		int childVal; scanf ("%d",&childVal);
		NODE *newNode = addChildtoLast (targetNode,childVal);
	}
}

int main() {
	//Initiate startNode
	startNode.VALUE = -1;
	startNode.FCHD = NULL;
	startNode.PAR = NULL;
	startNode.NXSIB = NULL;
	
	printf ("End of Program. Exit now\n");
	return 0;
}
