package com.deceiver.algorithm.sort;

public class ShellSort {

    private static void sort(int[] arr) {
        if(arr == null || arr.length == 0)
            return;
        shellSort(arr);
    }

    private static void shellSort(int[] arr) {
        int len = arr.length;

        for(int increment = len / 2; increment > 0; increment /= 2){
            for(int i = increment; i < len; i++){
                int temp = arr[i];
                int j;
                for(j = i; j >= increment && arr[j-increment] > temp; j -= increment){
                    arr[j] = arr[j-increment];
                }
                arr[j] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = AlgorithmUtils.getRandomArray();
        sort(arr);
        AlgorithmUtils.printArray(arr);
    }
}
