#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define SEED 0

// PROTOTYPES
void selectionSort(int *vetor, int size, int *counter);
void bubbleSort(int *vetor, int size, int *counter);
void insertionSort(int *vetor, int size, int *counter);
int max(int *vetor, int start, int end, int *counter);
void troca(int *vetor, int bigger, int lastPosition);
void printVetor(int *vetor, int size);
void insertion(int *vetor, int size, int *counter);
int* randomVector(int n, int max, int seed);

void insertionSort(int *vetor, int size, int *counter){
  for(int i = 1; i < size; i++){
    insertion(vetor, i, counter);
  }
}

void selectionSort(int *vetor, int size, int *counter){
  int bigger;
  for(int i = size-1; i > 0; i--){
      bigger = max(vetor,0, i, counter);
      troca(vetor, bigger, i);
  }
}

void bubbleSort(int *vetor, int size, int *counter){
  for(int i = size-1; i > 0; i--){
    for(int j = 0; j < i; j++){
      *counter += 1;
      if(vetor[j] > vetor[j+1]){
        troca(vetor, j, j+1);
      }
    }
  }
}

void insertion(int *vetor, int size, int *counter){
  int i = size-1;
  int savedValue = vetor[size];

  while(i >= 0 && vetor[i] > savedValue){
    *counter += 1;
    vetor[i+1] = vetor[i];
    i--;
  }

  vetor[i+1] = savedValue;
}

int max(int *vetor, int start, int end, int *counter){
  int bigger = end;

  for(int i = start; i <= end; i++){
      if(vetor[i] > vetor[end] && vetor[i] > vetor[bigger]){
        *counter += 1;
        bigger = i;
      }

  }

  return bigger;
}

void troca(int *vetor, int bigger, int lastPosition){
  int n1 = vetor[lastPosition];
  vetor[lastPosition] = vetor[bigger];
  vetor[bigger] = n1;
}

void printVetor(int *vetor, int size){
  for(int i = 0; i < size; i++){
      printf("%d, ", vetor[i]);
  }
}

int* randomVector(int n, int max, int seed){
  int* v = (int*) calloc(n, sizeof(int));
  srand(seed);
  for(int i = 0; i < n; i++)
    v[i] = rand() % max;

  return v;
}

int main(int argc, char** argv){
  int counter = 0;
  int size = 10000;
  int max = 100;

  clock_t time;

  int *vet = randomVector(size, max, SEED);
  printf("=============\nSelection Sort\n");

  time = clock();
  selectionSort(vet, size, &counter);
  time = clock() - time;

  printf("Comparations Selection Sort: %d\n", counter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  counter = 0;


  int *vet2 = randomVector(size, max, SEED);
  printf("=============\nBubble Sort\n");

  time = clock();
  bubbleSort(vet2, size, &counter);
  time = clock() - time;
  

  printf("Comparations Bubble Sort: %d\n", counter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  counter = 0;


  int *vet4 = randomVector(size, max, SEED);
  printf("=============\nInsertion Sort\n");
 
  time = clock();
  insertionSort(vet4, size, &counter);
  time = clock() - time;

  printf("Comparations Insertion Sort: %d\n", counter);
  printf("It took %f seconds.\n", ((float)time/CLOCKS_PER_SEC));
  counter = 0;

  return 0;
}
