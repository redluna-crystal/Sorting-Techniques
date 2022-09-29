#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr){
  int n = arr.size();
  for(int i= 0; i< n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      if (arr[j] > arr[j+1]){
        int key = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = key;
      }
    }
  }
}
void selectionSort(vector<int> &arr){
  int n = arr.size();
  for(int i = 0; i < n-1; i++){
    int min = i;
    for(int j=i+1; j < n; j++){
      if (arr[min] > arr[j]) min = j;
    }
    int key= arr[min];
    arr[min] = arr[i];
    arr[i] = key;
  }
}
void insertionSort(vector<int> &arr, int n){
  for (int j = 1 ; j < n ; j ++){
    int i = j -1 , key = arr[j];
    while(i >= 0 && arr[i] > key){
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1] =key;
  }
  return;
}
void recInsertionSort(vector<int> &arr, int len){
  //base case 
  if (len <= 1) return ;

  // recursively sort the len-1 items
  recInsertionSort(arr, len-1);

  //insert the nth item
  int j = len-2, key = len-1;
  while(j >= 0 && arr[j] >= key){
    arr[j+1] = arr[j];
    j--;
  }
  arr[j+1] = key;

}
int main(){
  vector<int> arr = {4,2, 5, 1, 2, 3,6, 3, 7};
  recInsertionSort(arr, arr.size());
  for(int a : arr) cout <<a << ' ' ;
  cout << endl;
  return 0;
}
