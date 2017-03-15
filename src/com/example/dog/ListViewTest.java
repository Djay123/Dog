package com.example.dog;

import java.util.ArrayList;
import java.util.HashMap;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class ListViewTest extends Activity{
	ListView listView = null;
	Button button = null;
	Button sa = null;
	Button buttonTemp = null;
	boolean b = true;
	String tag = "ListViewtest";
	private AlertDialog diag = null;
	String[] from = {"view","season"};
	int[] to = {R.id.imageview,R.id.itemtextview};
	String[] contant = {"��","��","��","��"};
	
	String XiaoYaoYou[] = {
	"��ڤ����",
	"����Ϊ��",
	"��֮��",
	"��֪�伸ǧ��Ҳ",
	"����Ϊ��",
	"����Ϊ��",
	"��֮��",
	"��֪�伸ǧ��Ҳ",
	"ŭ����",
	"����������֮��",
	"����Ҳ",
	"������������ڤ",
	"��ڤ��",
	"���Ҳ",
	"����г����",
	"־����Ҳ",
	"��г��֮��Ի",
	"��֮������ڤҲ",
	"ˮ����ǧ��",
	"�ҷ�ҡ�����߾�����",
	"ȥ������Ϣ��Ҳ",
	"Ұ��Ҳ",
	"����Ҳ",
	"����֮��Ϣ�വҲ",
	"��֮�Բ�",
	"����ɫа",
	"��Զ����������а",
	"������Ҳ",
	"������������"
	};
	
	ArrayList<HashMap<String, Object>> arrayList;
	ArrayAdapter<String> arrayAdapter;
	SimpleAdapter simpleAdapter = null;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.listviewupda);
		listView = (ListView)findViewById(R.id.listview);
		button = (Button)findViewById(R.id.buttonnotify);
		arrayList = new  ArrayList<HashMap<String,Object>>();
		for(int i = 0; i < XiaoYaoYou.length; i++)
		{
			HashMap<String, Object> hashMap = new HashMap<String, Object>();
			hashMap.put(from[0], R.drawable.ic_launcher);
			hashMap.put(from[1], XiaoYaoYou[i]);
			arrayList.add(hashMap);
		}
//		arrayAdapter = new ArrayAdapter<String>(this, 
//				android.R.layout.simple_expandable_list_item_1, contant);
//		listView.setAdapter(arrayAdapter);
		
		
		
		simpleAdapter = new SimpleAdapter(this, arrayList, R.layout.item, from, to);
		listView.setAdapter(simpleAdapter);
		
		String stitle = "RESET THE ECU";
		String scontant = "We are doing some thing,just wait a minute.";
		
		
		AlertDialog.Builder builder = new AlertDialog.Builder(ListViewTest.this);

		diag = builder.create();
		//diag.getWindow().setType(WindowManager.LayoutParams.TYPE_SYSTEM_ALERT);
		diag.setTitle(stitle);
		diag.setMessage(scontant);
		diag.show();
		
		button.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				
				int ilast = 0;
				int ifirst = 0;
				String strFirst = "The First Visible position:";
				String strLast = "The Last Visible position:";
				ifirst = listView.getFirstVisiblePosition();
				ilast = listView.getLastVisiblePosition();
				strFirst += ifirst;
				strLast += ilast;
				Log.i("ListView", strFirst);
				Log.i("ListView", strLast);
				
				if(b)
				{
					//ListView.getLastVisiblePosition();
					//ListView.getFirstVisiblePosition();

					b = false;
					contant[0] = "÷";
					contant[1] = "��";
					contant[2] = "��";
					contant[3] = "��";
					arrayList.clear();
					for(int i = 0; i < contant.length; i++)
					{
						HashMap<String, Object> hashMap = new HashMap<String, Object>();
						hashMap.put(from[0], R.drawable.ic_launcher);
						hashMap.put(from[1], contant[i]);
						
						arrayList.add(hashMap);
					}
					simpleAdapter.notifyDataSetChanged();
					diag.cancel();
				}
				else
				{
					b = true;
					contant[0] = "��";
					contant[1] = "��";
					contant[2] = "��";
					contant[3] = "��";
					arrayList.clear();
					for(int i = 0; i < XiaoYaoYou.length; i++)
					{
						HashMap<String, Object> hashMap = new HashMap<String, Object>();
						hashMap.put(from[0], R.drawable.ic_launcher);
						hashMap.put(from[1], XiaoYaoYou[i]);
						
						arrayList.add(hashMap);
					}
					simpleAdapter.notifyDataSetChanged();
				}
			}
		});
		
		sa = (Button)findViewById(R.id.start);
		sa.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String action = "com.example.dog.ListviewTest";
				Intent intent = new Intent();
				intent.setAction(action);
				startActivity(intent);
			}
		});
		
		buttonTemp = (Button)findViewById(R.id.TempStart);
		buttonTemp.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				Intent intent = new Intent(ListViewTest.this, TempActivity.class);
				startActivity(intent);
				
			}
		});
	}
	
	/* (non-Javadoc)
	 * @see android.app.Activity#onStart()
	 */
	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		super.onStart();
		Log.i(tag, "onStart");
	}

	/* (non-Javadoc)
	 * @see android.app.Activity#onRestart()
	 */
	@Override
	protected void onRestart() {
		// TODO Auto-generated method stub
		super.onRestart();
		Log.i(tag, "onRestart");
	}
	
	/* (non-Javadoc)
	 * @see android.app.Activity#onResume()
	 */
	@Override
	protected void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		Log.i(tag, "onResume");
	}
	/* (non-Javadoc)
	 * @see android.app.Activity#onNewIntent(android.content.Intent)
	 */
	@Override
	protected void onNewIntent(Intent intent) {
		// TODO Auto-generated method stub
		super.onNewIntent(intent);
		Log.i(tag, "onNewIntent");
	}
}
