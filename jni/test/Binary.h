#ifndef		__BINARY_H__
#define		__BINARY_H__

#include "adsStd.h"
//#include "CommWithEcu.h"


class CBinary
{
protected:
	struct tagBinaryData 
	{
		unsigned char *m_pucBinary;
		short m_iDataLength;
		short m_iAllocLength;
		short m_iDefaultAddAllocLength;
		short m_iCitationCount;
	}*m_pbinData;

	enum
	{
		BN_ALL_DATA           = -1,
		BN_COMMON_ALLOCLENGTH = 6,
		BN_DEFALT_GROW_LENGTH = 100
	};

public:
	BYTE &operator [] (W_INT16 nIndex);
	// ȱʡ���캯��
	CBinary(void);

	// ���캯��
	CBinary(const CBinary& binData);

	// ���캯���������ڴ�
	CBinary(short iLength); 

	// ���캯������������ΪiLength�Ļ�����������pBuffer�����ݸ��Ƶ�������
	CBinary(const char *pBuffer, short iBufferLength);
	CBinary(unsigned char *pucBuffer, short iBufferLength);
	CBinary(string& pBuffer, short iBufferLength);

	// ��������
	~CBinary(void);

public:
	// ������
	void operator = (const CBinary binData);

	// �����������ݺϲ�
	CBinary& operator += (CBinary binData);


	// �����������ݻ�����β����һ���ֽ�����
	CBinary& operator += (unsigned char ucValue);
//	CBinary& operator += (char cValue);

	// ��������������ϲ�����������
	CBinary operator + (CBinary& binData);

	// ȡָ��λ�õ��ַ�����
	const unsigned char operator [] (short nIndex)const; 

	// �Ƚ϶��������ƴ��Ĵ�С
	bool operator < (CBinary& binData);
	bool operator <= (CBinary& binData);
	bool operator >= (CBinary& binData);
	bool operator > (CBinary& binData);

	// �Ƚ϶��������ƴ��Ĵ�С
	bool operator == (const CBinary& binData);

	// ȡָ��λ�õ��ַ�����
	unsigned char GetAt(short nIndex);

	// �ı�ָ��λ�õ��ַ�����
	bool SetAt(short nIndex, unsigned char ucNewElement);

	// �����������ݻ�����β����һ���ֽ�����
//	bool Add(char cNewElement);
	bool Add(unsigned char ucNewElement);

	// �趨����������ĳߴ�
	bool SetAllocLength(short iAllocLength, short iGrowBy = BN_DEFALT_GROW_LENGTH);

	// ȡ���ݳ���
	short GetSize(void);

	// ȡ���ݻ�����ָ��
	const unsigned char *GetBuffer(void);//const;

	// ���������ݵ�Ŀ�껺����
	short ReadBuffer(unsigned char *pucSrc, short iStart=0, short iLength = BN_ALL_DATA);
	short ReadBuffer(char *pSrc, short iStart=0, short iLength = BN_ALL_DATA);
	
	// ��ָ������������д������ڲ�
	short WriteBuffer(const unsigned char * pucSrc, short iWriteLength);
	short WriteBuffer(const char* pSrc, short iWriteLength);

    // ������׷�ӵ��������ݵĽ�β
//	short Append(char *pBuffer, short iWriteLength);
	short Append(unsigned char *pucBuffer, short iWriteLength);

	// �������Ƿ�Ϊ��
	bool IsEmpty(void);

	// �ͷ�δʹ�õ��ڴ�
	void FreeExtra(void);

	//�������ڵ���Ŀ��
	short GetBufSize(void);
	short GetCitationCount(void);
	short GetDefaultAddAllocLength(void);

private:
	void CopySelf(CBinary binData);
};

#endif		//__BINARY_H_

