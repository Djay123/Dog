/**
 * 
 */
package com.example.dog;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

/** 
 * @author: Djay 
 * @version 创建时间：2016-8-26 上午10:36:37 
 * 类说明 
 */
/**
 * @author DJAY
 * @Datetime 2016-8-26 上午10:36:37
 */
public class TempActivity extends Activity {

	Button buttonBack = null;
	/* (non-Javadoc)
	 * @see android.app.Activity#onCreate(android.os.Bundle)
	 */
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_temp);
		buttonBack = (Button)findViewById(R.id.buttonback);
	
		buttonBack.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				Intent intent = new Intent(TempActivity.this, ListViewTest.class);
				startActivity(intent);
			}
		});
	}
}
