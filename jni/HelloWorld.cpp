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

JNIEXPORT void JNICALL Java_com_sample_jni_HelloWorld_sayHello
  (JNIEnv *env, jobject thiz){
	cout<<">>你好！"<<endl;
}



