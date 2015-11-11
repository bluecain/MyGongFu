#ifndef  _MY_UTILITY_H_
#define  _MY_UTILITY_H_

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class MyUtility
{
public:
	static string getCurrentTime();  //��ȡ��ǰʱ��

	static string gbk_2_utf8(const string text);  //��Win32ƽ̨�£���GBK����ת��ΪUTF-8

	static string getUTF8Char(const string key);  //��plist�ļ��л�ȡUTF-8�ַ�

};

#endif // _MY_UTILITY_H_
