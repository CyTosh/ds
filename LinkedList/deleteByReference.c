// ChandyShot

#include <stdio.h>
#include <stdlib.h>

#define MEM_ERR 	printf("%s\n", "Memory Error...!!")
#define GET_NODE 	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node))
#define ENDL 		printf("\n")

struct Node {
	int data;
	struct Node *next;
};

void print(struct Node *head){
	while(head){
		printf("%d", head->data);
		head = head->next;
		if(head)
			printf(" --> ");
	}
	ENDL;
}

void insertAtHead(struct Node **head_ref, int data){
	GET_NODE;
	if(!newNode){
		MEM_ERR;
		return;
	}
	newNode->data = data;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

void deleteLastNode(struct Node **head_ref){
	struct Node *current = *head_ref;
	if(current->next == NULL){
		*head_ref = NULL;
		return;
	}

	while(current->next->next != NULL) current = current->next;

	free(current->next);
	current->next = NULL;
}

void deleteByReference(struct Node **head_ref, struct Node **ref){
	if(!(*head_ref)){
		printf("error : Empty List!!!\n");
		return;
	}
	if((*ref)->next == NULL){	// if last node
		deleteLastNode(head_ref);
		return;
	}
	(*ref)->data = ((*ref)->next)->data;
	struct Node *temp = (*ref)->next;
	(*ref)->next = ((*ref)->next)->next;
	free(temp);
}

int main(){
	struct Node *head = NULL;
	insertAtHead(&head, 5);
	insertAtHead(&head, 4);
	insertAtHead(&head, 3);
	insertAtHead(&head, 2);
	insertAtHead(&head, 1);
	insertAtHead(&head, 0);
	print(head);
	deleteByReference(&head, &(head->next));
	print(head);
	deleteByReference(&head, &(head->next->next->next->next));
	print(head);
	return 0;
}
