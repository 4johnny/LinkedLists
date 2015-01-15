//
//  main.c
//  LinkedLists
//
//  Created by Johnny on 2015-01-14.
//  Copyright (c) 2015 Empath Solutions. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedListNode {
	int data;
	struct LinkedListNode* next;
} LinkedListNode;


LinkedListNode* createLLNode(int data, LinkedListNode* next) {
	LinkedListNode* newLL = malloc(sizeof(LinkedListNode));
	newLL->data = data;
	newLL->next = next;
	return newLL;
}

void freeLLNode(LinkedListNode** p_llNode) {
	if (p_llNode == NULL || *p_llNode == NULL) return;
	free(*p_llNode);
	*p_llNode = NULL;
}

void freeLL(LinkedListNode* ll) {
	if (ll == NULL) return;
	freeLL(ll->next);
	freeLLNode(&ll);
}

void printLLNode(LinkedListNode *llNode) {
	if (llNode == NULL) {
		printf("(NULL)");
		return;
	}
	printf("(%d)", llNode->data);
}

void printLL(LinkedListNode *ll) {
	if (ll == NULL) return;
	printLLNode(ll);
	printLL(ll->next);
}

LinkedListNode* searchLL(LinkedListNode* ll, int target) {
	if (ll == NULL) return NULL;
	if (ll->data == target) return ll;
	return searchLL(ll->next, target);
}

int main(int argc, const char * argv[]) {

	// Build up LL in reverse order.
	LinkedListNode* ll = createLLNode(5, NULL);
	ll = createLLNode(4, ll);
	ll = createLLNode(3, ll);
	ll = createLLNode(2, ll);
	ll = createLLNode(1, ll);

	// Show stuff
	printLL(ll);
	printf("\n");
	LinkedListNode* targetLLNode = searchLL(ll, 2);
	printLLNode(targetLLNode);
	printf("\n");
	
	// Free memory.
	freeLL(ll);
	
    return 0;
}
