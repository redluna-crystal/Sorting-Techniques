#include <bits/stdc++.h>
using namespace std;


void mergefun (vector<int> &arr, int si, int mid , int ei){
  int i, j, k, nl, nr;
  //size of left and right arrays..
  nl = mid-si+1, nr = ei-mid;
  // fill left and right arrays
  int larr [nl], rarr[nr];
  for (i = 0; i < nl ; i++){
    larr[i] = arr[si+i];
  }
  for(j=0; j < nr; j++){
    rarr[j] = arr[mid+1+j];
  }
  i= 0, j=0, k = si;
  while(i < nl && j < nr){
    if(larr[i]<= rarr[j]){
      arr[k] = larr[i];
      i++;
    }
    else {
      arr[k] = rarr[j];
      j++;
    }
    k ++;
  }

  while(i < nl){ //extra element in larr
    arr[k] = larr[i];
    i++; k++;
  }
  
  while(j < nr){ //extra element int rarr
    arr[k] = rarr[j];
    j++; k++;
  }
}
void mergeSort(vector<int> &arr, int si, int ei){
  if (si < ei){
    int mid = si + (ei-si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    mergefun(arr, si, mid , ei);
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
int main(){
  vector<int> arr = {4,2, 5, 1, 2, 3,6, 3, 7};
  mergeSort(arr, 0, arr.size()-1);
  for(int a : arr) cout <<a << ' ' ;
  cout << endl;
  return 0;
}
