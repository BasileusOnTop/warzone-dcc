/*
Copyright (c) 2013 Daniele Bartolini, Michele Rossi
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

package crown.android;

import android.content.res.AssetManager;
import android.view.Surface;

public class CrownLib
{
	static 
	{
		System.loadLibrary("luajit-5.1");
		System.loadLibrary("crown");
	}
	
	// Device functions
	public static native void 		init();
	public static native void 		frame();
	public static native void 		shutdown();
	public static native boolean 	isInit();
	public static native boolean	isRunning();

	// AssetManager functions
	public static native void 		initAssetManager(AssetManager assetManager);

	// InputManager functions
	public static native void 		pushIntEvent(int type, int a, int b, int c, int d);
	public static native void 		pushFloatEvent(int type, float a, float b, float c, float d);

	// Window functions
	public static native void		setWindow(Surface window);
	public static native void 		setDisplaySize(int width, int height);
}
