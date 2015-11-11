/*!
 * \file XmlParser.h
 * \date 2015/05/30 11:21
 *
 * \author SuooL
 * Contact: hu1020935219@gmail.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#ifndef __XMLParser_H__
#define __XMLParser_H__

#pragma once

#include <string>
#include "cocos2d.h"

class XMLParser : public cocos2d::Ref, public cocos2d::SAXDelegator
{
public:
	// ����ָ����xml�ļ�
	static XMLParser* parseWithFile(const char *xmlFileName);

	static XMLParser* parseWithString(const char *content);

	XMLParser();
	virtual ~XMLParser();

	// �ӱ���xml�ļ���ȡ
	bool initWithFile(const char *xmlFileName);
	// ���ַ��ж�ȡ�������ڶ�ȡ�����е�xml����
	bool initWithString(const char *content);

	// ��Ӧxml��ǩ��ʼ,�磺<string name="app_name">
	virtual void startElement(void *ctx, const char *name, const char **atts);

	// ��Ӧxml��ǩ����,�磺</string>
	virtual void endElement(void *ctx, const char *name);

	// ��Ӧxml��ǩ�ı�
	virtual void textHandler(void *ctx, const char *s, int len);

	// ��ȡ��Ӧ��ǩ���ַ���
	cocos2d::String* getString(const char *key);

private:
	cocos2d::CCDictionary *m_pDictionary;
	std::string m_key;

	std::string startXMLElement;
	std::string endXMLElement;

};

#endif