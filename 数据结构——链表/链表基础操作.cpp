#include<stdio.h>
#include<stdlib.h>
#include"����ͷ�ļ�.h"
#include "windows.h"

int main(){
	Linklist L, q, withoutheadL,A,B;
	Elemtype e,x;
	int status, i, select=0,WCL=NULL;
	InitLinkList(L);
	while ((WCL != 1 && WCL != 2) || WCL == NULL) {
		printf("ѡ��ͷ�巨��β�巨��������\n1��ͷ�巨\n2��β�巨\n0���˳�\n");
		scanf_s("%d", &WCL);
		if (WCL == 1) {
			L = List_HeadInsert(L);
			ListTravel_LL(L);
		}
		else if (WCL == 2) {
			L = List_TailInsert(L);
			ListTravel_LL(L);
		}
		else if (WCL == 0) {
			return 0;
		}
		else {
			printf("�������\n");
		}
	}
	do {
		e = NULL;
		status = NULL;
		i = NULL;
		q = NULL;
		if (!L) {
			InitLinkList(L);
		}
		printf("\n**************************************************************\n");
		printf("1:�ж������Ƿ�Ϊ��\n");
		printf("2:��������\n");
		printf("3:���������ĵ�i��Ԫ��\n");
		printf("4:��ֵ��λԪ��λ��\n");
		printf("5:��i������ڵ����1\n");
		printf("6:��i������ڵ����2(��λ��)\n");
		printf("7:ɾ��i�ڵ�1\n");
		printf("8:ɾ��i�ڵ�2(��λ��)\n");
		printf("9:�ݹ�ɾ��ֵΪx�Ľڵ�\n");
		printf("10:�ݹ�ɾ��ֵΪx�Ľڵ�(����ͷ���)\n");
		printf("11:ɾ������ֵΪx�Ľڵ㣨p40 2��\n");
		printf("12:��ת����(p40 5\n");
		printf("13:�����������\n");
		printf("14:ɾ����������Сֵ��p40 4��\n");
		printf("15:�������򣨹鲢 p40 6��\n");
		printf("16:ɾ������ֵ֮���Ԫ�أ�p40 7��\n");
		printf("17:˳�������ɾ���ڵ�(p40 9��\n");
		printf("18:��ż���루p40 10��\n");
		printf("19:�������ֳ���������p40 11)\n");
		printf("20:ɾ�����������ظ�Ԫ�أ�p40 12��\n");
		printf("21:�ϲ������������С�������У�p40 13��\n");
		printf("22:����������������ȡ������Ԫ�أ�p40 14��\n");
		printf("23:ȡ���������Ľ�����P40 15��\n");
		printf("45:�����������\n");
		printf("50:������������\n");
		printf("**************************************************************\n");
		printf("������ѡ��");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			if (ListEmpty_LL(L) == TRUE) {
				printf("����Ϊ��\n");
			}
			else {
				printf("����ǿ�\n");
			}
			break;

		case 2:printf("��������\n");
			DestoryList_LL(L);
			break;

		case 3:printf("���������ĵ�i��Ԫ��\n������iֵ��");
			scanf_s("%d", &i);
			status = GetElem_LL(L, i, e,q);
			if (status == ERROR){
				printf("iֵ���Ϸ�\n");
			}
			else {
				printf("��%dλԪ��Ϊ��%d\n", i, e);
			}
			break;

		case 4:printf("��ֵ��λԪ��λ��\n�������ѯֵ��");
			scanf_s("%d", &e);
			q = LocateElem_LL(L, e, i);
			if (q == NULL) {
				printf("������û��%d����", e);
			}
			else {
				printf("%d�������%dλ\n", q->data, i);
			}
			break;

		case 5:printf("��i������ڵ����1\n");
			printf("������iֵ��");
			scanf_s("%d", &i);
			printf("������ڵ�ֵ��");
			scanf_s("%d", &e);
			if (InsertElem1(L, i, e) == ERROR) {
				printf("iֵԽ��\n");
				break;
			};
			ListTravel_LL(L);
			break;

		case 6:printf("��i������ڵ����2\n");
			printf("������iֵ��");
			scanf_s("%d", &i);
			printf("������ڵ�ֵ��");
			scanf_s("%d", &e);
			if (InsertElem2(L, i, e) == ERROR) {
				printf("iֵԽ��\n");
				break;
			};
			ListTravel_LL(L);
			break;

		case 7:printf("ɾ��i�ڵ�1\n");
			printf("������iֵ��");
			scanf_s("%d", &i);
			if (DeleteElem1(L, i) == ERROR) {
				printf("iֵԽ��\n");
				break;
			}
			ListTravel_LL(L);
			break;

		case 8:printf("ɾ��i�ڵ�2\n");
			printf("������iֵ��");
			scanf_s("%d", &i);
			if (DeleteElem2(L, i) == ERROR) {
				printf("iֵԽ��\n");
				break;
			}
			ListTravel_LL(L);
			break;
		
		case 9:printf("�ݹ�ɾ��ֵΪx�Ľڵ�\n");
			printf("������xֵ��");
			scanf_s("%d", &x);
			DeleteLNodeX1(L,x);
			ListTravel_LL(L);
			break;

		case 10:printf("�ݹ�ɾ��ֵΪx�Ľڵ�(����ͷ���)\n");
			CreateListWithoutHead(withoutheadL);
			ListTravel_LL(withoutheadL);
			printf("������xֵ��");
			scanf_s("%d", &x);
			DeleteLNodeX2(withoutheadL, x);
			ListTravel_LL(withoutheadL);
			break;

		case 11:printf("ɾ������ֵΪx�Ľڵ㣨p40 2��\n");
			printf("������xֵ��");
			scanf_s("%d", &x);
			DeleteLNodeX3(L, x);
			ListTravel_LL(L);
			break;

		case 12:printf("��ת����\n");
			Reverse_LL(L);
			ListTravel_LL(L);
			break;

		case 13:printf("�����������(p40 3)\n");
			i = 0;
			R_Print(L->next,i);
			printf("\n");
			break;

		case 14:printf("ɾ����������Сֵ��p40 4��\n");
			DeleteMinumLNode(L);
			ListTravel_LL(L);
			break;
		
		case 15:printf("15:�������򣨹鲢 p40 6��\n");
			MergeSort_LL(L);
			ListTravel_LL(L);
			break;

		case 16:printf("16:ɾ������ֵ֮���Ԫ�أ�p40 7��\n");
			printf("������x1��");
			int x1, x2;
			scanf_s("%d", &x1);
			printf("������x2��");
			scanf_s("%d", &x2);
			DeleteElem_x1_x2(L, x1, x2);
			ListTravel_LL(L);
			break;

		case 17:printf("17:˳�������ɾ���ڵ�(p40 9��\n");
			PrintAndDelete_Min(L);
			DestoryList_LL(L);
			break;

		case 18:printf("18:��ż���루p40 10��\n");
			Linklist OddL, EvenL;
			InitLinkList(OddL);
			InitLinkList(EvenL);
			SeparateOddEven(L, OddL, EvenL);
			printf("����");
			ListTravel_LL(OddL);
			printf("ż��");
			ListTravel_LL(EvenL);
			break;

		case 19:printf("19:�������ֳ���������p40 11)\n");
			Linklist L1, L2;
			InitLinkList(L1);
			InitLinkList(L2);
			SeparateList_LL(L, L1, L2);
			printf("һ��");
			ListTravel_LL(L1);
			printf("����");
			ListTravel_LL(L2);
			break;

		case 20:printf("20:ɾ�����������ظ�Ԫ�أ�p40 12��\n");
			MergeSort_LL(L);
			DelDuplicateElem(L);
			ListTravel_LL(L);
			break;

		case 21:printf("21:�ϲ������������С�������У�p40 13��\n");
			Linklist La, Lb;
			List_HeadInsert(La);
			List_HeadInsert(Lb);
			MergeSort_LL(La);
			MergeSort_LL(Lb);
			printf("һ��");
			ListTravel_LL(La);
			printf("����");
			ListTravel_LL(Lb);
			MergeAndSortList(La, Lb);
			ListTravel_LL(La);
			break;

		case 22:printf("22:����������������ȡ������Ԫ�أ�p40 14��\n");
			List_HeadInsert(A);
			List_HeadInsert(B);
			MergeSort_LL(A);
			MergeSort_LL(B);
			printf("A");
			ListTravel_LL(A);
			printf("B");
			ListTravel_LL(B);
			ListTravel_LL(FindDuplicateElem(A, B));
			break;

		case 23:printf("23:ȡ���������Ľ�����P40 15��bug��\n");
			List_HeadInsert(A);
			List_HeadInsert(B);
			MergeSort_LL(A);
			MergeSort_LL(B);
			printf("A");
			ListTravel_LL(A);
			printf("B");
			ListTravel_LL(B);
			ListTravel_LL(Intersection(A, B));
			break;

		case 24:

		case 45:printf("�����������\n");
			ListTravel_LL(L);
			break;

		case 50:printf("50:������������\n");
			WCL = NULL;
			while ((WCL != 1 && WCL != 2) || WCL == NULL) {
				printf("ѡ��ͷ�巨��β�巨��������\n1��ͷ�巨\n2��β�巨\n0���˳�\n");
				scanf_s("%d", &WCL);
				if (WCL == 1) {
					L = List_HeadInsert(L);
					ListTravel_LL(L);
				}
				else if (WCL == 2) {
					L = List_TailInsert(L);
					ListTravel_LL(L);
				}
				else if (WCL == 0) {
					return 0;
				}
				else {
					printf("�������\n");
				}
			}
			break;

		case 0: printf("��������\n"); break;

		default:printf("����ѡ�����! \n");
		}
	} while (select != 0);
}
