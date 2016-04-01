#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swap(int *arr, int left,int right);
int partition(int * arr, int left ,int right);
void quickSort(int * arr,int left ,int right);

void swap(int * arr, int left ,int right){
    int tmp=arr[left];
    arr[left]=arr[right];
    arr[right]=tmp;
}

int partition(int *arr,int left,int right){
    int pivot=arr[right];
    while(left<right){
        while(left<right && arr[++left]<pivot);
        while(left<right && arr[--right]>pivot);
        swap(arr,left,right);
    }
    return left;
}

void quickSort(int *arr,int left,int right){
    if(left>=right)
        return;
    int pivotIndex=(left+right)/2;
    swap(arr,pivotIndex,right);
    pivotIndex=partition(arr,left-1,right);
    swap(arr,pivotIndex,right);
    quickSort(arr,left,pivotIndex-1);
    quickSort(arr,pivotIndex+1,right);
}
    
int main(){
    srand(time(0));
    const int num=100;
    int a[num];
    for(int i=0;i<num;++i){
        a[i]=(float)rand()/RAND_MAX*num;
        cout<<a[i]<<' ';
    }
    cout<<endl;
    quickSort(a,0,num-1);
    for(int i=0;i<num;++i){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}



