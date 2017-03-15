package com.example.dog;

public class NativeClass {

	public NativeClass(){
		
	}
	public native void NativeInit();
	public native void NativeExit();
	public native String NativeStr(String str);
	
	static{
		System.loadLibrary("Dog");
	}
	
	public String NativeGetStr()
	{
		return NativeStr("Good");
	}
	

	
}
