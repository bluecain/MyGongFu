#ifndef  _MY_UTILITY_H_
#define  _MY_UTILITY_H_

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class MyUtility
{
public:
	static string getCurrentTime();  //获取当前时间

	static string gbk_2_utf8(const string text);  //在Win32平台下，将GBK编码转换为UTF-8

	static string getUTF8Char(const string key);  //从plist文件中获取UTF-8字符

};

#endif // _MY_UTILITY_H_
