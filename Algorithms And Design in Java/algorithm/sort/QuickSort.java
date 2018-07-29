package com.deceiver.algorithm.sort;

public class QuickSort {

    private static void quickSort(int[] arr) {
        if(arr == null)
            return;
        sort(arr, 0, arr.length - 1);
    }

    private static void sort(int[] arr, int left, int right) {
        if(left < right) {
            int mid = partition(arr, left, right);
            sort(arr, left, mid - 1);
            sort(arr, mid + 1, right);
        }
    }

    private static int partition(int[] arr, int left, int right) {
        int key = arr[left];

        while(left < right){
            while(left < right && arr[right] >= key)
                right--;
            arr[left] = arr[right];

            while(left < right && arr[left] <= key)
                left++;
            arr[right] = arr[left];
        }

        arr[left] = key;
        return left;
    }

    public static void main(String[] args) {
        int[] arr = AlgorithmUtils.getRandomArray();
        quickSort(arr);
        AlgorithmUtils.printArray(arr);
    }
}
