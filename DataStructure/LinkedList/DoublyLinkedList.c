/*
 * DoublyLinkedList.c
 *
 *  Created on: 2018. 5. 11.
 *      Author: sha
 */

#include<stdio.h>

typedef struct DLLNode{
	int data;
	struct DLLNode *next;
	struct DLLNode *prev;
}DLLNode;

//이중연결리스트는 단일연결리스트에서의 q가 필요없다.
void DLLInsert(struct DLLNode **head, int data, int position){
	int k = 1;
	struct DLLNode *temp, *newNode;
	newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
	if(!newNode){//항상 메모리에 에러를 체크
		printf("Memory error");
		return;
	}
	newNode->data = data;
	if(position == 1){//시작 위치에 노드를 삽입
		newNode->next=*head;
		newNode->prev = NULL;
		if(*head)
			(*head)->prev = newNode;
		*head = newNode;
		return;
	}
	temp = *head;
	//루프 후, temp는 마지막 노드의 이전 노드를 가리키거나
	//삽입하고자 하는 위치의 노드의 이전 노드를 가리킴
	while((k<position) && temp->next!=NULL){
		temp = temp->next;
		k++;
	}
	if(k!=position){
		printf("Desired position deos not exist\n");
	}
	newNode->next=temp->next;
	newNode->prev=temp;
	if(temp->next)
		temp->next->prev=newNode;
	temp->next=newNode;
	return;
}

void DDLDelete(struct DLLNode **head, int position){
	struct DLLNode *temp, *temp2;
	temp = *head;
	int k=1;
	if(*head == NULL){
		printf("Lis  t is empty");
		return;
	}
	if(position == 1){
		*head = *head->next;
		if(*head != NULL)
			*head->prev = NULL;
		free(temp);
		return;
	}
	//temp
	while((k<position-1) && temp->next!=NULL){
		temp = temp->next;
		k++;
	}
	if(k!=position-1){
		printf("Desired position does not exist\n");
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	if(temp->next)//중간노드 삭제
		temp->next->prev=temp2;
	free(temp);
	return;
}
