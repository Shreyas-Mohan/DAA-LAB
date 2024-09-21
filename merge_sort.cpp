#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
   int *new_arr = new int[e - s + 1];
   int i = s, j = mid + 1, k = 0;

   while (i <= mid && j <= e) {
      if (arr[i] <= arr[j]) {
         new_arr[k++] = arr[i++];
      } else {
         new_arr[k++] = arr[j++];
      }
   }

   while (i <= mid) {
      new_arr[k++] = arr[i++];
   }

   while (j <= e) {
      new_arr[k++] = arr[j++];
   }

   for (int i = s; i <= e; i++) {
      arr[i] = new_arr[i - s];
   }
}

void mergesort(int arr[], int s, int e) {
   if (s >= e) {
      return;
   }
   int mid = (s + e) / 2;
   mergesort(arr, s, mid);
   mergesort(arr, mid + 1, e);
   merge(arr, s, mid, e);
}

int main() {
   int arr[7] = {38, 27, 43, 3, 9, 82, 10};
   int n = 7;
   mergesort(arr, 0, n - 1);
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   return 0;
}