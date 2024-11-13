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
			if(j+i>11) {
				sum+=matrix[i][j];
				count++;
			}
		}
	}

	if (op == 'S'){
		printf("%.1lf\n", sum);	
	}else{
    avarage = (sum/count);
		printf("%.1lf\n", avarage);
	}
	
	return 0;
}