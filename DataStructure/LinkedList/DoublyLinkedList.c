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

//���߿��Ḯ��Ʈ�� ���Ͽ��Ḯ��Ʈ������ q�� �ʿ����.
void DLLInsert(struct DLLNode **head, int data, int position){
	int k = 1;
	struct DLLNode *temp, *newNode;
	newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
	if(!newNode){//�׻� �޸𸮿� ������ üũ
		printf("Memory error");
		return;
	}
	newNode->data = data;
	if(position == 1){//���� ��ġ�� ��带 ����
		newNode->next=*head;
		newNode->prev = NULL;
		if(*head)
			(*head)->prev = newNode;
		*head = newNode;
		return;
	}
	temp = *head;
	//���� ��, temp�� ������ ����� ���� ��带 ����Ű�ų�
	//�����ϰ��� �ϴ� ��ġ�� ����� ���� ��带 ����Ŵ
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
	if(temp->next)//�߰���� ����
		temp->next->prev=temp2;
	free(temp);
	return;
}
