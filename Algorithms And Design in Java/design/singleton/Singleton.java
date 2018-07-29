package com.deceiver.design.singleton;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午10:41
 */
public class Singleton {

    private static Singleton instance = null;

    private Singleton() {

    }

    public static final Singleton getInstance(){
        if (instance == null){
            synchronized (instance){
                if (instance == null){
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}
