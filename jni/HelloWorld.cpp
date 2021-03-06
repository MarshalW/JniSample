/*
 * HelloWorld.cpp
 *
 *  Created on: 2013年7月27日
 *      Author: marshal
 */

#include <jni.h>
#include <iostream>
#include "com_sample_jni_HelloWorld.h"

using namespace std;

string jstring2str(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("UTF8");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes",
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	string stemp(rtn);
	free(rtn);
	return stemp;
}

jstring str2jstring(JNIEnv* env, const char* pat) {
	jclass strClass = (env)->FindClass("Ljava/lang/String;");
	jmethodID ctorID = (env)->GetMethodID(strClass, "<init>",
			"([BLjava/lang/String;)V");
	jbyteArray bytes = (env)->NewByteArray(strlen(pat));
	(env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
	jstring encoding = (env)->NewStringUTF("UTF8");
	return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

JNIEXPORT jstring JNICALL Java_com_sample_jni_HelloWorld_sayHello(JNIEnv *env,
		jobject thiz, jstring name) {
	return str2jstring(env, (">>你好," + jstring2str(env, name) + " !").c_str());
}

