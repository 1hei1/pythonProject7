#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
ElemType data[MaxSize];//存放顺序表元素
int length;//存放顺序表的长度
} SqList;//声明顺序表的类型
void CreateList(SqList*& L, ElemType a[], int n); //整体建立顺序表

void InitList(SqList*& L);//初始化线性表

void DestroyList(SqList*& L);  //销毁线性表

bool ListEmpty(SqList* L);//判线性表是否为空表

int ListLength(SqList* L);//求线性表的长度

void DispList(SqList* L);//输出线性表

bool GetElem(SqList* L, int i, ElemType& e);//求线性表中第i个元素值

int LocateElem(SqList* L, ElemType e);//查找第一个值域为e的元素序号

bool ListInsert(SqList*& L, int i, ElemType e);//插入第i个元素

bool ListDelete(SqList*& L, int i, ElemType& e);//删除第i个元素
