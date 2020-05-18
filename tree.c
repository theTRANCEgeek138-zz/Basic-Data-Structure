#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int VALUE;
	struct element *FCHD;
	struct element *NXSIB;
	struct element *PAR;
} NODE;

NODE startNode;
int maxDepth;

//Add a child to to a node, next to the last existing sibling
NODE *addChildtoLast (NODE *parentNode,int val) {
	NODE *newNode = (NODE*) malloc(sizeof(NODE));
	newNode->VALUE = val;
	//Set newNode relatives
	newNode->PAR = parentNode;
	newNode->FCHD = NULL;
	//Find the closest sibling
	NODE *nearestSib = parentNode->FCHD;
	if (nearestSib == NULL) 
		//If first child pointer is NULL, newNode is the first child
		parentNode->FCHD = newNode;
	else {
		while (nearestSib != NULL) nearestSib = nearestSib->NXSIB;
		nearestSib->NXSIB = newNode;
	}
	newNode->NXSIB = NULL;
	return newNode;
}

//Add a sibling to a node, next to specified sibling node
NODE *addSiblingtoPos (NODE *parentNode,NODE *siblingNode,int val) {
	NODE *newNode = (NODE*) malloc(sizeof(NODE));
	newNode->VALUE = val;
	newNode->PAR = parentNode;
	newNode->FCHD = NULL;
	//Set new node relatives
	if (siblingNode != NULL) {
		newNode->NXSIB = siblingNode->NXSIB;
		siblingNode->NXSIB = newNode;
	} else {
		//If siblingNode pointer is NULL, it means the new node is added to 1st child position
		newNode->NXSIB = parentNode->FCHD;
		parentNode->FCHD = newNode;
	}
	return newNode;
}

//Create Tree or Sub-tree starts with specified ROOT node
void initTree (NODE *rootNode,int currentDepth) {
	if (currentDepth == maxDepth) return;
	printf ("How many children: ");
	int childrNum; scanf ("%d",&childrNum);
	NODE *newNode = NULL;
	//Adding "childrNum" children to the root node
	for (int i=0;i<childrNum;i++) {
		printf ("Depth %d\nChild no.%d: ",currentDepth,i);
		int childVal; scanf ("%d",&childVal);
		newNode = addSiblingtoPos (rootNode,newNode,childVal);
		initTree (newNode,currentDepth+1);
	}
}

int main() {
	scanf ("%d",&maxDepth);
	initTree (&startNode,0);
	printf ("End of Program. Exit now\n");
	return 0;
}
