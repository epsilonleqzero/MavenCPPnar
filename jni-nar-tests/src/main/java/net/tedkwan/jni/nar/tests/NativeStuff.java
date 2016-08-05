/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.tedkwan.jni.nar.tests;

/**
 *
 * @author Devils
 */
public class NativeStuff {

    static {
        NarSystem.loadLibrary();
    }

    public native double[] twice(double[] a);

    public final native String sayHello();

    public static void main(String[] args) {
        double[] a = {1.0, 2.0, 3.0, 4.0};
        NativeStuff stuff = new NativeStuff();
            double [] b =stuff.twice(a);
            for(int i=0;i<b.length;i++){
                System.out.println(b[i]);
            }
        System.out.println(stuff.sayHello() +" from Java");
//		new NativeStuff().helloNative();
    }

}
