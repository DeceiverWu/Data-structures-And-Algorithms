package com.deceiver.algorithm.sort;

public class MergeSort {

    private static void mergeSort(int[] arr) {
        if(arr == null)
            return;

        int len = arr.length;
        int[] temp = new int[len];
        sort(arr, 0, len -1, temp);
    }

    private static void sort(int[] arr, int left, int right, int[] temp) {
        if(left < right) {
            int mid = (left + right) / 2;
            sort(arr, left, mid, temp);
            sort(arr, mid + 1, right, temp);
            merge(arr, left, mid + 1, right, temp);
        }
    }

    private static void merge(int[] arr, int left, int mid, int right, int[] temp) {
        int leftEnd = mid - 1;
        int index = left;
        int counts = right - left + 1;

        while(left <= leftEnd && mid <= right){
            if (arr[left] <= arr[mid]){
                temp[index++] = arr[left++];
            }else{
                temp[index++] = arr[mid++];
            }
        }

        while(left <= leftEnd){
            temp[index++] = arr[left++];
        }
        while(mid <= right){
            temp[index++] = arr[mid++];
        }

        for(int i = 0; i < counts; i++, right--){
            arr[right] = temp[right];
        }

    }

    public static void main(String[] args) {
        int[] arr = AlgorithmUtils.getRandomArray();
        mergeSort(arr);
        AlgorithmUtils.printArray(arr);
    }
}
