/*
 * SinglyLinkedList.c
 *
 *  Created on: 2018. 5. 11.
 *      Author: sha
 */
#include<stdio.h>

typedef struct ListNode{//������ �� typedef �ʿ�! �ƴϸ� struct ListNode List���� �پ�� ��
	int data;
	struct ListNode *next;
}ListNode;

void InserInLinkedList(struct ListNode **head, int data, int position){
					   //���, ���ο� ����� ����Ÿ ��, ���ο� ��带 �߰��ϰ� ���� ��ġ
	int k=1;
	struct ListNode *p, *q, *newNode;
	newNode = (ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode) {
		printf("MemoryError");
		return;
	}
	newNode->data = data;
	p = *head;//p�� ����Ʈ�� ù ��° ���

	//���� ������ ����
	if(position == 1){
		newNode->next=p;//newNode�� next�� p�� ����
		*head=newNode;//����� newNode�� ����Ű�� ��
	}
	else{//���� ������ ��ġ���� ����� Ž��
		//q -> ���ο� ��� -> p �� ���� ����!
		while((p!=NULL) && (k<position)){
			k++;
			q=p;
			p=p->next;
		}
		q->next=newNode;
		newNode->next=p;
	}
}

void DeletedFromLinkedList(struct ListNode **head, int position){
	int k = 1;
	struct ListNode *p, *q;
	if(*head == NULL){
		printf("List Empty");
		return;
	}
	p=*head;
	if(position == 1){//ó������
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		//�����ϰ��� �ϴ� ��ġ���� ����� Ž��
		while ((p=!NULL)&&(k<position)){
			k++;
			q=p;
			p=p->next;
		}//p : ������ ���, q : ������ ��� ������ ���
		if(p==NULL)//������
			printf("Position does not exist.");
		else{//�߰�����
			q->next = p->next;
			free(p);
		}
	}
}

