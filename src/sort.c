#include "sort.h"

static void swap(int *x, int *y) {
   int temp = *x;

   *x = *y;
   *y = temp;
}

void insertion_sort(int *data, const int size) {
   for(int i = 1; i <= size - 1; i++){
      for(int j=i; j > 0 && data[j - 1] > data[j]; j--){
         int t = data[j];
         data[j] = data[j - 1];
         data[j - 1] = t;
      }
   }
}

void selection_sort(int *data, const int size) {
   int i, j, min_id_x;

   for (i = 0; i < size-1; i++) {
      min_id_x = i;
      for (j = i+1; j < size; j++) {
         if (data[j] < data[min_id_x]) min_id_x = j;
      }

      swap(&data[min_id_x], &data[i]);
   }
}

void bubble_sort(int *data, const int size) {
   int i, j;

   for (i = 0; i < size-1; i++) {
      for (j = 0; j < size-1; j++) {
         if (data[j] > data[j+1]) swap(&data[j], &data[j+1]);
      }
   }
}

void shell_sort(int *data, const int size) {
   for (int interval = size / 2; interval > 0; interval /= 2) {
      for (int i = interval; i < size; i += 1) {
         int temp = data[i];
         int j;

         for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
            data[j] = data[j - interval];
         }

         data[j] = temp;
      }
   }
}