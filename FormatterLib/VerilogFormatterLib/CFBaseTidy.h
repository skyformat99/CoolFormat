#ifndef CFBASETIDY_H
#define CFBASETIDY_H
#include <string>

class CCFBaseTidy
{
public:
	CCFBaseTidy();
	virtual ~CCFBaseTidy();

	/**
	* ��ʽ��
	* @param const char * pSourceIn
	* @param const char * pOptions
	* @param string & strOut
	* @param string & strErr
	* @return bool
	*/
	virtual bool TidyMain(const char* pSourceIn, const char* pOptions, std::string &strOut, std::string &strErr);

protected:

	/**
	* ���ø�ʽ������
	* @param void * pTidy ��ʽ��ָ��
	* @param const char * pOptions ����������
	*/
	void TidyOptionsSet(void* pTidy, const char* pOptions);

	/**
	* ��ʼ��Ĭ�ϵĸ�ʽ������
	*/
	virtual void InitTidyDefault();

	/**
	* ���ø�ʽ������
	* @param const char * pOptions ����������
	*/
	void SetTidyFromOptions(const char* pOptions);

	/**
	* ����ÿһ��Ĳ���
	* @param const char * pOption ����������
	* @param int nPos ��ʼλ��
	* @param int nSize ��С
	*/
	void SetTidyOption(const char* pOption, int nPos, int nSize);

	/**
	* ���þ��������
	* @param const std::string & strParam ������д��
	* @param int nNumValue ��ֵ
	* @param const std::string & strNumValue ��ֵ
	* @param const std::string & strTextValue �ı�ֵ
	*/
	virtual void SetTidyProp(const std::string& strParam, int nNumValue, const std::string& strNumValue, const std::string& strTextValue);

	/**
	* ����ĸ�ʽ����ָ��
	*/
	void* tidy;
};
#endif
