#include<bits/stdc++.h>
using namespace std;


void swap(vector<int>& arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int random (int l, int r){
  srand(time(0));
  int i = (rand()%r)+l;
  return i;
}

int partition (vector<int>& arr, int l, int r){
  int x = arr[r];
  int i= l-1;
  for (int j=l; j< r; j++){
    if(arr[j] < x){
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i+1, r);
  return i+1;
}

int randomizedPartition(vector<int>& arr, int l, int r){
  int i= random(l, r);
  swap(arr, r, i);
  return partition(arr, l, r);
}

void randomizedQuickSort(vector<int>& arr, int l, int r){
  if(l<r){
    int q= randomizedPartition(arr, l, r);
    randomizedQuickSort(arr, l, q-1);
    randomizedQuickSort(arr, q+1, r);
  }
}
int main(){
  vector<int> arr{2, 3, 10, 1, 5, 4, 6};
  int l=0, r= arr.size()-1;
  randomizedQuickSort(arr, l, r);
  for(int i=0; i< arr.size(); i++){
    cout << arr[i] << " ";
  }
  return 0;
}