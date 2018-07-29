package com.deceiver.jzoffer;

import java.util.ArrayList;
import java.util.Collections;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-23
 * Time: 下午7:19
 */
public class Permutation {

    public ArrayList<String> permutation(String str) {
        ArrayList<String> sorts = new ArrayList<>();
        if (str != null && str.length() > 0) {
            permutation(str.toCharArray(), 0, sorts);
            Collections.sort(sorts);
        }
        return sorts;
    }

    public void permutation(char[] str, int index, ArrayList<String> sorts){
        if (index == str.length - 1){
            String s = String.valueOf(str);
            sorts.add(s);
        } else {
            for (int i = index; i < str.length; i++){
                if (i == index || str[i] != str[index]) {
                    swap(str, index, i);
                    permutation(str, index + 1, sorts);
                    swap(str, index, i);
                }
            }
        }
    }

    public void swap(char[] str, int i, int j){
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    public static void main(String[] args) {
        Permutation permutation = new Permutation();
        ArrayList<String> ab = permutation.permutation("ab");
        System.out.println(ab.toString());
    }
}
