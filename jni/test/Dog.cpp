#include <jni.h>
#include <string.h>
#include <string>
#include <android/log.h>
#include "Binary.h"
#include <unistd.h>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>

static const char* TAG = "MyDog";
using namespace std;
#define MY
#define M_Sprintf(_buf,_frm,arg) sprintf(_buf,_frm,arg)
static char table[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#ifndef SYSTM
typedef struct {
	int wYear;
	int wMonth;
	int wDay;
	int wHour;
	int wMinute;
	int wSecond;

} SYSTM;
#endif

typedef struct{

	string str1;
	int i;
	bool b;
}struct_test;



typedef unsigned int size_t;

void GetLocalTime(SYSTM* st);
char* _strrev(char* path);
char *itoa_my(int value,char *string,int radix);
void pStr(string& str1,string* str2,string str3);
char* w2c(wchar_t *pw,int* len);
wchar_t* c2w(const char *pc,int* len,wchar_t* lpwStr);
char* _ltoa(long value, char* string, int radix);
int argsSum(int arg,...);
void structTest(struct_test& t)
{
	t.str1 = "is OK";
}
//自己实现CBinary的排序
vector<CBinary> mYSort(vector<CBinary>::iterator begin,vector<CBinary>::iterator end);

/* 功能：将浮点型转为字符串
 * 参数：@f：浮点数
 * 	   @num：保留几位小数
 * 	   @position：小数点在第几位，输出参数
 * 	   @flag：0表示正数，1表示负数，输出参数
 * */
char* fcvt(double f,int num,int* position,int* flag);

#define test() \
int i = 10, j = 20; \
int sum = i + j;    \
s = sum;

short GetModuleFileName(char* strCurPath,long len)
{
//	int cnt = readlink("/proc/self/exe", strCurPath, len);
//	if (cnt < 0 || cnt >= len)
//	{
//		return -1;
//	}
	string strPath = "a/b/c";
	sprintf(strCurPath,"%s/",strPath.c_str());
	return strlen(strCurPath);
}


/* 毫秒级 延时 */
void Sleep(int ms)
{
#if 0
    struct timeval delay;
    delay.tv_sec = 0;
    delay.tv_usec = ms * 1000; // 20 ms
    select(0, NULL, NULL, NULL, &delay);
#endif
    usleep(ms * 1000);

}

void logPrintInfo(const char *tag,const char *fmt,...)
{

}
void Native_Init(JNIEnv* env,jobject thiz)
{

}
void Native_Exit(JNIEnv* env,jobject thiz)
{

}
jstring Native_Str(JNIEnv*env,jobject thiz,jstring str)
{
	//测试
	if(0)//测试时间的结构体
	{
		time_t now; //实例化time_t结构
		struct tm *timenow; //实例化tm结构指针
		time(&now);

		//time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now
		timenow = localtime(&now);
		__android_log_print(ANDROID_LOG_DEBUG,"ToDayis:","today is %4d%02d%02d%02d%02d%02d/n", timenow->tm_year+1900,
				timenow->tm_mon+1, timenow->tm_mday, timenow->tm_hour, timenow->tm_min,timenow->tm_sec);
	}
	//时间函数结封装，在诊断中这样写的
	if(0)
	{
		SYSTM st;
		GetLocalTime(&st);
//		__android_log_print(ANDROID_LOG_DEBUG,"ToDayis:","today is %4d%02d%02d%02d%02d%02d/n", st->tm_year,
//				st->tm_mon, st->tm_mday, st->tm_hour, st->tm_min,st->tm_sec);

		__android_log_print(ANDROID_LOG_DEBUG,"ToDayis:","today is %4d-%02d-%02d %02d:%02d:%02d", st.wYear,
				st.wMonth, st.wDay, st.wHour, st.wMinute,st.wSecond);
	}


	if(0)//测试两个CBinary的重载操作符
	{
		CBinary binary1 = NULL;
		CBinary binary2 = NULL;
		binary1.Add(0x1);
		string strbuffer = "hello";
		binary2 = CBinary("\x2\x2",2);

		__android_log_print(ANDROID_LOG_DEBUG,"TestBinary",
				"before binary2 len = %d buffer[0,1] = %d %d",binary2.GetSize(),
				binary2.GetAt(0),
				binary2.GetAt(1));

		binary1+=binary2;
		__android_log_print(ANDROID_LOG_DEBUG,"TestBinary",
				"after binary2 len = %d buffer[0,1] = %d %d",binary2.GetSize(),
				binary2.GetAt(0),
				binary2.GetAt(1));

		__android_log_print(ANDROID_LOG_DEBUG,"TestBinary",
				"binary1 len = %d buffer[0 - 2] = %d %d %d",binary1.GetSize(),
				binary1.GetAt(0),
				binary1.GetAt(1),
				binary1.GetAt(2));
	}

/*
	if(0)//测试得到当前程序的绝对路径
	{

		char strCurPath[200];
		char strName[20];

		memset(strCurPath,0,sizeof(strCurPath));
		memset(strName,0,sizeof(strName));
		sprintf(strName,"/hello world");
		short nct = GetModuleFileName(strCurPath,sizeof(strCurPath));
		__android_log_print(ANDROID_LOG_DEBUG,"TestBinary","strCurPath = %s,nct = %d",strCurPath,nct);

		sprintf(strCurPath + strlen(strCurPath),"%s",strName);
		__android_log_print(ANDROID_LOG_DEBUG,"TestBinary","strCurPath = %s",strCurPath);

	}
*/
	if(0)
	{
		unsigned int tt = 16908543;
		int rr = tt >> 16;
		int xx = (tt >> 16)&0xFF;
		__android_log_print(ANDROID_LOG_DEBUG,"TestInt","strCurPath = %d, xx = %d",rr,xx);
	}
	//linux实现毫秒级延时和微妙级别的延时
	if(0)
	{
		__android_log_write(ANDROID_LOG_DEBUG,"sleepms","sleep 0s");
		usleep(4000 * 1000);//延时4秒
		__android_log_write(ANDROID_LOG_DEBUG,"sleepms","sleep 4s");
		usleep(1000);//延时1毫秒
		__android_log_write(ANDROID_LOG_DEBUG,"sleepms","sleep ms");
		sleep(5);//延时5秒
		__android_log_write(ANDROID_LOG_DEBUG,"sleepms","sleep 7s");

	}

	if(0)
	{
	    struct timespec ts;

	    clock_gettime(CLOCK_MONOTONIC, &ts);

	    unsigned long times = (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
	    __android_log_print(ANDROID_LOG_DEBUG,"timems","times = %ld",times);
	}
	/*测试short的-1值*/
	if(0)
	{
		short ishort = -1;
		if(ishort >= 0)
		{
			__android_log_write(ANDROID_LOG_DEBUG,"TestShort","ishort = -1 >= 0");
		}
		else
		{
			__android_log_write(ANDROID_LOG_DEBUG,"TestShort","ishort = -1 <= 0");
		}
		ishort = 0xFF;
		if(ishort >= 0)
		{
			__android_log_write(ANDROID_LOG_DEBUG,"TestShort","ishort = 0xFF >= 0");
		}
		else
		{
			__android_log_write(ANDROID_LOG_DEBUG,"TestShort","ishort = 0xFF <= 0");
		}
	}


	if(0)
	{
		char path[] = "hello world";

		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","path : %s len = %d",path,strlen(path));


		char* result = _strrev(path);
		int len = strlen(result);

		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","path reverse: %s len = %d",result,len);
	}

	//测试itoa
	if(0)
	{
		int num = 123456;
		char* strNum = new char[20];
		memset(strNum,0,20);
		itoa_my(num,strNum,16);

		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","strNum: %s",strNum);
	}

	//测试C++的传值：参数是引用的情况
	if(0)
	{
		string str1,str2,str3;
		pStr(str1,&str2,str3);
		string str = "str1: " + str1 + "str2: " + str2 + "str3: " + str3;
		//str1: hellostr2: wroldstr3:
		__android_log_write(ANDROID_LOG_DEBUG,"MyDog",str.c_str());
	}
	//测试sprintf的宏定义
	if(0)
	{
		char* buf = new char[100];
		char* frm = "%s";
		const char* arg = "hello world";
		memset(buf,0,100);
		M_Sprintf(buf,frm,arg);
		__android_log_write(ANDROID_LOG_DEBUG,"MyDog",buf);


		delete[] buf;
	}
	//unsigned char* 转wstring
	if(0)
	{
		unsigned short pw[6] = {200,100,300,500,600,700};
		wstring ws;
		for(int i = 0; i < 6; i++)
		{
			wchar_t temp = pw[i];
			ws += temp;
		}
		int size = ws.size();
		wchar_t mY0 = ws[0];
		wchar_t mY5 = ws[5];
		// size = 6, ws[0] = 200 ws[5] = 700
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","size = %d, ws[0] = %d ws[5] = %d",size,mY0,mY5);
	}
	//char* 转 wchar_t*
	if(0)
	{
/*
		char* lpcStr = "hello world";
		int i = 0;
		wchar_t* lpwStr = new wchar_t[100];
		memset(lpwStr,0,100);
		for(i = 0; i < strlen(lpcStr); i++)
		{
			lpwStr[i] = lpcStr[i];
		}
		lpwStr[i] = '\0';
		//lpwStr[0 - 5]:h,e,l,l,o
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","lpwStr[0 - 5]:%c,%c,%c,%c,%c",lpwStr[0],lpwStr[1],
				lpwStr[2],lpwStr[3],lpwStr[4]);
*/
		char* lpcStr = "The city is so big but the life is so small!";
		int len = 0;
		wchar_t* lpMyStr = new wchar_t[200];
		memset(lpMyStr,0,200);
		wchar_t* lpwStr = c2w(lpcStr,&len,lpMyStr);

		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","lpcStr: %s",lpcStr);
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","lpwStr: %s len = %d",lpwStr,len);
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","lpMyStr: %s",lpMyStr);

	}


	if(0)
	{
		int s = 0;
		test();
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","s = %d", s);
	}

	//测试删除一个文件,未能成功删除hello.txt文件
	if(0)
	{
		char* command = new char[200];
		memset(command,0,200);
		char* fileName = "/Vpecker/hello.txt";
		sprintf(command,"rm %s",fileName);

		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","command : %s",command);
		if(access(fileName,F_OK))//文件存在
		{
			__android_log_write(ANDROID_LOG_DEBUG,"MyDog","file Exit");
		}
		else
		{
			__android_log_write(ANDROID_LOG_DEBUG,"MyDog","file not Exit");
		}
		//system(command);没用
		//system("del /Vpecker/hello.txt");
		unlink("/Vpecker/hello.txt");
		int result = remove("/Vpecker/hello.txt");
		//__android_log_print(ANDROID_LOG_DEBUG,"MyDog","remove result: %d ",result);
	}
	//测试将long类型转换成任意进制的字符串
	if(0)
	{
		long mLong = 4002;
		char* result = new char[100];
		memset(result,0,100);
		char* str = _ltoa(mLong,result,2);
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","str:%s, result:%s",str,result);
		delete result;
		result = NULL;
	}
	//测试可变参数
	if(0)
	{
		int arg1 = 100, arg2 = 200, sum = 0;
		sum = argsSum(2,arg1,arg2);
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","argsSum = %d",sum);
	}
/*
	//测试CBinary的排序
	if(0)
	{
		vector<CBinary> vCbr;
		vCbr.push_back(CBinary("\x01\x02\x03",3));
		vCbr.push_back(CBinary("\x05\x02\x05\x04",4));
		vCbr.push_back(CBinary("\x04\x02\x04\x04\x05",5));
		//01-19 08:59:04.680: D/MyDog(6580): num: 1 5 4
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","num: %d %d %d ",vCbr[0].GetAt(0),vCbr[1].GetAt(0),vCbr[2].GetAt(0));
		vCbr = mYSort(vCbr.begin(),vCbr.end());
		//01-19 08:59:04.680: D/MyDog(6580): num: 1 4 5
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","num: %d %d %d ",vCbr[0].GetAt(0),vCbr[1].GetAt(0),vCbr[2].GetAt(0));
	}
*/
	//测试将浮点数转为字符串
	if(0)
	{
		char str[100];
		double f = 145698745.123456789;
		sprintf(str,"%.16lf",f);
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","str: %s",str);
/*
		fcvt(str, 23.56821312, 8, 10);
		//01-19 09:28:34.320: D/MyDog(11116): str: 00000023.5682131777
		__android_log_print(ANDROID_LOG_DEBUG,"MyDog","str: %s",str);
*/
	}

	string strValue;
	if(0)
	{
		//在大平板上可以打开这个路径，大平板是root过的"/sdcard/Vpecker/SCAN/PRO/OBDII/EN/EN.txt";
		const char* pathFile = "/sdcard/Vpecker/SCAN/PRO/TPMS/EN/EN.txt";
		FILE* mFile = NULL;
		mFile = fopen(pathFile,"rb");
		if(NULL == mFile)
		{
			__android_log_write(ANDROID_LOG_DEBUG,"MyDog","File open Failed");
			perror("Open Failed");

		}
		else
		{
			wchar_t *szBuff = new wchar_t[20];
			fread(szBuff, 1, 20, mFile);
			__android_log_print(ANDROID_LOG_DEBUG,"MyDog","read value: %s",szBuff);
			delete szBuff;
			szBuff = NULL;
		}
	}


	//延时函数测试：在不同手机上
	if(0)
	{
		__android_log_write(ANDROID_LOG_DEBUG,"MyDog","begin");
		for(int i = 0; i < 10; i++)
		{
			Sleep(i * 1000);
			__android_log_print(ANDROID_LOG_DEBUG,"MyDog","Delayed %d Sec",i);
		}
	}

	//测试%c和%c
	if(0)
	{
		const char* buffer = "ABabcdef";
		char* bufferFormat = new char[100];
		memset(bufferFormat,0,100);
		int len = strlen(buffer);
		__android_log_print(ANDROID_LOG_DEBUG,TAG,"len of buffer: %d",len);
		for(int i = 0; i < len; i++)
		{
			sprintf(bufferFormat,"%s%c",bufferFormat,buffer[i]);
		}
		return env->NewStringUTF(bufferFormat);
	}
	//测试打印函数
	if(0)
	{
		const char* str = "hello world";
		int i = 100;
		//logPrintInfo("logPrint","%s%d",str,i);
	}
	//测试结构体中的值能否赋值
	if(0)
	{
		struct_test mTest;
		mTest.b = true;
		__android_log_write(ANDROID_LOG_DEBUG,TAG,"before");
		//如果对一个结构体进行设0操作，其中的基本数据类型是可以进行再赋值，对于对象比如(string)类型进行任何操作都会报错。
		memset(&mTest,0,(int)sizeof(struct_test));
		structTest(mTest);
		__android_log_write(ANDROID_LOG_DEBUG,TAG,"after");
	}
	//测试vector的赋值问题
	if(1)
	{
		vector<int> vecSrc;
		vector<int> vecDest;
		vecSrc.clear();
		for(int i = 0; i < 10; i++)
		{
			vecSrc.push_back(i);
			__android_log_print(ANDROID_LOG_DEBUG,"MyDog","vecSrc[%d] : %d",i,vecSrc[i]);
		}
		for(int i = 0; i < 10; i++)
		{
			vecDest.push_back((int)vecSrc[i]);
			__android_log_print(ANDROID_LOG_DEBUG,"MyDog","vecDest[%d] : %d",i,vecDest[i]);
		}
	}



	return env->NewStringUTF("Hello \n dog");
}


char *itoa_my(int value,char *string,int radix)
{
    char zm[37]="0123456789abcdefghijklmnopqrstuvwxyz";
    char aa[100]={0};

    int sum=value;
    char *cp=string;
    int i=0;

    if(radix<2||radix>36)//增加了对错误的检测
    {
        return string;
    }

    if(value<0)
    {
        return string;
    }


    while(sum>0)
    {
        aa[i++]=zm[sum%radix];
        sum/=radix;
    }

    for(int j=i-1;j>=0;j--)
    {
        *cp++=aa[j];
    }
    *cp='\0';
    return string;
}

char* _strrev(char* path)
{
	char* result = new char[strlen(path)];
	strcpy(result,path);
	for(int i = 0; i < strlen(path); i++)
	{
		*(path + i) = *(result + strlen(result) - 1 -i);
	}

	delete result;
	result = NULL;
	return path;
}
void GetLocalTime(SYSTM* st)
{
	time_t now; //实例化time_t结构
	time(&now);
	struct tm* timeNow;
	//time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now
	timeNow = localtime(&now);

	st->wYear = timeNow->tm_year + 1990;
	st->wMonth = 1 + timeNow->tm_mon;
	st->wDay = timeNow->tm_mday;
	st->wHour = timeNow->tm_hour;
	st->wMinute = timeNow->tm_min;
	st->wSecond = timeNow->tm_sec;
}
static JNINativeMethod gMethods[] =
{
	{"NativeInit","()V",(void*)Native_Init},
	{"NativeExit","()V",(void*)Native_Exit},
	{"NativeStr","(Ljava/lang/String;)Ljava/lang/String;",(void*)Native_Str}
};

jint JNI_OnLoad(JavaVM* vm,void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;
	if(vm->GetEnv((void**)&env,JNI_VERSION_1_4) != JNI_OK)
	{
		return JNI_ERR;
	}
	jclass clazz = env->FindClass("com/example/dog/NativeClass");
	if(clazz == NULL)
	{
		__android_log_write(ANDROID_LOG_DEBUG, "Dog.cpp","JNI_OnLoad");
		return -1;
	}
	env->RegisterNatives(clazz,gMethods,(int)(sizeof(gMethods)/sizeof(gMethods[0])));
	return JNI_VERSION_1_4;
}

/* 卸载JNI库 */
void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{
	__android_log_write(ANDROID_LOG_DEBUG, "Dog.cpp","JNI_OnUnload");
}
void pStr(string& str1,string* str2,string str3)
{
	str1 = "hello";
	*str2 = "wrold";
	str3 = "everyone";
}

size_t get_wchar_size(const char *str)
{
	size_t len = strlen(str);
	size_t size=0;
	size_t i;
	for(i=0; i < len; i++)
	{
	   if( str[size] >= 0 && str[size] <= 127 ) //不是全角字符
	   size+=sizeof(wchar_t);
	   else //是全角字符，是中文
	   {
	   size+=sizeof(wchar_t);
	   i+=2;
	   }
	}
	return size;
}

//宽字节转多字节
char* w2c(wchar_t *pw,int* len)
{
	setlocale(LC_ALL,"zh_CN.utf8");

	if(!pw)
	   return NULL;
	size_t size= wcslen(pw)*sizeof(wchar_t);
	char* pc;
	if(!(pc = (char*)malloc(size)))
	{
	   printf("malloc fail");
	   return NULL;
	}

	wcstombs(pc,pw,size);
	*len = size;
	return pc;
}

//多字节转宽字节
wchar_t* c2w(const char *pc,int* len,wchar_t* lpwStr)
{
	setlocale(LC_ALL,"zh_CN.utf8");

	if(!pc)
	   return NULL;
	size_t size_of_ch = strlen(pc)*sizeof(char);
	size_t size_of_wc = get_wchar_size(pc);

	wchar_t* pw;
	if(!(pw = (wchar_t*)malloc(size_of_wc)))
	{
	   printf("malloc fail");
	   return NULL;
	}
	mbstowcs(pw,pc,size_of_wc);

	memcpy(lpwStr,pw,size_of_wc);
	*len = size_of_wc;
	return pw;
}
char* _ltoa(long value, char* string, int radix)
{
	return " ";
	/*
    char tmp[33];
    char* tp = tmp;
    long i;
    long v;
    int sign;
    char* sp;

    if (radix > 36 || radix <= 1)
    {

        return 0;
    }

    sign = (radix == 10 && value < 0);
    if (sign)
        v = -value;
    else
        v = (unsigned long)value;
    while (v || tp == tmp)
    {
        i = v % radix;
        v = v / radix;
    if (i < 10)
        *tp++ = i+'0';
    else
        *tp++ = i + 'a' - 10;
    }

    if (string == 0)
        string = (char*)malloc((tp-tmp)+sign+1);
    sp = string;

    if (sign)
        *sp++ = '-';
    while (tp > tmp)
        *sp++ = *--tp;
        *sp = 0;
    return string;
    */
}
int argsSum(int arg,...)
{
	int val = 0;
   va_list ap;
   int i;

   va_start(ap, arg);
   for(i = 0; i < arg; i++)
   {
	  val += va_arg(ap, int);
   }
   va_end(ap);

   return val;
}

vector<CBinary> mYSort(vector<CBinary>::iterator begin,vector<CBinary>::iterator end)
{

	vector<CBinary> temp;
	for(;begin < end; begin++)
	{
		temp.push_back(*begin);
	}

	for(int i = 0; i < temp.size() - 1; i++)
	{
		for(int j = 0; j < temp.size() - 1 - i; j++)
		{
			if(temp[j] > temp[j + 1])
			{
				CBinary t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
		}
	}

	return temp;


}



char* fcvt(double f,int num,int* position,int* flag)
{
	if (num >= 15)
	{
		num = 14;
	}
	int i = 0,j = 0,k = 0;
	char* result = new char[100];
	memset(result,0,100);
	char* str = new char[100];
	memset(str,0,100);
	sprintf(str,"%.15lf",f);
	if (str[0] == '-')
	{
		*flag = 1;
		++j;
	}
	else
	{
		*flag = 0;
	}

	for (; j < strlen(str); j++,k++)
	{
		if (str[j] == '.')
		{
			*position = k;
			break;
		}
		result[k] = str[j];
	}

	int m = 0;
	for (j = j + 1; j < strlen(str); j++,k++,m++)
	{
		if (m == num)
		{
			break;
		}
		result[k] = str[j];
	}

	delete str;
	str = NULL;
	return result;
}


