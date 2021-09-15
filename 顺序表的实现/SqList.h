#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//数组长度递增量
#define init_size 10

//顺序表泛型
#define SqList(T) T##_SqList

//添加新的类型到泛型库中，添加后才能使用
/*********************************************************/
#define SQLIST_TYPE_SET(T)                                      \
typedef struct SqList(T) SqList(T);                             \
struct SqList(T){                                               \
    T* (*begin)();                                              \
    T* (*end)();                                                \
    SqList(T) (*ClearList)();                                   \
    SqList(T) (*DestoryList)();                                 \
    int (*ListEmpty)();                                         \
    int (*ListLength)();                                        \
    int (*ListCapacity)();                                      \
    T (*GetElem)(int i);                                        \
    int (*LocateElem)(T e);                                     \
    int (*ListInsert)(int i, T e);                              \
    int (*ListDelet)(int i);                                    \
}


//顺序表方法体，定义函数的功能
/******************************************************************/
#define SQLIST_FUNCTION_BODY(T)                                           \
T* begin(){                                                               \
    return sqlist;                                                        \
}                                                                         \
T* end(){                                                                 \
    return sqlist + length;                                               \
}                                                                         \
SqList(T) ClearList(){                                                    \
    length = 0;                                                           \
    return this;                                                          \
}                                                                         \
SqList(T) DestoryList(){                                                  \
    free(sqlist);                                                         \
    capacity = length = 0;                                                \
    return this;                                                          \
}                                                                         \
int ListEmpty(){                                                          \
    return length == 0;                                                   \
}                                                                         \
int ListLength(){                                                         \
    return length;                                                        \
}                                                                         \
int ListCapacity(){                                                       \
    return capacity;                                                      \
}                                                                         \
T GetElem(int i){                                                         \
    if (i < 0 && i >= length) {                                           \
        exit(0);                                                          \
    }                                                                     \
    return sqlist[i - 1];                                                 \
}                                                                         \
int LocateElem(T e){                                                      \
    int i;                                                                \
    for(i = 0; i < length; ++i){                                          \
        if(sqlist[i] == e)                                                \
            return i + 1;                                                 \
    }                                                                     \
    return 0;                                                             \
}                                                                         \
int ListInsert(int i, T e){                                               \
    if(i <= 0 && i > length + 1) return 0;                                \
    if (capacity <= length) {                                             \
        void* _new_ptr_;                                                  \
		 _new_ptr_ = (T*)realloc(sqlist, sizeof(T)*(capacity+init_size)); \
        if(_new_ptr_ == NULL) {                                           \
            return 0;                                                     \
        }                                                                 \
        capacity += init_size;                                            \
    	sqlist = (T*)_new_ptr_;                                           \
	}                                                                     \
    memmove(sqlist + i, sqlist + i - 1, length - (i - 1));                \
    sqlist[i-1]=e;                                                        \
    ++length;                                                             \
    return 1;                                                             \
}                                                                         \
int ListDelet(int i){                                                     \
    memmove(sqlist + i - 1, sqlist + i, --length - (i-1));                \
    return 1;                                                             \
}


//生成类所含的成员方法
/*****************************************************************/
#define SQLIST_FUNCTION_assignmen                                         \
    this.begin = begin;                                                   \
    this.end = end;                                                       \
    this.ClearList = ClearList;                                           \
    this.DestoryList = DestoryList;                                       \
    this.ListEmpty = ListEmpty;                                           \
    this.ListLength = ListLength;                                         \
    this.ListCapacity = ListCapacity;                                     \
    this.GetElem = GetElem;                                               \
    this.LocateElem = LocateElem;                                         \
    this.ListInsert = ListInsert;                                         \
    this.ListDelet = ListDelet;                                           \

/******************************************************************/


//构造函数
#define InitList(T)                                                       \
({                                                                        \
    T *sqlist = NULL;                                                     \
    int length = 0;                                                       \
    int capacity = 0;                                                     \
    SqList(T) this;                                                       \
    SQLIST_FUNCTION_BODY(T)                                               \
    SQLIST_FUNCTION_assignmen                                             \
    this;                                                                 \
})

/******************************************************************/


#endif // _SQLIST_H_
