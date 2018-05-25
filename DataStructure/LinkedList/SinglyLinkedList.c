/*
 * SinglyLinkedList.c
 *
 *  Created on: 2018. 5. 11.
 *      Author: sha
 */
#include<stdio.h>

typedef struct ListNode{//정의할 때 typedef 필요! 아니면 struct ListNode List같이 붙어야 함
	int data;
	struct ListNode *next;
}ListNode;

void InserInLinkedList(struct ListNode **head, int data, int position){
					   //헤더, 새로운 노드의 데이타 값, 새로운 노드를 추가하고 싶은 위치
	int k=1;
	struct ListNode *p, *q, *newNode;
	newNode = (ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode) {
		printf("MemoryError");
		return;
	}
	newNode->data = data;
	p = *head;//p는 리스트의 첫 번째 노드

	//시작 지점에 삽입
	if(position == 1){
		newNode->next=p;//newNode의 next를 p에 연결
		*head=newNode;//헤더가 newNode를 가리키게 함
	}
	else{//삽입 지점의 위치까지 목록을 탐색
		//q -> 새로운 노드 -> p 로 넣을 거임!
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
	if(position == 1){//처음에서
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		//삭제하고자 하는 위치까지 목록을 탐색
		while ((p=!NULL)&&(k<position)){
			k++;
			q=p;
			p=p->next;
		}//p : 삭제할 노드, q : 삭제할 노드 이전의 노드
		if(p==NULL)//끝에서
			printf("Position does not exist.");
		else{//중간에서
			q->next = p->next;
			free(p);
		}
	}
}

