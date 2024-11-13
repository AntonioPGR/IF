#include<stdio.h>
#define size 12

int main (){
	int i, j;
	double sum=0, avarage=0, matrix[size][size];
	char op;
	
	fflush(stdin);
	scanf("%c", &op);
	
	for (i=0; i<size; i++){
		for(j=0; j<size; j++){
			scanf("%lf", &matrix[i][j]);
		}
	}

  for (i=0; i<size; i++){
    for(j=0; j<size; j++){
      if(i<j){
        sum += matrix[i][j];
      }
    }
  }

	if (op == 'S'){
		printf("%.1lf\n", sum);	
	}else{
    avarage = (sum/(((size*size)-size)/2));
		printf("%.1lf\n", avarage);
	}
	
	return 0;
}