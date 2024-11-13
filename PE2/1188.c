#include<stdio.h>
#define size 12

int main (){
	int i, j;
	double sum=0, count=0, avarage=0, matrix[size][size];
	char op;
	
	fflush(stdin);
	scanf("%c", &op);
	
	for (i=0; i<size; i++){
		for(j=0; j<size; j++){
			scanf("%lf", &matrix[i][j]);
		}
	}

	int start = 5, end = 6;
	for (i=7; i<12; i++){
		for(j=start; j<=end; j++){
			sum+=matrix[i][j];
			count++;
		}
		start--;
		end++;
	}

	if (op == 'S'){
		printf("%.1lf\n", sum);	
	}else{
    avarage = (sum/count);
		printf("%.1lf\n", avarage);
	}
	
	return 0;
}