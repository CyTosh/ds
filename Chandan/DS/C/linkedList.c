// Because You look Gorgeous in Black...

/*	COPYRIGHT : DO the FUCK you wanna do... 

	// Thanks for GEEKSFORGEEKS.COM
	
	DOCS	=>	function names are self explanatory
	
	// Print
	void printList(struct Node *head);
	void traceList(struct Node *current);	// Help to debug
	void printReverse(struct Node *current);

	// Insertion
	void insertAtHead(struct Node **head_ref, int data);
	void insertAtTail(struct Node **head_ref, int data);
	void insertAfterNode(struct Node **head_ref, struct Node **node, int data);

	// Deletion
	void deleteNode(struct Node **head_ref, int data);
	void deleteNthNode(struct Node **head_ref, int data);	// N => index [0, no. of nodes - 1)
	void delete(struct Node **head_ref); 	// Delete whole List

	// Length
	void length(struct Node *head);

	// Search
	int isPresent(struct Node *head_ref, int data);	// returns 1 if data is present in List, else return 0

	// Swapping
	void swapNodesHaving(struct Node **head_ref, int x, int y);	// swaps nodes having data x and y

	// Reversing
	void reverseRecursive(struct Node **head_ref);
	void reverseIterative(struct Node **head_ref)
	
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};


void insertAtHead(struct Node **head_ref, int data){
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Overflow Error !\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = *head_ref;
	*head_ref = newNode;
}

void insertAtTail(struct Node **head_ref, int data){

	if(*head_ref == NULL){
		insertAtHead(head_ref, data);
		return;
	}

	struct Node *current = *head_ref;

	while(current->next != NULL){
		current = current->next;
	}

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Overflow Error !\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	current->next = newNode;
}


void printList(struct Node *current){
	printf("List is : ");
	while(current){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// void traceList(struct Node *current){
// 	printf("Trace : ");
// 	while(current){
// 		printf("%u  ", (unsigned int)current);
// 		current = current->next;
// 	}
// 	printf("\n");
// }


void insertAfterNode(struct Node **head_ref, struct Node **node, int data){
	struct Node *current = *head_ref;
	if(!current){
		printf("Empty List!!!\n");
		return;
	}

	while(current != NULL && current != *node) current = current->next;

	if(current == NULL){
		printf("Node not found!!!\n");
		return;
	}

	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = current->next;
	current->next = newNode;
}

void deleteNode(struct Node **head_ref, int data){
	struct Node *current = *head_ref;
	if(!current){
		printf("Empty List!!!\n");
		return;
	}

	if(current->data == data){
		struct Node *temp = current;
		current = current->next;
		*head_ref = current;
		free(temp);
		return;
	}

	while(current->next != NULL && current->next->data != data)
		current = current->next;

	if(current->next == NULL){
		printf("Node not Found!!!\n");
		return;
	}

	struct Node *temp = current->next;
	current->next = current->next->next;
	free(temp);
}

void deleteNthNode(struct Node **head_ref, int n){
	if(n<0){
		printf("Invalid Argument!!!\n");
		return;
	}

	struct Node *current = *head_ref;
	if(n==0){
		struct Node *temp = current;
		current = current->next;
		*head_ref = current;
		free(temp);
		return;
	}

	int cnt = 0;
	while(current->next != NULL && ++cnt < n) current = current->next;

	if(cnt != n){
		printf("Not Enough Nodes!!!\n");
		return;
	}

	struct Node *temp = current->next;
	current->next = current->next->next;
	free(temp);
}

int length(struct Node *current){
	int len = 0;
	while(current){
		len++;
		current = current->next;
	}
	return len;
}

int isPresent(struct Node *current, int data){
	while(current){
		if(current->data == data)
			return 1;
		current = current->next;
	}
	return 0;
}

void swapNodesHaving(struct Node **head_ref, int x, int y){
	if(x==y)
		return;

	struct Node *Xnode = *head_ref;
	struct Node *PrevXnode = NULL;
	struct Node *Ynode = *head_ref;
	struct Node *PrevYnode = NULL;

	while(Xnode && Xnode->data != x){
		PrevXnode = Xnode;
		Xnode = Xnode->next;
	}

	while(Ynode && Ynode->data != y){
		PrevYnode = Ynode;
		Ynode = Ynode->next;
	}

	if(Xnode == NULL || Ynode == NULL){
		printf("Values not found!!!\n");
		return;
	}

	if(PrevYnode == NULL || PrevXnode == NULL){
		if(PrevXnode == NULL){
			*head_ref = Ynode;
			PrevYnode->next = Xnode;
		}
		else{
			*head_ref = Xnode;
			PrevXnode->next = Ynode;
		}
		struct Node *temp = Ynode->next;
		Ynode->next = Xnode->next;
		Xnode->next = temp;
		return;
	}

	PrevXnode->next = Ynode;
	PrevYnode->next = Xnode;

	struct Node *temp = Ynode->next;
	Ynode->next = Xnode->next;
	Xnode->next = temp;

}


void delete(struct Node **head_ref){
	struct Node *current = *head_ref;
	if(!current){
		return;
	}

	struct Node *prev = NULL;
	while(current){
		prev = current;
		free(prev);
		current = current->next;
	}

	*head_ref = NULL;
}

void reverseIterative(struct Node **head_ref){
	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	struct Node *prev = NULL;
	struct Node *current = *head_ref;
	struct Node *next = current->next;

	while(current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void reverseRecursiveHelper(struct Node **head_ref, struct Node *current){
	if(current->next == NULL){
		*head_ref = current;
		return;
	}

	reverseRecursiveHelper(head_ref, current->next);

	current->next->next = current;
	current->next = NULL;
}

void reverseRecursive(struct Node **head_ref){
	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	reverseRecursiveHelper(head_ref, (*head_ref));
}

void printReverse(struct Node *current){
	if(current == NULL){
		printf("List is : ");
		return;
	}
	printReverse(current->next);
	printf("%d ", current->data);
}


int main(){
	struct Node *head = NULL;
	insertAtHead(&head, 1);
	insertAtTail(&head, 2);
	insertAtTail(&head, 3);
	insertAtTail(&head, 4);
	insertAtTail(&head, 5);
	insertAtTail(&head, 6);
	insertAtTail(&head, 7);
	insertAtTail(&head, 8);
	insertAtTail(&head, 9);
	printList(head);

	//reverseRecursive(&head);
	// printReverse(head);
	// printf("\n");
	// printf("%d\n", isPresent(head, 5));
	// printList(head);
	// deleteNthNode(&head, 1);
	// traceList(head);
	// insertAfterNode(&head, &(head), 9);
	// deleteNode(&head, 1);
	printList(head);
	return 0;
}
