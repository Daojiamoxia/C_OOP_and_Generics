#include<stdio.h>
#include<stdlib.h>
#include "SqList.h"
/**
* SqList.h
* 作者：althumi
* 顺序表的库函数，支持泛型编程
* 使用说明：
* 如果要使用以int为类型的SqList，须提前使用
* SQLIST_TYPE_SET(int);设置。同理，如果要使
* 用double类型的SqList，也须提前设置SQLIST_TYPE_SET(double);
* 设置完成使用InitList(type)构造对象SqList(type)，
* 例如：
* SqList(int) a = InitList(int);
*
* 生成完成了a这个顺序表后，可以通过a来调用它的成员函数对他的成员变量操作
* 成员函数如下：
* a.begin()        -----   返回顺序表a的头指针
* a.end()          -----   返回顺序表a的结束指针
* 通过a.begin()和a.end()可以做到使用指针循环直接操作内容
*
* a.ClearList()    -----   清楚顺序表a的所有元素
* a.DestoryList()  -----   释放顺序表a的内存空间
* a.ListEmpty()    -----   返回顺序表a是否为空
* a.ListLength()   -----   返回顺序表a的元素个数
* a.ListCapacity() -----   返回顺序表a的当前容量
* a.GetElem(int i) -----   返回顺序表a的第i个元素
* a.LocateElem(type e)     --- 返回数据e在顺序表a中的第几个元素，不存在返回0
* a.ListInsert(int i, T e) --- 插入元素e到顺序表中的第i个位置
* a.ListDelet(int i)       --- 删除顺序表a的第i个元素
*/


/**
*
* 将int类型添加到SqList泛型库中
* 如果还需要其他类型，请SQLIST_TYPE_SET(type)
*
*/
SQLIST_TYPE_SET(int);

//显示菜单
void show();

//输入函数
void input(SqList(int) *);

//输出函数
void output(SqList(int) *);

//求顺序表A与B的交集
void A_and_B(SqList(int) *, SqList(int) *);

//求顺序表A与B的并集
void A_or_B(SqList(int) *, SqList(int) *);

//求顺序表A与B的差集
void A_sub_B(SqList(int) *, SqList(int) *);

int main(){
    //定义顺序表A,B
	SqList(int) A = InitList(int);
	SqList(int) B = InitList(int);


    //操作字符
	char op[2];

	show();
	scanf("%s", op);

	while(strcmp(op, "0") != 0){
		switch(op[0]){
			case '1':
				system("cls");
				printf("功能1执行中...\n");
				input(&A);
				system("pause");
				break;
			case '2':
				system("cls");
				printf("功能2执行中...\n");
				input(&B);
				system("pause");
				break;
			case '3':
				system("cls");
				printf("功能3执行中...\n");
				puts("集合A数据：");
				output(&A);
				system("pause");
				break;
			case '4':
				system("cls");
				printf("功能4执行中...\n");
				puts("集合B数据：");
				output(&B);
				system("pause");
				break;
			case '5':
			    system("cls");
				printf("功能5执行中...\n");
				A_or_B(&A, &B);
				system("pause");
				break;
			case '6':
			    system("cls");
				printf("功能6执行中...\n");
				A_and_B(&A, &B);
				system("pause");
				break;
			case '7':
			    system("cls");
				printf("功能7执行中...\n");
				A_sub_B(&A, &B);
				system("pause");
				break;
			default:
				printf("请选择菜单上的选项！\n");
				system("pause");
				break;
		}
		show();
		fflush(stdin);
		scanf("%s", op);
	}

	//回收顺序表A与B的内存
	A.DestoryList();
	B.DestoryList();

	system("cls");
	puts("谢谢使用！再见~");
	system("pause");

	return 0;
}

void show(){
	system("cls");
	printf("\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\t\n");
	printf(" ||\t\t1  集合A数据输入              \t||\n");
	printf(" ||\t\t2  集合B数据输入              \t||\n");
	printf(" ||\t\t3  集合A数据显示              \t||\n");
	printf(" ||\t\t4  集合B数据显示              \t||\n");
	printf(" ||\t\t5  集合A和集合B的并集         \t||\n");
	printf(" ||\t\t6  集合A和集合B的交集         \t||\n");
	printf(" ||\t\t7  集合A和集合B的差集         \t||\n");
	printf(" ||\t\t0  退出系统                   \t||\n");
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\t\n");
	printf("\n");
	printf("\t请选择功能：");
}

void input(SqList(int) *temp){
	int x, i = temp -> ListLength() + 1;
	char op[2];


	printf("请输入第%d个数据：", i);
	scanf("%d", &x);

	if(!temp->LocateElem(x)){
		temp->ListInsert(i++, x);
	}

	printf("是否还要输入第%d个数据(y/n)? ", i);
	scanf("%s", op);

	while(strcmp(op, "Y") == 0 || strcmp(op, "y") == 0){

		printf("请输入第%d个数据：", i);
		scanf("%d", &x);

		if(!temp->LocateElem(x)){
			temp->ListInsert(i++, x);
		}

		printf("是否还要输入第%d个数据(y/n)? ", i);
		scanf("%s", op);
	}

	puts("已完成输入，请继续使用！");
}

void output(SqList(int) *temp){
	int i = 1;

	for(i = 1; i <= temp->ListLength(); ++i){
		printf("%d%c", temp->GetElem(i), (i % 10 != 0) ? ' ' : '\n');
	}

	putchar('\n');
}

void A_and_B(SqList(int) *_A, SqList(int) *_B){
	int i,j;
	SqList(int) res = InitList(int);

    for(i = 0, j = 1; i < _A->ListLength(); ++i){
        if(_B->LocateElem(_A->GetElem(i + 1))){
            res.ListInsert(j++, _A->GetElem(i + 1));
        }
    }

    puts("A和B的交集为：");

    output(&res);

    res.DestoryList();
}

void A_or_B(SqList(int) *_A, SqList(int) *_B){
    int i,j;
	SqList(int) res = InitList(int);

    for(i = 0, j = 1; i < _A->ListLength(); ++i){
        res.ListInsert(j++, _A->GetElem(i + 1));
    }

    for(i = 0; i < _B->ListLength(); ++i) if(!res.LocateElem(_B->GetElem(i + 1)))
        res.ListInsert(j++, _B->GetElem(i + 1));

    puts("A和B的并集为：");

    output(&res);

    res.DestoryList();
}

void A_sub_B(SqList(int) *_A, SqList(int) *_B){
    int i,j;
	SqList(int) res = InitList(int);

    for(i = 0, j = 1; i < _A->ListLength(); ++i){
        if(!_B->LocateElem(_A->GetElem(i + 1)))
            res.ListInsert(j++, _A->GetElem(i + 1));
    }

    for(i = 0; i < _B->ListLength(); ++i){
        if(!_A->LocateElem(_B->GetElem(i + 1)))
            res.ListInsert(j++, _B->GetElem(i + 1));
    }

    puts("A和B的差集集为：");

    output(&res);

    res.DestoryList();
}
