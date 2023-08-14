// Code For Merge Sort
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int n,int s,int e){
    int mid=s+(e-s)/2;
    int n1=mid-s+1;
    int n2=e-mid;
    
    int arr1[n1]={0};
    int arr2[n2]={0};
    int mainindex=s;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[mainindex++];
    }
    mainindex=mid+1;
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mainindex++];
        
    }

    int i=0;
    int j=0;
    mainindex=s;
    while(i<n1 && j<n2){
    if(arr1[i]<arr2[j]){
        arr[mainindex++]=arr1[i++];
    }
    else{
        arr[mainindex++]=arr2[j++];
    }
    }
    while(i<n1){
        arr[mainindex++]=arr1[i++];
    }
    while(j<n2){
        arr[mainindex++]=arr2[j++];
    }

}
void sort(int *arr,int n,int s,int e){

    // base case
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    // recursive formula

    sort(arr,n,s,mid);
    sort(arr,n,mid+1,e);

    merge(arr,n,s,e);

}

int main()
{
    int n;
    cin>>n;

    int arr[n]={0};

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,n,0,n-1);

    

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}