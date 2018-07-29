package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-20
 * Time: 下午10:10
 */

public class FindKthToTail {

    class ListNode{
        int val;
        ListNode next = null;

        ListNode(int val){
            this.val = val;
        }
    }

    public ListNode findKthToTail(ListNode pHead, int k){
        if (pHead == null || k <= 0 || k > Integer.MAX_VALUE){
            return null;
        }

        ListNode p1 = pHead;
        ListNode p2 = null;

        for (int i = 0; i < k - 1; i++){
            if (p1.next != null){
                p1 = p1.next;
            } else {
                // 说明链表根本没有那么长
                return null;
            }
        }

        p2 = pHead;
        while (p1.next != null){
            p1 = p1.next;
            p2 = p2.next;
        }
        return p2;
    }
}
