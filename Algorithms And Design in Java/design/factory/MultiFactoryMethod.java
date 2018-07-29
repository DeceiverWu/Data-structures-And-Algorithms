package com.deceiver.design.factory;

import org.junit.Test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午9:41
 */
public class MultiFactoryMethod {


    private interface Sender {
        public void send();
    }

    private class  SmsSender implements Sender {

        @Override
        public void send() {
            System.out.println("This is sms...");
        }
    }

    private class MailSender implements Sender {

        @Override
        public void send() {
            System.out.println("This is mail...");
        }
    }

    public class SendFactory {

        public Sender newSmsSender() {
            return new SmsSender();
        }

        public Sender newMailSender() {
            return new MailSender();
        }
    }

    @Test
    public void test(){
        SendFactory sendFactory = new SendFactory();
        Sender sender = sendFactory.newMailSender();
        sender.send();
    }
}
