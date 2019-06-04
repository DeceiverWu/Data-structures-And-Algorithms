package com.deceiver.design.factory;

import org.junit.Test;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午1:08
 */
public class NormalFactoryMethod {

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

        public Sender produce(String type) {
            if ("mail".equals(type)){
                return new MailSender();
            } else if ("sms".equals(type)){
                return new SmsSender();
            } else {
                System.out.println("Please input correct type...");
                return null;
            }
        }
    }


    @Test
    public void testFactory(){
        SendFactory sendFactory = new SendFactory();
        Sender sms = sendFactory.produce("sms");
        Sender mail = sendFactory.produce("mail");
        sms.send();
        mail.send();
    }
}
