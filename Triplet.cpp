#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//����OK��OVERFLOW����
#define OK 1
#define OVERFLOW -2
#define ERROR -1 // ����ERROR����

//��Ԫ��ṹ��
typedef struct{
    ElemType *elements; //��̬��������� 
} Triplet;

//��ʼ����Ԫ��
int InitTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3){
    T->elements = (ElemType *)malloc(3 * sizeof(ElemType)); // Ӧ��ΪT->elements�����ڴ�
    if(!T->elements) // ����ڴ�����Ƿ�ɹ�
        exit(OVERFLOW);
        
    T->elements[0] = v1;
    T->elements[1] = v2;
    T->elements[2] = v3;
    return OK;
} 

//������Ԫ��
int DestroyTriplet(Triplet *T){
    free(T->elements); // Ӧ���ͷ�T->elementsָ����ڴ�
    T->elements = NULL; // ��ָ������ΪNULL
    return OK;
} 

//����T�ĵ�iԪ��ֵ
int Get(Triplet T, int i, ElemType *e){ // eӦ����ָ�����ͣ��Ա��޸��ⲿ������ֵ
    if(i < 1 || i > 3)
        return ERROR;
    *e = T.elements[i - 1]; // ͨ��ָ���޸��ⲿ������ֵ
    return OK;
}

//��T�ĵ�iԪ��ֵ
int Put(Triplet *T, int i, ElemType e){
    if(i < 1 || i > 3)
        return ERROR;
    T->elements[i - 1] = e; // Ӧ��ͨ��T->elements����Ԫ��
    return OK;
} 

//�ж��Ƿ�������
int IsAscending(Triplet T){
    return (T.elements[0] <= T.elements[1]) && (T.elements[1] <= T.elements[2]); // Ӧ��ͨ��T.elements����Ԫ��
} 

//�ж��Ƿ��ǽ���
int IsDescending(Triplet T){
    return (T.elements[0] >= T.elements[1]) && (T.elements[1] >= T.elements[2]); // Ӧ��ͨ��T.elements����Ԫ��
} 

//�������Ԫ�ص�ֵ
int Max(Triplet T, ElemType *e){ // eӦ����ָ������
    *e = (T.elements[0] >= T.elements[1]) ? ((T.elements[0] >= T.elements[2]) ? T.elements[0] : T.elements[2])
                       : ((T.elements[1] >= T.elements[2]) ? T.elements[1] : T.elements[2]);
    return OK;
} 

//������СԪ��
int Min(Triplet T, ElemType *e){ // eӦ����ָ������
    *e = (T.elements[0] <= T.elements[1]) ? ((T.elements[0] <= T.elements[2]) ? T.elements[0] : T.elements[2])
                       : ((T.elements[1] <= T.elements[2]) ? T.elements[1] : T.elements[2]);
    return OK;
}

int main() {
    Triplet T;
    ElemType value;
    
    // ��ʼ����Ԫ��
    if (InitTriplet(&T, 3, 2, 1) == OK) {
        // �ж��Ƿ�������
        printf("IsAscending: %d\n", IsAscending(T));
        
        // �ж��Ƿ��ǽ���
        printf("IsDescending: %d\n", IsDescending(T));
        
        // ��ȡ���ֵ
        if (Max(T, &value) == OK) {
            printf("Max element: %d\n", value);
        }
        
        // ��ȡ��Сֵ
        if (Min(T, &value) == OK) {
            printf("Min element: %d\n", value);
        }
        
        // ������Ԫ��
        DestroyTriplet(&T);
    }
    
    return 0;
}
