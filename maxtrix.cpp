#include<stdio.h>

#define MAX_SIZE 100 //定义最大矩阵尺寸

//矩阵相乘函数
void MatrixMultiply(int a[MAX_SIZE][MAX_SIZE],
	int b[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE],
	int rowA,int colA,int rowB,int colB){
		int i,j,k;
		
		//初始化结果矩阵为0
		for(i=0;i<rowA;i++){
			for(j=0;j<colB;j++){
				result[i][j]=0;
			}
		}
		
		//执行矩阵乘法
		for(i=0;i<rowA;i++){
			for(j=0;j<colB;j++){
				for(k=0;k<colA;k++){
					result[i][j] += a[i][k]*b[k][j];
				}
			}
		} 
	}
	
//打印矩阵函数
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

    // 输入矩阵A的行数和列数
    printf("Enter the dimensions of matrix A (rows x columns): ");
    scanf("%d %d", &rowA, &colA);

    // 输入矩阵A的元素
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 输入矩阵B的行数和列数
    printf("Enter the dimensions of matrix B (rows x columns): ");
    scanf("%d %d", &rowB, &colB);

    // 确保矩阵A的列数等于矩阵B的行数
    if (colA != rowB) {
        printf("The number of columns in A must be equal to the number of rows in B.\n");
        return 1;
    }

    // 输入矩阵B的元素
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // 矩阵相乘
    MatrixMultiply(a, b, result, rowA, colA, rowB, colB);

    // 打印结果矩阵
    printf("The result of matrix multiplication is:\n");
    PrintMatrix(result, rowA, colB);

    return 0;
}


