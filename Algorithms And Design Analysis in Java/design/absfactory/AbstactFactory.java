package com.deceiver.design.absfactory;

import org.junit.Test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午10:07
 */
public class AbstactFactory {

    @Test
    public void test(){
        MailFactory mailFactory = new MailFactory();
        mailFactory.newSender().send();

    }
}

interface Sender {
    public void send();
}

interface Provider {
    public Sender newSender();
}

class MailSender implements Sender {

    @Override
    public void send() {
        System.out.println("This is mail...");
    }
}

class SmsSender implements Sender {

    @Override
    public void send() {
        System.out.println("This is sms...");
    }
}

class MailFactory implements Provider {

    @Override
    public Sender newSender() {
        return new MailSender();
    }
}

class SmsFactory implements Provider {

    @Override
    public Sender newSender() {
        return new SmsSender();
    }
}



