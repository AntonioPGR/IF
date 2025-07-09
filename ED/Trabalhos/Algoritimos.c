#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

#define TAM 50000

void generateRandomArray(int arr[]) {
  for (int i = 0; i < TAM; i++) arr[i] = rand() % TAM + 1;
}

void printArray(int arr[]){
  for (int i = 0; i < TAM; i++) printf("%d ", arr[i]);
}

void swap(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void reset(int arr[], int copy[]){
  memcpy(copy, arr, TAM * sizeof(arr[0]));
}

void bubbleSort(int arr[]){
  int lastComparison = TAM - 1;
  for(int i = 0; i < TAM; i++){
    int isSorted = 1;
    for(int j = 0; j < lastComparison; j++){
      if(arr[j] > arr[j+1]){
        isSorted = 0;
        swap(&arr[j], &arr[j+1]);
      }
    }
    lastComparison--;
    if(isSorted) break;
  }
}

void insertionSort(int arr[]){
  for(int i = 1; i < TAM; i++){
    int aux = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > aux){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = aux;
  }
};

void selectionSort(int arr[]){
  for(int i = 0, j = TAM - 1; i < j; i++, j--){
    int min = arr[i], max = arr[j];
    int min_index = i, max_index = j;

    for(int k = i; k <= j; k++){
      if(arr[k] < min){
        min = arr[k];
        min_index = k;
      }
      if(arr[k] > max){
        max = arr[k];
        max_index = k;
      }
    }

    swap(&arr[i], &arr[min_index]);
    if(max_index == i) max_index = min_index;
    swap(&arr[j], &arr[max_index]);
  }
};

int partition(int arr[], int low, int high){ 
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) { 
    if (arr[j] <= pivot) { 
      i++;
      swap(&arr[i], &arr[j]); 
    } 
  } 
  swap(&arr[i + 1], &arr[high]); 
  return (i + 1); 
} 
void quickSort(int arr[], int low, int high) { 
  if (low < high) { 
    int pi = partition(arr, low, high); 
    quickSort(arr, low, pi - 1); 
    quickSort(arr, pi + 1, high); 
  } 
} 

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;
	while(i < leftCount && j < rightCount) {
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}
void mergeSort(int *A,int n) {
	if(n < 2) return; 
	int mid,i, *L, *R;
	mid = n/2; 
	L = (int*) malloc(mid*sizeof(int));
	R = (int*) malloc((n- mid)*sizeof(int));
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];
	mergeSort(L,mid); 
	mergeSort(R,n-mid); 
	Merge(A,L,mid,R,n-mid); 
  free(L);
  free(R);
}


int main() {
    srand(time(NULL));
    int arr[TAM], copia[TAM];
    clock_t t;
    double time_taken;

    generateRandomArray(arr);

    // Bubble Sort
    reset(arr, copia);
    t = clock(); 
    bubbleSort(copia);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("BUBBLE: %lf\n", time_taken);

    // Insertion Sort
    reset(arr, copia);
    t = clock(); 
    insertionSort(copia);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("INSERTION: %lf\n", time_taken);

    // Selection Sort
    reset(arr, copia);
    t = clock(); 
    selectionSort(copia);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("SELECTION: %lf\n", time_taken);

    // Quick Sort
    reset(arr, copia);
    t = clock(); 
    quickSort(copia, 0, TAM-1);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("QUICK: %lf\n", time_taken);

    // Merge Sort
    reset(arr, copia);
    t = clock(); 
    mergeSort(copia, TAM);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("MERGE: %lf\n", time_taken);

    return 0;
}
