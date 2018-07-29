package com.deceiver.design.singleton;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午10:28
 */
public class NormalSingleton {

    private static NormalSingleton instance = null;

    private NormalSingleton() {

    }

    public static NormalSingleton getInstance() {
        if (instance == null){
            instance = new NormalSingleton();
        }
        return instance;
    }
}
