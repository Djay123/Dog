/***************************************************************************//**
* \file		adsStd.h
* \brief	used as global header fot the whole DiagnosisBaseClass library
* \author	
*******************************************************************************/

#ifndef __I386_TYPES_H_
#define __I386_TYPES_H_

#undef DATA_DRV_EXT
#define DATA_DRV_EXT	// wrap extended contents specially for data driven task

#pragma  warning(disable:4786)
#include <string>
// #include <sstream>	seems not support under V30's ARM compiler (under WinCE)

#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

#ifdef DATA_DRV_EXT
#include <stdlib.h>
#ifdef WIN32
  #include <xstring>//avoid for ios
  #include <windows.h>//avoid for ios
  #include "SpxGasLibError.h"	// make use of its macro mechanism
  #include "DataCommon.h"		// make use of its debug/log output mechanism
#endif
// #include <tchar.h>	// to use _T



#define BT_FF					((BYTE)~0)
#ifndef DW_FFFFFFFF
#define DW_FFFFFFFF				((DWORD)~0)
#endif	// #ifndef DW_FFFFFFFF

#define  DATA_INVALIDATION			0			//added by bin

#define SZ_EMPTY				""
#define SZ_BS					"\\"			// back slash
#define SZ__					"_"
#define SZ_DOT_DAT				".dat"
#define SZ_WS					" "

// #define SCRIPT_NO_FIGS		6	/** script no.(dec) has 6 figures at most */
// #define SCRIPT_NO_UPBOUND	1000000

// pre-defined invalid DWORD value
#define INVALID_DWORD		DW_FFFFFFFF

// pre-defined file header length
#define DATA_DRV_FILE_HEAD_LEN	64

#endif	// #ifdef DATA_DRV_EXT


//数据类型定义
#ifndef CHAR
typedef char CHAR;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

#ifndef WORD
typedef unsigned short WORD;
#endif

#ifndef DWORD
typedef unsigned long DWORD;
#endif


#ifndef W_INT8
typedef char W_INT8;
#endif

#ifndef W_UINT8
typedef unsigned char W_UINT8;
#endif


#ifndef W_INT16
typedef short W_INT16;
#endif

#ifndef W_UINT16
typedef unsigned short W_UINT16;
#endif


#ifndef W_INT
typedef int W_INT;
#endif

#ifndef W_UINT
typedef unsigned int W_UINT;
#endif

#ifndef UINT
typedef unsigned int UINT;
#endif

/*
#ifndef WIN32
	#ifndef BOOL
	typedef bool BOOL;
	#endif
#endif
*/

#ifndef W_INT32
typedef int W_INT32;
#endif

#ifndef W_UINT32
typedef unsigned int W_UINT32;
#endif


#ifndef W_LONG
typedef long W_LONG;
#endif

#ifndef W_FLOAT
typedef double W_FLOAT;
#endif

#ifndef W_DOUBLE
typedef double W_DOUBLE;
#endif

#ifndef NULL
#define NULL	0
#endif

#ifndef FALSE
#define FALSE	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef max
#define max(a,b) (((a)>(b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a)<(b)) ? (a) : (b))
#endif

#define MAX_PATH	260


#define ID_BINARY_LENTH 6

//错误代码定义
#define EC_SUCCESS						0 	//执行成功

//通信类
#define EC_OVERTIME						-1	//通信超时
#define EC_BREAK						-2	//执行被中断
#define EC_ECU_NO_RESPONSION			-3	//ECU无应答
#define EC_ECU_RESONSE_NUM_WRONG		-4	//返回接收组数不对
#define EC_SEND_DATA_FAILED     		-5	//发送数据失败

#define EC_DOWN_BOARD_NO_RESPONSION		-10	//下位机无应答
//结果类
#define EC_IO_VOLTAGE_MATCH             -11	// 电压不匹配

//注：在IO口电压为5V时，测试到设定使用12V电平通信则会出现该错误代码；反之亦然。
#define EC_BUFFER_OVER					-12	//缓冲区溢出

//参数类
#define EC_ID_NUMBER					-101	//ID位数不匹配
#define EC_PARAMETER					-102	//无效参数
//	注：参数数值取值范围不合法

#define EC_DATA_FORMAT					-103	//数据格式错
//注：如CBinary标准ID长度为6个字节，如该参数中不为6位则报此错

#define EC_DB_DATA_STREAM               -104    // 数据流库中没找到
#define EC_TYPE_DATA_STREAM             -105    // 数据流库格式不一致
#define EC_ORDER_DATA_STREAM            -106    // 添加数据流次序错，添加数据流内容后不能再添加按纽

// 数据流错误码
#define DATASTEAM_ERRORDSITEM			-1	//数据流内容有误
#define	DATASTEAM_NOEXPRESS		    	-2	//数据流的公式表达式缺失
#define DATASTEAM_NOFORMAT		     	-3	//数据流的格式控制字符串缺失


// 多项选择类

#define EC_OVER_ITEM_NUM                -108    // 设置的被选项序号大于选项数量
#define EC_OVER_MASK_LEN                -109    // 掩码长度不够


#define  CHECKSTRING(x)	((x).length() == 0 ? FALSE:TRUE)
#define  CHECKDATA(x)	(((x) == DATA_INVALIDATION || !CHECKADDR(x)) ? FALSE:TRUE)

void TDSleep(W_INT32 iMilliseconds);

#endif	//	__I386_TYPES_H_
