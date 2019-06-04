package com.deceiver.design.factory;

import org.junit.Test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午9:51
 */
public class StaticFactoryMethod {

    @Test
    public void test(){
        Sender sender = SendFactory.newMailSender();
        sender.send();
    }
}


interface Sender {
    public void send();
}

class  SmsSender implements Sender {

    @Override
    public void send() {
        System.out.println("This is sms...");
    }
}

class MailSender implements Sender {

    @Override
    public void send() {
        System.out.println("This is mail...");
    }
}

class SendFactory {

    public static Sender newSmsSender() {
        return new SmsSender();
    }

    public static Sender newMailSender() {
        return new MailSender();
    }
}