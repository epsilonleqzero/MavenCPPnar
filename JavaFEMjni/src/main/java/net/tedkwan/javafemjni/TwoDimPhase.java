


package net.tedkwan.javafemjni;

import java.io.IOException;

/**
 * This class is to interface with C++ using JNI.
 * 
 * It calls the rk45c library in C++ and runs the JNI
 * method.
 * 
 * @author Ted Kwan
 */
public class TwoDimPhase {
    
    /**
     * Access Native Library.
     */
    static {   
        try {    
            NativeUtils.loadLibraryFromJar("/lib/librk45c.so");   
        } catch (IOException e) {
            System.out.println("Failed to load lib.");
        }
    }

    /**
     * Pars has 8 fields:
     * 
     * h - index 0.
     * a-d are indices 1-4
     * tf - index 5.
     * x0 - index 6.
     * y0 - index 7.
     * z0 - index 8.
     * 
     * @param pars This is the double array passed to C++
     * @param pptype This is a string to pass to C++, it represents the name of the function to be run.
     * @return double array which represents x,y (and z). This needs to be split into a Nx2 (or Nx3) matrix to be parsed.
     */
    public native double[] rk4(double[] pars,String pptype);
    
    public TwoDimPhase(){
        
    }
    
}
