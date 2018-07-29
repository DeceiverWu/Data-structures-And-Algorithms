package com.deceiver.jzoffer;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-16
 * Time: 下午8:07
 */


public class PrintListFromTailToHead {

    class ListNode{

        int val;
        ListNode next = null;

        ListNode(int val){
            this.val = val;
        }
    }

    public ArrayList<Integer> printListFromTailToHead(ListNode listNode){
        LinkedList<Integer> stack = new LinkedList<>();
        while (listNode != null){
            stack.push(listNode.val);
            listNode = listNode.next;
        }

        ArrayList<Integer> arrayList = new ArrayList<>();
        while (!stack.isEmpty()){
            arrayList.add(stack.pop());
        }
        return arrayList;
    }
}
