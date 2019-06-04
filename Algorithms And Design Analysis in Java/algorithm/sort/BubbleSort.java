package com.deceiver.algorithm.sort;

import java.util.Arrays;

public class BubbleSort {

    private static void sort(int[] arr){
        int len = arr.length;
        boolean tag = true;
        for(int i = 0; i < len && tag; i++){
            tag = false;
            for(int j = len - 1; j > i; j--){
                if(arr[j] < arr[j-1]){
                    arr[j] ^= arr[j-1];
                    arr[j-1] ^= arr[j];
                    arr[j] ^= arr[j-1];
                    tag = true;
                }
            }
        }
    }

    private static void sort_v2(int[] arr) {
        int len = arr.length;
        boolean tag = true;
        for(int i = 0; i < len - 1 && tag; i++) {
            tag = false;
            for(int j = 0; j < len - i -1; j++) {
                if(arr[j] > arr[j+1]){
                    arr[j] ^= arr[j+1];
                    arr[j+1] ^= arr[j];
                    arr[j] ^= arr[j+1];
                    tag = true;
                }
            }
        }
    }

    public static void main(String[] args){
        int[] arr = AlgorithmUtils.getRandomArray();
//        sort(arr);
        sort_v2(arr);
        AlgorithmUtils.printArray(arr);

    }
}
