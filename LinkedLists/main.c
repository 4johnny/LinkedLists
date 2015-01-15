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

LinkedListNode* appendToLL(LinkedListNode* ll, int data) {
	if (ll == NULL) return createLLNode(data, NULL);
	ll->next = appendToLL(ll->next, data);
	return ll;
}

LinkedListNode* removeFromLL(LinkedListNode* currLLNode, LinkedListNode* prevLLNode, LinkedListNode* targetLLNode) {
	if (targetLLNode == NULL) return currLLNode;
	if (currLLNode == NULL) return prevLLNode;
	if (currLLNode == targetLLNode) {
		if (prevLLNode == NULL) {
			LinkedListNode* next = currLLNode->next;
			freeLLNode(&currLLNode);
			return next;
		}
		prevLLNode->next = currLLNode->next;
		freeLLNode(&currLLNode);
		return prevLLNode;
	}
	removeFromLL(currLLNode->next, currLLNode, targetLLNode);
	return currLLNode;
}

int main(int argc, const char * argv[]) {
	
	// Build list.
	LinkedListNode* ll = NULL;
	ll = appendToLL(ll, 1);
	ll = appendToLL(ll, 2);
	ll = appendToLL(ll, 3);
	ll = appendToLL(ll, 4);
	ll = appendToLL(ll, 5);
	
	//	// Build up LL in reverse order.
	//	LinkedListNode* ll = createLLNode(5, NULL);
	//	ll = createLLNode(4, ll);
	//	ll = createLLNode(3, ll);
	//	ll = createLLNode(2, ll);
	//	ll = createLLNode(1, ll);
	
	// Show list and searched item.
	printLL(ll);
	printf("\n");
	LinkedListNode* targetLLNode = searchLL(ll, 2);
	printLLNode(targetLLNode);
	printf("\n");
	
	// Show list after item removed.
	ll = removeFromLL(ll, NULL, targetLLNode);
	//	ll = removeFromLL(ll, NULL, searchLL(ll, 2));
	//	ll = removeFromLL(ll, NULL, searchLL(ll, 3));
	//	ll = removeFromLL(ll, NULL, searchLL(ll, 4));
	//	ll = removeFromLL(ll, NULL, searchLL(ll, 5));
	printLL(ll);
	printf("\n");
	
	// Free memory.
	freeLL(ll);
	
	return 0;
}
