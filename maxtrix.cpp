#include<stdio.h>

#define MAX_SIZE 100 //����������ߴ�

//������˺���
void MatrixMultiply(int a[MAX_SIZE][MAX_SIZE],
	int b[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE],
	int rowA,int colA,int rowB,int colB){
		int i,j,k;
		
		//��ʼ���������Ϊ0
		for(i=0;i<rowA;i++){
			for(j=0;j<colB;j++){
				result[i][j]=0;
			}
		}
		
		//ִ�о���˷�
		for(i=0;i<rowA;i++){
			for(j=0;j<colB;j++){
				for(k=0;k<colA;k++){
					result[i][j] += a[i][k]*b[k][j];
				}
			}
		} 
	}
	
//��ӡ������
void PrintMatrix(int matrix[MAX_SIZE][MAX_SIZE],int
		rows,int cols){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d  ",matrix[i][j]);
		}
		printf("\n");
	}
} 

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowA, colA, rowB, colB;

    // �������A������������
    printf("Enter the dimensions of matrix A (rows x columns): ");
    scanf("%d %d", &rowA, &colA);

    // �������A��Ԫ��
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // �������B������������
    printf("Enter the dimensions of matrix B (rows x columns): ");
    scanf("%d %d", &rowB, &colB);

    // ȷ������A���������ھ���B������
    if (colA != rowB) {
        printf("The number of columns in A must be equal to the number of rows in B.\n");
        return 1;
    }

    // �������B��Ԫ��
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // �������
    MatrixMultiply(a, b, result, rowA, colA, rowB, colB);

    // ��ӡ�������
    printf("The result of matrix multiplication is:\n");
    PrintMatrix(result, rowA, colB);

    return 0;
}


