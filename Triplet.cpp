#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//定义OK和OVERFLOW常量
#define OK 1
#define OVERFLOW -2
#define ERROR -1 // 定义ERROR常量

//三元组结构体
typedef struct{
    ElemType *elements; //动态分配的数组 
} Triplet;

//初始化三元组
int InitTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3){
    T->elements = (ElemType *)malloc(3 * sizeof(ElemType)); // 应该为T->elements分配内存
    if(!T->elements) // 检查内存分配是否成功
        exit(OVERFLOW);
        
    T->elements[0] = v1;
    T->elements[1] = v2;
    T->elements[2] = v3;
    return OK;
} 

//销毁三元组
int DestroyTriplet(Triplet *T){
    free(T->elements); // 应该释放T->elements指向的内存
    T->elements = NULL; // 将指针设置为NULL
    return OK;
} 

//返回T的第i元的值
int Get(Triplet T, int i, ElemType *e){ // e应该是指针类型，以便修改外部变量的值
    if(i < 1 || i > 3)
        return ERROR;
    *e = T.elements[i - 1]; // 通过指针修改外部变量的值
    return OK;
}

//置T的第i元的值
int Put(Triplet *T, int i, ElemType e){
    if(i < 1 || i > 3)
        return ERROR;
    T->elements[i - 1] = e; // 应该通过T->elements访问元素
    return OK;
} 

//判断是否是升序
int IsAscending(Triplet T){
    return (T.elements[0] <= T.elements[1]) && (T.elements[1] <= T.elements[2]); // 应该通过T.elements访问元素
} 

//判断是否是降序
int IsDescending(Triplet T){
    return (T.elements[0] >= T.elements[1]) && (T.elements[1] >= T.elements[2]); // 应该通过T.elements访问元素
} 

//返回最大元素的值
int Max(Triplet T, ElemType *e){ // e应该是指针类型
    *e = (T.elements[0] >= T.elements[1]) ? ((T.elements[0] >= T.elements[2]) ? T.elements[0] : T.elements[2])
                       : ((T.elements[1] >= T.elements[2]) ? T.elements[1] : T.elements[2]);
    return OK;
} 

//返回最小元素
int Min(Triplet T, ElemType *e){ // e应该是指针类型
    *e = (T.elements[0] <= T.elements[1]) ? ((T.elements[0] <= T.elements[2]) ? T.elements[0] : T.elements[2])
                       : ((T.elements[1] <= T.elements[2]) ? T.elements[1] : T.elements[2]);
    return OK;
}

int main() {
    Triplet T;
    ElemType value;
    
    // 初始化三元组
    if (InitTriplet(&T, 3, 2, 1) == OK) {
        // 判断是否是升序
        printf("IsAscending: %d\n", IsAscending(T));
        
        // 判断是否是降序
        printf("IsDescending: %d\n", IsDescending(T));
        
        // 获取最大值
        if (Max(T, &value) == OK) {
            printf("Max element: %d\n", value);
        }
        
        // 获取最小值
        if (Min(T, &value) == OK) {
            printf("Min element: %d\n", value);
        }
        
        // 销毁三元组
        DestroyTriplet(&T);
    }
    
    return 0;
}
