#include <stdio.h>
int main() {
	int i, j;
	float matrix_1[2][2];
	float matrix_2[2][2];
	float sum[2][2];
	fflush(stdout);
	fflush(stdin);
//****************************************
	printf("enter matrix_1\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("enter a%d%d\n", i + 1, j + 1);
			scanf("%f", &matrix_1[i][j]);
		}
	}
//****************************************
	printf("enter matrix_2\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("enter b%d%d\n", i + 1, j + 1);
			scanf("%f", &matrix_2[i][j]);
		}
	}
//****************************************
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			sum[i][j]=matrix_1[i][j]+matrix_2[i][j];

		}
	}
//****************************************
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%0.1f\t",sum[i][j]);
		}
		printf("\n");
	}
//****************************************
}
