// Code For Quick Sort
#include <iostream>
using namespace std;
int partition(int *arr,int n,int s,int e){
     int pivot = arr[s];
    int pivotindex=s;
    for(int i=s+1;i<n;i++){
        if(arr[i]<pivot){
            pivotindex++;
        }
    }
    swap(arr[pivotindex],arr[s]);

    int i=s,j=e;
    
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }

    }
    return pivotindex;


}
void quicksort(int *arr,int n,int s,int e){
    // base case
    if(s>=e){
        return;
    }
    
    int p=partition(arr,n,s,e);

    // recursive formula
    quicksort(arr,n,s,p-1);
    quicksort(arr,n,p+1,e);
}
int main(){
    int n;
    cin>>n;

    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    quicksort(arr,n,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}