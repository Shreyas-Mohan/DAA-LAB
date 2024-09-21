#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high) {
   int pivot = arr[low]; // taking first element as the pivot
   int i = low + 1; // start from the second number 
   int j = high;

   do // do-while ensures that the pointers are moved at least once
   {
      while (arr[i] <= pivot) // traverse until you find a number greater than pivot
      {
         i++;
      }

      while (arr[j] > pivot) // traverse until you find an element smaller than the pivot
      {
         j--;
      }
      if (i < j) // if j is still greater than i, swap the values where the while loop breaks in both the cases
      {
         swap(arr[i], arr[j]);
      }
   } while (i < j);
   swap(arr[low], arr[j]);
   return j;
}
void quickSort(int arr[], int low, int high){
   if (low < high){
      int partitionIndex = partition(arr, low, high); // same as merge sort, but here we specify the pivot element 
      quickSort(arr, low, partitionIndex - 1);
      quickSort(arr, partitionIndex + 1, high);
   }
   else{
      return;
   }
}
int main(){
   int arr[7] = {38, 27, 43, 3, 9, 82, 10};
   int n = 7;
   quickSort(arr, 0, n - 1);
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   return 0;
}