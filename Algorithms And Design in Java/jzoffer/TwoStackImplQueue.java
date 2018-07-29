package com.deceiver.jzoffer;

import java.util.NoSuchElementException;
import java.util.Stack;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-16
 * Time: 下午10:46
 */
public class TwoStackImplQueue {

    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();

    public void push(int e){
        stack1.push(e);
    }

    public int pop(){
        if (stack2.size() <= 0){
            while (stack1.size() > 0){
                stack2.push(stack1.pop());
            }
        }
        if (stack2.size() == 0) {
            throw new NoSuchElementException("queue is empty");
        }
        return stack2.pop();
    }
}
