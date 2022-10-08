#include "sort.h"

void insertion_sort(int *data, const int size) {
   for(int i = 1; i <= size - 1; i++){
      for(int j=i; j > 0 && data[j - 1] > data[j]; j--){
         int t = data[j];
         data[j] = data[j - 1];
         data[j - 1] = t;
      }
   }
}