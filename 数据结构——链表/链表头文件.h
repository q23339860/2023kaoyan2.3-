#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <random>
#include<math.h>
typedef int Elemtype;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef struct LNode {
	Elemtype data;
	LNode* next;
}LNode, * Linklist;

Linklist InitLinkList(Linklist &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = NULL;
	return L;
}

Linklist List_HeadInsert(Linklist& L) {
	Linklist s;
	int n=0;
	int choice;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = NULL;
	printf("请输入链表长度：\n");
	scanf_s("%d", &n);
	printf("输入1生成随机链，表输入2生成指定链表：\n");
	scanf_s("%d", &choice);
	
	if (choice == 1) {
		time_t t;
		srand(time(&t));
		int b;
		do {
			printf("请输入随机数范围：\n");
			scanf_s("%d", &b);
			if (b == 0) {
				printf("输入错误");
			}
		} while (b == 0);
		if (b == 0) {
			printf("请不要乱输入随机范围。\n");
			return L;
		}
		for (int i = 0; i < n; i++) {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = rand() % b;
			s->next = L->next;
			L->next = s;
		}
	}
	else if (choice == 2) {
		for (int i = 0; i < n; i++) {
			printf("请输入第%d个元素：", n - i);
			int x;
			s = (LNode*)malloc(sizeof(LNode));
			scanf_s("%d", &x);
			s->data = x;
			s->next = L->next;
			L->next = s;
		}
	}
	else {
		printf("输入错误\n");
	}
	return L;
}
Linklist List_TailInsert(Linklist &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = NULL;
	Linklist s,r=L;
	int n = 0,choice;
	printf("请输入链表长度：\n");
	scanf_s("%d", &n);
	printf("输入1生成随机链表,输入2生成指定链表\n");
	scanf_s("%d", &choice);
	if (choice == 1) {
		time_t t;
		srand(time(&t));
		int b;
		do {
			printf("请输入随机数范围：\n");
			scanf_s("%d", &b);
			if (b == 0) {
				printf("输入错误");
			}
		} while (b == 0);
		for (int i = 0; i < n; i++) {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = rand() % b;
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
	else if (choice == 2) {
		for (int i = 0; i < n; i++) {
			printf("请输入第%d个元素：", i+1);
			int x;
			s = (LNode*)malloc(sizeof(LNode));
			scanf_s("%d", &x);
			s->data = x;
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
	else {
		printf("输入错误\n");
	}
	return L;
}
Status ListTravel_LL(Linklist L) {
	LNode *p;
	if (L->data != NULL) {
		 p = L;
	}
	else {
		p=L->next;
	}
	int i = 0;
	printf("链表为：\n");
	while (p != NULL) {
		if (i % 10 == 0) {
			printf("\n");
		}
		i++;
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status ListEmpty_LL(Linklist L) {
	if (L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status DestoryList_LL(Linklist &L) {
	LNode* p;
	while (L != NULL) {
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}
Status GetElem_LL(Linklist L, int i,Elemtype &e,Linklist &p) {
	Linklist q;
	q = L;
	if (i < 0) {
		p = q;
		return ERROR;

	}
	while (i >= 0 && q!= NULL){
		if (i == 0) {
			e = q->data;
			break;
		}
		q = q->next;
		i--;
	} 
	if (i >= 0&&q == NULL) {
		return ERROR;
	}
	p = q;
	
	return OK;
}
Linklist LocateElem_LL(Linklist L, Elemtype e,int &i) {
	Linklist q = L->next;
	i = 1;
	while (q != NULL) {
		if (q->data == e) {
			return q;
		}
		q = q->next;
		i++;
	}
	return q;
}
Status InsertElem1(Linklist L, int i,Elemtype e) {
	Linklist s = (Linklist)malloc(sizeof(Linklist));
	Linklist p = L;
	Elemtype t;
	if (GetElem_LL(L, i - 1, t, p) == ERROR) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status InsertElem2(Linklist L, int i, Elemtype e) {
	Linklist s = (Linklist)malloc(sizeof(Linklist));
	Linklist p;
	Elemtype t;
	if (GetElem_LL(L, i , t, p) == ERROR) {
		return ERROR;
	}
	s->next = p->next;
	p->next = s;
	Elemtype temp = p->data;
	p->data = e;
	s->data = temp;
	return OK;
}
Status DeleteElem1(Linklist L, int i) {
	Linklist p;
	Elemtype t;
	if (GetElem_LL(L, i - 1, t, p) == ERROR) {
		return ERROR;
	}
	Linklist q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}
Status DeleteElem2(Linklist L, int i) {
	Linklist p;
	Elemtype t;
	if (GetElem_LL(L, i , t, p) == ERROR) {
		return ERROR;
	}
	Linklist q = p->next;
	p->data = p->next->data;
	p->next = p->next->next;
	free(q);
	return OK;
}
Status DeleteLNodeX1(Linklist L,int x) {
	Linklist q = L->next;
	Linklist p = L;
	if (q!=NULL) {
		if (q->data==x) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		return DeleteLNodeX1(q, x);
	}
	return OK;
}
Status CreateListWithoutHead(Linklist &L) {
	Linklist s;
	int n = 0;
	int choice;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = NULL;
	printf("请输入链表长度：\n");
	scanf_s("%d", &n);
	printf("输入1生成随机链，表输入2生成指定链表：\n");
	scanf_s("%d", &choice);

	if (choice == 1) {
		time_t t;
		srand(time(&t));
		L->data= rand() % 50;
		for (int i = 1; i < n; i++) {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = rand() % 50;
			s->next = L->next;
			L->next = s;
		}
	}
	else if (choice == 2) {
		int x;
		scanf_s("%d", &x);
		L->data = x;
		for (int i = 1; i < n; i++) {
			printf("请输入第%d个元素：", n - i + 1);
			s = (LNode*)malloc(sizeof(LNode));
			scanf_s("%d", &x);
			s->data = x;
			s->next = L->next;
			L->next = s;
		}
	}
	else {
		printf("输入错误\n");
	}
	return OK;
}
void DeleteLNodeX2(Linklist &L, int x) {
	Linklist q;
	if (L == NULL) {
		return;
	}
	if(L->data==x){
		q = L;
		L = L->next;
		free(q);
		DeleteLNodeX2(L, x);
	}
	else {
		DeleteLNodeX2(L->next, x);
	}
}
Status DeleteLNodeX3(Linklist& L, int x) {
	Linklist p,q;
	p = L;
	q = L->next;
	while (q != NULL) {
		if (q->data == x) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
		p = p->next;
		q = q->next;
		}
	}
	return OK;
}
Status Reverse_LL(Linklist &L) {
	Linklist q, p, k;
	p = NULL;
	q = L->next;
	while (q != NULL) {
		k = q->next;
		q->next = p;
		p = q;
		q = k;
	}
	L->next = p;
	return OK;
}
Status R_Print(Linklist L,int &i) {
	if (L->next != NULL) {
		R_Print(L->next,i);
	}
	if (i % 10 == 0) {
		printf("\n");
	}
	if (L!=NULL) {
		printf(" %d ", L->data);
	}
	i++;
	return OK;
}
Status DeleteMinumLNode(Linklist L) {
	Linklist pre = L->next;
	Linklist p = pre->next;
	Elemtype x;
	if (L->next == NULL) {
		return ERROR;
	}
	x = pre->data;
	while (p != NULL) {
		if (pre->data > p->data) {
			x = p->data;
		}
		p = p->next;
		pre = p;
	}
	DeleteLNodeX3(L, x);
	return OK;
}
Status LinkSplit(Linklist head, Linklist* head1, Linklist* head2) {
	Linklist slow, fast;
	if (head == NULL || head->next == NULL) {
		*head1 = head;
		*head2 = NULL;
		return OK;
	}
	slow = head;
	fast = head->next;
	while (fast) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	*head1 = head;
	*head2 = slow->next;

	slow->next = NULL;
	return OK;
}
Linklist LinkMerge(Linklist head1, Linklist head2) {
	Linklist p, q, t;
	if (!head1) {
		return head2;
	}
	if (!head2) {
		return head1;
	}
	p = NULL;
	q = head1;
	while (head2) {
		t = head2;
		head2 = head2->next;
		while (q != NULL&& q->data <= t->data) {
			p = q;
			q = q->next;
		}
		if (p == NULL) {
			head1 = t;
		}
		else {
			p->next = t;
		}
		t->next = q;
		p = t;
	}
	return head1;
}
Linklist MergeSort_LL(Linklist head) {
	Linklist head1,head2;
	if (head==NULL ||head->next==NULL) {
		return head;
	}
	LinkSplit(head, &head1, &head2);
	head1 = MergeSort_LL(head1);
	head2 = MergeSort_LL(head2);
	head = LinkMerge(head1, head2);
	return head;
}
Status DeleteElem_x1_x2(Linklist L, int x1, int x2) {
	Linklist p,q;
	if (x1 > x2) {
		return DeleteElem_x1_x2(L, x2, x1);
	}
	p = L;
	q = p->next;
	while (q != NULL) {
		if (q->data > x1 && q->data < x2) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	return OK;
}
Status PrintAndDelete_Min(Linklist L) {
	if (L->next == NULL) {
		return OK;
	}
	Linklist q = L->next;
	Elemtype x = q->data;
	while (q != NULL) {
		if (x > q->data) {
			x = q->data;
		}
		q = q->next;
	}
	Linklist p = L;
	q = L->next;
	while (q != NULL) {
		if (x == q->data) {
			printf(" %d ",q->data);
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			q = q->next;
			p = p->next;
		}
	}
	PrintAndDelete_Min(L);
	return OK;
}
Status SeparateOddEven(Linklist L, Linklist OddL, Linklist EvenL) {
	Linklist p = L->next;
	while (p != NULL) {
		if (p->data % 2 == 1) {
			OddL->next = p;
			OddL = OddL->next;
		}
		else if (p->data % 2 == 0) {
			EvenL->next = p;
			EvenL = EvenL->next;
		}
		p = p->next;
	}
	OddL->next = NULL;
	EvenL->next = NULL;
	return OK;
}
Status SeparateList_LL(Linklist L, Linklist L1, Linklist L2) {
	Linklist p = L->next;
	int i = 1;
	while (p != NULL) {
		if (i % 2 == 1) {
			L1->next = p;
			L1 = L1->next;
			p = p->next;
		}
		else if(i % 2 == 0) {
			L2->next = p;
			L2 = L2->next;
			p = p->next;
		}
		else
		{
			p = p->next;
		}
		i++;
	}
	L1->next = NULL;
	L2->next = NULL;
	return OK;
}
Status DelDuplicateElem(Linklist L) {
	Linklist p = L->next;
	Linklist q = p->next;
	while (q != NULL) {
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	return OK;
}
Status MergeAndSortList(Linklist L1,Linklist L2) {
	Linklist r, p1 = L1->next, p2 = L2->next;
	L1->next = NULL;
	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) {
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}
		else {
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}
	if (p1 != NULL) {
		p2 = p1;
	}
	while (p2!=NULL) {
		r = p2->next;
		p2->next = L1->next;
		L1->next = p2;
		p2 = r;
	}
	free(L2);
	return OK;
}

//Status mergelist(Linklist L1, Linklist L2) {
//	Linklist r, p1 = L1->next, p2 = L2->next;
//	L1->next = NULL;
//	while (p1 != NULL && p2 != NULL) {
//		if (p1->data <= p2->data) {
//			r = p1->next;
//			p1->next = L1->next;
//			L1->next = p1;
//			p1 = r;
//		}
//		else {
//			r = p2->next;
//			p2->next = L1->next;
//			L1->next = p2;
//			p2 = r;
//		}
//	}
//	if (p1 != NULL) {
//		p2 = p1;
//	}
//	while (p2 != NULL) {
//		r = p2->next;
//		p2->next = L1->next;
//		L1->next = p2;
//		p2 = r;
//	}
//	free(L2);
//	return OK;
//}

Linklist FindDuplicateElem(Linklist A, Linklist B) {
	Linklist Aa = A->next, Bb = B->next, C, s,r;
	InitLinkList(C);
	r = C;
	while (Aa != NULL&&Bb!=NULL) {
		if (Aa->data > Bb->data) {
			Bb = Bb->next;
		}
		else if (Aa->data < Bb->data) {
			Aa = Aa->next;
		}
		else {
			InitLinkList(s);
			s->data = Aa->data;
			s->next = r->next;
			r->next = s;
			r = s;
			Bb = Bb->next;
			Aa = Aa->next;
		}
	}
	r->next = NULL;
	return C;
}
Linklist Intersection(Linklist &A, Linklist &B) {
	Linklist p = A->next, q = B->next, pq = A,u;
	while (p != NULL && q != NULL) {
		if(p->data==q->data) {
			pq->next = p;
			pq = p;
			p = p->next;
			u = q;
			q = q->next;
			free(u);
		}
		else if (p->data > q->data) {
			u = q;
			q = q->next;
			free(u);
		}
		else if(p->data < q->data) {
			u = p;
			p = p->next;
			free(u);
		}
	}
	DestoryList_LL(q);
	DestoryList_LL(p);
	return A;
}