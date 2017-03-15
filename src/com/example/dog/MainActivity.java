package com.example.dog;

import java.util.HashMap;
import java.util.Timer;
import java.util.TimerTask;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends Activity {

	TextView tv;
	Button button = null;
	Button helloDog = null;
	String action = "com.example.dog.ListviewTest";
	String tag = "TestLiveTime";
	String strPath;
	String TAG = "MyDog";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv = (TextView)findViewById(R.id.textView1);
        NativeClass nc = new NativeClass();
        String str = nc.NativeGetStr();
        tv.setText(str);
        strPath = getApplicationContext().getFilesDir().getAbsolutePath();
        // /data/data/com.example.dog/files
        Log.i(TAG, "AbsolutePath: " + strPath);
        
        String strName = "Ford(Americal)";
        Log.i(TAG, "strName 1: " + strName);
        strName = strName.replace('(', '_').replace(')', ' ').trim();
        Log.i(TAG, "strName 2: " + strName);
        
        new Thread(new Runnable() {
			boolean finish = false;
			@Override
			public void run() {
				// TODO Auto-generated method stub
				Timer timer = new Timer();
				TimerTask task = new TimerTask() {
					
					@Override
					public void run() {
						// TODO Auto-generated method stub
						finish = true;
					}
				};
				timer.schedule(task, 10000);

				int i = 0;
				while(true)
				{
					if(finish)
					{
						//Toast.makeText(MainActivity.this, "Game Over", Toast.LENGTH_SHORT).show();
						timer.cancel();
						break;
					}
						
					try {
						Thread.sleep(500);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					++i;
					Log.i(tag,"i = " + i);
				}
			}
		}).start();
        
        byte[] ucCmd = new byte[100];
        ucCmd[0] = 0;
        ucCmd[1] = 1;
        ucCmd[2] = 0;
        ucCmd[3] = 3;
        ucCmd[0] = 0;
        
        int len = ucCmd.length;
        Log.i("lenByte", "ucCmd.length = " + len);
        
   
        button = (Button)findViewById(R.id.bt2);
        button.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				Intent intent = new Intent();
				intent.setAction(action);
				startActivity(intent);
			}
		});
       
    }
  

 

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
