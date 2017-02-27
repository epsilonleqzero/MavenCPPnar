


package net.tedkwan.javafemjni;


import java.io.IOException;

/**
 * This class is to interface with C++ using JNI.
 * 
 * It calls the cFEM library in C++ and runs the JNI
 * method.
 * 
 * @author Ted Kwan
 */
public class FemBoltzman {
    /**
     * Access Native Library.
     */
    static {   
        try {    
            NativeUtils.loadLibraryFromJar("/lib/libcFEMnl.so");   
        } catch (IOException e) {
            System.out.println("Failed to load lib.");
        }
    }

    /**
     * This is the native method which calls C++
     * 
     * Pars has 5 fields:
     * 
     * x lower bound - index 0.
     * x upper bound - index 1.
     * y lower bound - index 2.
     * y upper bound - index 3.
     * h - index 4.
     * 
     * @param pars This is the double array passed to C++
     * @param femfun This is a string to pass to C++, it represents the name of the function to be run.
     * @return double array which represents x,y and u. This needs to be split into a Nx3 matrix to be parsed.
     */
    public native double[] cFEMnLin(double[] pars,String femfun, int J);
    
    public FemBoltzman(){
        
    }
    
}
