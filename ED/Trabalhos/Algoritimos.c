#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

#define TAM 10000

void generateRandomArray(int arr[]) {
  for (int i = 0; i < TAM; i++) arr[i] = rand() % 1000 + 1;
}

void printArray(int arr[]){
  for (int i = 0; i < TAM; i++) printf("%d ", arr[i]);
}

void swap(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void reset(int arr[], int copy[], int *comparacoes, int *trocas){
  memcpy(copy, arr, TAM * sizeof(arr[0]));
  *comparacoes = 0;
  *trocas = 0;
}

void bubbleSort(int arr[], int *comparacoes, int *trocas){
  int lastComparison = TAM - 1;
  for(int i = 0; i < TAM; i++){
    int isSorted = 1;
    for(int j = 0; j < lastComparison; j++){
      (*comparacoes)++;
      if(arr[j] > arr[j+1]){
        isSorted = 0;
        swap(&arr[j], &arr[j+1]);
        (*trocas)++;
      }
    }
    lastComparison--;
    if(isSorted) break;
  }
}

void insertionSort(int arr[], int *comparacoes, int *trocas){
  for(int i = 1; i < TAM; i++){
    int aux = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > aux){
      (*comparacoes)++;
      (*trocas)++;
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = aux;
  }
};

void selectionSort(int arr[], int *comparacoes, int *trocas){
  for(int i = 0, j = TAM - 1; i < j; i++, j--){
    int min = arr[i], max = arr[j];
    int min_index = i, max_index = j;

    for(int k = i; k <= j; k++){
      (*comparacoes)++;
      if(arr[k] < min){
        min = arr[k];
        min_index = k;
      }
      (*comparacoes)++;
      if(arr[k] > max){
        max = arr[k];
        max_index = k;
      }
    }

    swap(&arr[i], &arr[min_index]);
    if(max_index == i) max_index = min_index;
    swap(&arr[j], &arr[max_index]);
    (*trocas) += 2;
  }
};

int main() {
    srand(time(NULL));
    int arr[TAM], copia[TAM];
    int comparacoes, trocas;
    clock_t t;
    double time_taken;

    generateRandomArray(arr);

    // printf("VETOR DESORDENADO: \n");
    // printArray(arr);
    // printf("\n\n");

    // Bubble Sort
    reset(arr, copia, &comparacoes, &trocas);
    t = clock(); 
    bubbleSort(copia, &comparacoes, &trocas);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("BUBBLE: \n");
    printf("Comparacoes: %d\nTrocas: %d\nTempo: %lf\n\n", comparacoes, trocas, time_taken);
    // printf("Vetor: ");
    // printArray(copia);
    // printf("\n\n");

    // Insertion Sort
    reset(arr, copia, &comparacoes, &trocas);
    t = clock(); 
    insertionSort(copia, &comparacoes, &trocas);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("INSERTION: \n");
    printf("Comparacoes: %d\nTrocas: %d\nTempo: %lf\n\n", comparacoes, trocas, time_taken);
    // printf("Vetor: ");
    // printArray(copia);
    // printf("\n\n");

    // Selection Sort
    reset(arr, copia, &comparacoes, &trocas);
    t = clock(); 
    selectionSort(copia, &comparacoes, &trocas);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("SELECTION: \n");
    printf("Comparacoes: %d\nTrocas: %d\nTempo: %lf\n\n", comparacoes, trocas, time_taken);
    // printf("Vetor: ");
    // printArray(copia);
    // printf("\n\n");


    return 0;
}
