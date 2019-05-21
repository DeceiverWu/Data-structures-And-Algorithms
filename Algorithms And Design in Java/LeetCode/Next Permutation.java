/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {

    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        // finding first decreasing element
        while (i > 0 && nums[i + 1] < nums[i]) {
            i—-;
        }

        // finding a number just larger than first found element
        if (i >= 0) {
            int j = nums.length - 1;
            while(j >= 0 && nums[j] <= nums[i]) {
                j—;
            }
            swap(nums, i, j);
        }

        // reverse these number whose index larger than first found element
        reverse(nums, i + 1);
    }

    private void reverse(int[] arr, int start) {
        int i = start;
        int j = arr.length - 1;
        while (i < j) {
            swap(arr, i++, j—);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

