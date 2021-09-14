#include "SqList.h"

SQLIST_TYPE_SET(int);

int main(){
    SqList(int) a = InitList(int);
    SqList(int) b = InitList(int);
    /*
    printf("%d\n", a.ListLength());
    a.ListInsert(1, 2);
    printf("%d\n", a.GetElem(1));
    a.ListInsert(2, 5);
    printf("%d\n", a.GetElem(2));
    */
    printf("is empty? %s\n", (a.ListEmpty())?"true":"false");
    printf("capacity = %d\n", a.ListCapacity());
    a.ListInsert(1,3);
    printf("is empty? %s\n", (a.ListEmpty())?"true":"false");
    printf("capacity = %d\n", a.ListCapacity());
    a.ListInsert(2,4);
    printf("capacity = %d\n", a.ListCapacity());
    a.ListInsert(3,2);

    for(int i = 0; i < a.ListLength(); ++i){
        printf("%d%c", a.GetElem(i + 1), (i != a.ListLength()-1)?' ':'\n');
    }

    for(int *it = a.begin(); it != a.end(); ++it){
        printf("%d%c", *it, (it!= a.end()-1)?' ':'\n');
    }
    a.ListDelet(2);
    printf("capacity = %d\n", a.ListCapacity());
    for(int *it = a.begin(); it != a.end(); ++it){
        printf("%d%c", *it, (it!= a.end()-1)?' ':'\n');
    }

    a.ListDelet(1);
    printf("capacity = %d\n", a.ListCapacity());

    for(int *it = a.begin(); it != a.end(); ++it){
        printf("%d%c", *it, (it!= a.end()-1)?' ':'\n');
    }

    a.DestoryList();
    b.DestoryList();
    return 0;
}
