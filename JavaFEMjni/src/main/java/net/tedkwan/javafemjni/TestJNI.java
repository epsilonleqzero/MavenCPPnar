/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.tedkwan.javafemjni;

/**
 *
 * @author devils
 */
public class TestJNI {
    
    public static void main(String [] args){
        TwoDimPhase phase=new TwoDimPhase();
        double[] initc = {0.05, 0.1, 1, 0.3,-1.0,30.0,0.3,0.6};
        double[] res = phase.rk4(initc);
        int r = res.length / 3;
    }
    
}
