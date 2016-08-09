


package net.tedkwan.javafemjni;

import java.io.IOException;

/**
 *
 * @author devils
 */
public class TwoDimPhase {
    
    static {   
        try {    
            NativeUtils.loadLibraryFromJar("/lib/librk45c.so");   
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Failed to load lib.");
        }
    }

    /**
     * Pars has 5 fields:
     * 
     * gamma - index 0.
     * h - index 1.
     * tf - index 2.
     * x0 - index 3.
     * y0 - index 4.
     * 
     * 
     * @param pars
     * @return 
     */
    public native double[] rk4(double[] pars);
    
    public TwoDimPhase(){
        
    }
    
}
