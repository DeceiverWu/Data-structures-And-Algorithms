package com.deceiver.algorithm.sort;

public class HeapSort {

    private static void adjHeap(int[] arr, int k, int len){
        int temp = arr[k];
        for(int i = 2*k+1; i < len; i = 2*i+1){
            if((i+1) < len && arr[i+1] > arr[i]){
                i++;
            }
            if(arr[i] > temp){
                arr[k] = arr[i];
                k = i;
            }else{
                break;
            }
        }
        arr[k] = temp;
    }

    private static void swap(int[] arr, int x, int y){
        if(arr == null)
            return;

        arr[x] ^= arr[y];
        arr[y] ^= arr[x];
        arr[x] ^= arr[y];

    }

    private static void heapSort(int[] arr){
        if(arr == null){
            throw new NullPointerException();
        }
        int len = arr.length;
        for(int i = len/2 - 1; i >= 0; i--){
            adjHeap(arr, i, len);
        }

        for(int i = len - 1; i >= 0; i--){
            swap(arr, 0, i);
            adjHeap(arr, 0, i);
        }
    }

    public static void main(String[] args) {
        int[] arr = AlgorithmUtils.getRandomArray();
        heapSort(arr);
        AlgorithmUtils.printArray(arr);
    }
}
