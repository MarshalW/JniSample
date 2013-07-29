package com.sample.jni;

public class HelloWorld {
	public native String sayHello(String name);
	
	static{
		System.loadLibrary("HelloWorld");
	}
	
	public static void main(String[] args) {
		System.out.println(new HelloWorld().sayHello("李四"));
	}
}

