package com.deceiver.algorithm.sort;

public class InsertSort {

    private static void sort(int[] arr) {
        int len = arr.length;
        int j;
        for(int i = 1; i < len; i++){
            int key = arr[i];
            for(j = i; j > 0 && arr[j-1] > key; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = key;
        }
    }

    public static void main(String[] args){
        int[] arr = AlgorithmUtils.getRandomArray();
        sort(arr);
        AlgorithmUtils.printArray(arr);
    }
}
