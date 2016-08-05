#include <iostream>
#include "net_tedkwan_jni_nar_tests_NativeStuff.h"
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
using namespace std;

extern "C" void dgesv_(const int *N, const int *nrhs, double *A, const int *lda, int
	*ipiv, double *b, const int *ldb, int *info);

extern "C" void dgels_(const char *trans, const int *M, const int *N, const int *nrhs,
    double *A, const int *lda, double *b, const int *ldb, double *work,
    const int * lwork, int *info);

JNIEXPORT jdoubleArray JNICALL Java_net_tedkwan_jni_nar_tests_NativeStuff_twice(JNIEnv *env, jobject jobj, jdoubleArray jarray) {
    int i;
    jboolean isCopy1;

    jdouble* srcArrayElems = 
           env -> GetDoubleArrayElements(jarray, &isCopy1);
    jint n = env -> GetArrayLength(jarray);
/* Here it starts*/
        /* 3x3 matrix A
     * 76 25 11
     * 27 89 51
     * 18 60 32
     */
    double A[9] = {76, 27, 18, 25, 89, 60, 11, 51, 32};
    double b[3] = {10, 7, 43};

    int N = 3;
    int nrhs = 1;
    int lda = 3;
    int ipiv[3];
    int ldb = 3;
    int info;


    dgesv_(&N, &nrhs, A, &lda, ipiv, b, &ldb, &info);

    if(info == 0) /* succeed */
	printf("The solution is %lf %lf %lf\n", b[0], b[1], b[2]);
    else
	fprintf(stderr, "dgesv_ fails %d\n", info);
    
/* Here it ends*/
    jboolean isCopy2;   
    jdoubleArray result = env -> NewDoubleArray(n);
    jdouble* destArrayElems = 
           env -> GetDoubleArrayElements(result, &isCopy2);
       cout << "Hello from CPP!" << endl;    
    for (i = 0; i < n; i++) {
       destArrayElems[i] = 2 * srcArrayElems[i];
       cout << destArrayElems[i] << endl;
       //cout << result[i] << endl;
    } 

    if (isCopy1 == JNI_TRUE) {
       env -> ReleaseDoubleArrayElements(jarray, srcArrayElems, JNI_ABORT);
    }
       
    env->SetDoubleArrayRegion(result,0,n,destArrayElems);
    if (isCopy2 == JNI_TRUE) {
       env -> ReleaseDoubleArrayElements(jarray, destArrayElems, 0);
    }
    
    return result;
}