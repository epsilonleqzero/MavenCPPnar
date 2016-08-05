#include <stdio.h>
#include "net_tedkwan_jni_nar_tests_NativeStuff.h"

JNIEXPORT jstring JNICALL Java_net_tedkwan_jni_nar_tests_NativeStuff_sayHello( JNIEnv *env, jobject obj ) {
	jstring value;           /* the return value */

	char buf[40];            /* working buffer (really only need 20 ) */

	sprintf ( buf, "%s", "Hello NAR World!" );

	value = (*env)->NewStringUTF( env, buf );

	return value;
}
