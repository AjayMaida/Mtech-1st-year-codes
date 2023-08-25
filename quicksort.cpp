#include<bits/stdc++.h>
//c++ code for quicksort algo

//recursive function to sort the array
void swap(std::vector<int> & arr,int i,int j){
int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
// int partition(std::vector<int>& arr, int l, int r){
//     int pivot=arr[r];//choosing last element as each all time
//     int i=l-1;//i is pointing to the last element which is smaller than pivot ele
//     for(int j=l;j<=r;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr,i,j);
//         }
//     }
//     swap(arr,i+1,r);//put pivot at its correct position in sorted array
//     return i+1;
// }
// void quickSort(std::vector<int>& arr, int l, int r){
//     if(l<r)//to ensure that we have atleast two ele
//     {
//         int pi=partition(arr,l,r);//funtion which will put pivot element at correct position and return its index
//         //rec call to left of pivot ele(which are smaller that pivot)
//         quickSort(arr,l,pi-1);
//         //for right ele(greater than pivot)
//         quickSort(arr,pi+1,r);

//     }
// }
void quickSort(std::vector<int>& arr, int low, int high)
    {
        // code here
        if(low>=high)return ;
        int pivot=arr[high];
        int i=low,j=low;
        while(i<=high){
            if(arr[i]<pivot){
                std::swap(arr[i],arr[j]);
                j++;
            }
            i++;
        }
        std::swap(arr[high],arr[j]);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
int main(void){
    std::vector<int> arr(5);
    for(auto &i:arr){
        std::cin>>i;
    }
    quickSort(arr,0,arr.size()-1);
    for(auto i:arr){
        std::cout<<i<<" ";
    }
}