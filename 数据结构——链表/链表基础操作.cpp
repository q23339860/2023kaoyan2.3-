#include<stdio.h>
#include<stdlib.h>
#include"链表头文件.h"
#include "windows.h"

int main(){
	Linklist L, q, withoutheadL,A,B;
	Elemtype e,x;
	int status, i, select=0,WCL=NULL;
	InitLinkList(L);
	while ((WCL != 1 && WCL != 2) || WCL == NULL) {
		printf("选择头插法或尾插法创建链表\n1：头插法\n2：尾插法\n0：退出\n");
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
			printf("输入错误\n");
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
		printf("1:判断链表是否为空\n");
		printf("2:销毁链表\n");
		printf("3:查找链表表的第i个元素\n");
		printf("4:按值定位元素位置\n");
		printf("5:在i处插入节点操作1\n");
		printf("6:在i处插入节点操作2(换位法)\n");
		printf("7:删除i节点1\n");
		printf("8:删除i节点2(换位法)\n");
		printf("9:递归删除值为x的节点\n");
		printf("10:递归删除值为x的节点(不带头结点)\n");
		printf("11:删除所有值为x的节点（p40 2）\n");
		printf("12:翻转链表(p40 5\n");
		printf("13:反向输出链表\n");
		printf("14:删除链表中最小值（p40 4）\n");
		printf("15:链表排序（归并 p40 6）\n");
		printf("16:删除给定值之间的元素（p40 7）\n");
		printf("17:顺序输出并删除节点(p40 9）\n");
		printf("18:奇偶分离（p40 10）\n");
		printf("19:将链表拆分成两个链表（p40 11)\n");
		printf("20:删除有序链表重复元素（p40 12）\n");
		printf("21:合并两个有序表并由小到大排列（p40 13）\n");
		printf("22:从两个有序链表中取出公共元素（p40 14）\n");
		printf("23:取两个有序表的交集（P40 15）\n");
		printf("45:遍历输出链表\n");
		printf("50:填入链表数据\n");
		printf("**************************************************************\n");
		printf("请输入选择：");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			if (ListEmpty_LL(L) == TRUE) {
				printf("链表为空\n");
			}
			else {
				printf("链表非空\n");
			}
			break;

		case 2:printf("销毁链表\n");
			DestoryList_LL(L);
			break;

		case 3:printf("查找链表表的第i个元素\n请输入i值：");
			scanf_s("%d", &i);
			status = GetElem_LL(L, i, e,q);
			if (status == ERROR){
				printf("i值不合法\n");
			}
			else {
				printf("第%d位元素为：%d\n", i, e);
			}
			break;

		case 4:printf("按值定位元素位置\n请输入查询值：");
			scanf_s("%d", &e);
			q = LocateElem_LL(L, e, i);
			if (q == NULL) {
				printf("链表中没有%d存在", e);
			}
			else {
				printf("%d在链表第%d位\n", q->data, i);
			}
			break;

		case 5:printf("在i处插入节点操作1\n");
			printf("请输入i值：");
			scanf_s("%d", &i);
			printf("请输入节点值：");
			scanf_s("%d", &e);
			if (InsertElem1(L, i, e) == ERROR) {
				printf("i值越界\n");
				break;
			};
			ListTravel_LL(L);
			break;

		case 6:printf("在i处插入节点操作2\n");
			printf("请输入i值：");
			scanf_s("%d", &i);
			printf("请输入节点值：");
			scanf_s("%d", &e);
			if (InsertElem2(L, i, e) == ERROR) {
				printf("i值越界\n");
				break;
			};
			ListTravel_LL(L);
			break;

		case 7:printf("删除i节点1\n");
			printf("请输入i值：");
			scanf_s("%d", &i);
			if (DeleteElem1(L, i) == ERROR) {
				printf("i值越界\n");
				break;
			}
			ListTravel_LL(L);
			break;

		case 8:printf("删除i节点2\n");
			printf("请输入i值：");
			scanf_s("%d", &i);
			if (DeleteElem2(L, i) == ERROR) {
				printf("i值越界\n");
				break;
			}
			ListTravel_LL(L);
			break;
		
		case 9:printf("递归删除值为x的节点\n");
			printf("请输入x值：");
			scanf_s("%d", &x);
			DeleteLNodeX1(L,x);
			ListTravel_LL(L);
			break;

		case 10:printf("递归删除值为x的节点(不带头结点)\n");
			CreateListWithoutHead(withoutheadL);
			ListTravel_LL(withoutheadL);
			printf("请输入x值：");
			scanf_s("%d", &x);
			DeleteLNodeX2(withoutheadL, x);
			ListTravel_LL(withoutheadL);
			break;

		case 11:printf("删除所有值为x的节点（p40 2）\n");
			printf("请输入x值：");
			scanf_s("%d", &x);
			DeleteLNodeX3(L, x);
			ListTravel_LL(L);
			break;

		case 12:printf("翻转链表\n");
			Reverse_LL(L);
			ListTravel_LL(L);
			break;

		case 13:printf("反向输出链表(p40 3)\n");
			i = 0;
			R_Print(L->next,i);
			printf("\n");
			break;

		case 14:printf("删除链表中最小值（p40 4）\n");
			DeleteMinumLNode(L);
			ListTravel_LL(L);
			break;
		
		case 15:printf("15:链表排序（归并 p40 6）\n");
			MergeSort_LL(L);
			ListTravel_LL(L);
			break;

		case 16:printf("16:删除给定值之间的元素（p40 7）\n");
			printf("请输入x1：");
			int x1, x2;
			scanf_s("%d", &x1);
			printf("请输入x2：");
			scanf_s("%d", &x2);
			DeleteElem_x1_x2(L, x1, x2);
			ListTravel_LL(L);
			break;

		case 17:printf("17:顺序输出并删除节点(p40 9）\n");
			PrintAndDelete_Min(L);
			DestoryList_LL(L);
			break;

		case 18:printf("18:奇偶分离（p40 10）\n");
			Linklist OddL, EvenL;
			InitLinkList(OddL);
			InitLinkList(EvenL);
			SeparateOddEven(L, OddL, EvenL);
			printf("奇数");
			ListTravel_LL(OddL);
			printf("偶数");
			ListTravel_LL(EvenL);
			break;

		case 19:printf("19:将链表拆分成两个链表（p40 11)\n");
			Linklist L1, L2;
			InitLinkList(L1);
			InitLinkList(L2);
			SeparateList_LL(L, L1, L2);
			printf("一号");
			ListTravel_LL(L1);
			printf("二号");
			ListTravel_LL(L2);
			break;

		case 20:printf("20:删除有序链表重复元素（p40 12）\n");
			MergeSort_LL(L);
			DelDuplicateElem(L);
			ListTravel_LL(L);
			break;

		case 21:printf("21:合并两个有序表并由小到大排列（p40 13）\n");
			Linklist La, Lb;
			List_HeadInsert(La);
			List_HeadInsert(Lb);
			MergeSort_LL(La);
			MergeSort_LL(Lb);
			printf("一号");
			ListTravel_LL(La);
			printf("二号");
			ListTravel_LL(Lb);
			MergeAndSortList(La, Lb);
			ListTravel_LL(La);
			break;

		case 22:printf("22:从两个有序链表中取出公共元素（p40 14）\n");
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

		case 23:printf("23:取两个有序表的交集（P40 15有bug）\n");
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

		case 45:printf("遍历输出链表\n");
			ListTravel_LL(L);
			break;

		case 50:printf("50:填入链表数据\n");
			WCL = NULL;
			while ((WCL != 1 && WCL != 2) || WCL == NULL) {
				printf("选择头插法或尾插法创建链表\n1：头插法\n2：尾插法\n0：退出\n");
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
					printf("输入错误\n");
				}
			}
			break;

		case 0: printf("操作结束\n"); break;

		default:printf("输入选择出错! \n");
		}
	} while (select != 0);
}
