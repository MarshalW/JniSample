package com.sample.jni;

public class HelloWorld {
	public native void sayHello(String name);
	
	static{
		System.loadLibrary("HelloWorld");
	}
	
	public static void main(String[] args) {
		new HelloWorld().sayHello("张三");
	}
}

