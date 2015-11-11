/*!
 * \file GlobalDefine.h
 * \date 2015/05/14 12:47
 *
 * \author SuooL
 * Contact: hu1020935219@gmail.com
 *
 * \brief ȫ�ֺ궨��
 *
 * TODO: long description
 *
 * \note
*/

#ifndef __GlobalDefine__H__
#define __GlobalDefine__H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

#define WINSIZE Director::getInstance()->getWinSize()

#define setIntToXML     UserDefault::getInstance()->setIntegerForKey
#define setFloatToXML   UserDefault::getInstance()->setFloatForKey
#define setBoolToXML    UserDefault::getInstance()->setBoolForKey
#define getIntFromXML   UserDefault::getInstance()->getIntegerForKey
#define getFloatFromXML UserDefault::getInstance()->getFloatForKey
#define getBoolFromXML  UserDefault::getInstance()->getBoolForKey

#define SOUND_KEY       "soundClose"            // ������Ч
#define MUSIC_KEY       "musicClose"              // ��������
#define SOUNDVOL        "soundVolume"        // ��Ч����
#define MUSICVOL        "musicVolume"          // ��������
#define EXP_KEY         "heroCurrentExp"        // Ӣ�۵�ǰ����
#define GAMELEVEL_KEY   "gameLevel"        // ��ǰ�ؿ�
#define HEROLEVEL_KEY   "heroLevel"          // ��ǰ�ȼ�
#define HEROCOIN_KEY    "heroCoin"            // Ӣ�۽��
#define HEROENERGY_KEY  "heroEnergy"   // Ӣ������
#define HEROHP_KEY      "heroHP"                // Ӣ��Ѫ��
#define HEROMP_KEY      "heroMP"               // Ӣ������
#define HEROAPOWER_KEY  "heroAPower"  // Ӣ���չ��˺�
#define HEROABILITY_KEY "heroAbility"        // Ӣ�������ȼ�
#define SELECTGATE      "selectGate"               // ѡ��Ĺؿ�
#define GATEONE         "gateOne"                     // ��һ��
#define GATETWO         "gateTwo"                    // �ڶ���
#define GATETHREE       "gateThree"               // ������
#define GAMEOVER        "gameOver"              // ��Ϸ�������

#define aduioEngine   SimpleAudioEngine::getInstance()


#define PLAYEFFECT if (getBoolFromXML(SOUND_KEY)) \
{\
	aduioEngine->setEffectsVolume(getFloatFromXML(SOUNDVOL));\
	aduioEngine->playEffect("Sound/button.wav");\
}

#endif