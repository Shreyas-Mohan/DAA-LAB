#include <bits/stdc++.h>
using namespace std;
void maxHeapify(vector<int>& A, int i)
{
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   int n = A.size();
   if (left < n && A[left] > A[largest])
      largest = left;
   if (right < n && A[right] > A[largest])
      largest = right;
   if (largest != i)
   {
      swap(A[i], A[largest]);
      maxHeapify(A, largest);
   }
}

void buildMaxHeap(vector<int>& A)
{
   int n = A.size();
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      maxHeapify(A, i);
   }
}

void heapSort(vector<int>& A)
{
   buildMaxHeap(A);
   int n = A.size();
   for (int i = n - 1; i >= 1; i--)
   {
      swap(A[0], A[i]);
      n--;
      maxHeapify(A, 0);
   }
}

int main()
{
   vector<int> A = {16, 4, 10, 8, 7, 9, 3, 2, 14, 1};
   maxHeapify(A, 1); // Change the index to test different scenarios
   cout << "Array after MAX-HEAPIFY: ";
   for (int val : A)
      cout << val << " ";
   cout << endl;
   heapSort(A);
   cout << "Array after HEAP SORT: ";
   for (int val : A)
      cout << val << " ";
   cout << endl;
   return 0;
}