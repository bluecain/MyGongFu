/*!
 * \file GlobalData.h
 * \date 2015/05/14 12:51
 *
 * \author SuooL
 * Contact: hu1020935219@gmail.com
 *
 * \brief ȫ�ֲ���
 *
 * TODO: long description
 *
 * \note
*/

#ifndef __GlobalData__H__
#define __GlobalData__H__

#include <iostream>
#include "cocos2d.h"

class Monster;

USING_NS_CC;

extern Vector<Monster*> monsterOneList;
extern Vector<Monster*> monsterTwoList;
extern Vector<Monster*> monsterThreeList;
extern Vector<Monster*> monsterFourList;
extern Vector<Monster*> monsterFiveList;
extern Vector<Monster*> monsterShowList;

extern bool m_bFlag1;
extern bool m_bFlag2;
extern bool m_bFlag3;
extern bool m_bFlag4;
extern bool m_bFlag5;
// ����ͼ����
#define MAPMAX 9
// ��ǰѡ��Ĺؿ�
extern int m_iSelectGate;
// ��������
const static int gl_iEnemyType = 1;
// ��������
const static std::string gl_sEnemyName[gl_iEnemyType] = { "muzhuang" };
// �������˶�������
const static std::string gl_sEnemyByHurt[gl_iEnemyType] = { "mzaHurt" };
// ����ս������֡ͼƬ����
const static std::string gl_sEnemyFrameName[gl_iEnemyType] = { "mzStand" };
// ����������������
const static std::string gl_sEnemyDie[gl_iEnemyType] = { "mzDead" };

// �����ƶ���������
const static std::string gl_sEnemyMoveSpriteAnimation[gl_iEnemyType] = { "mzWalk" };
// ���ﶯ��֡ͼƬ��ʱ
const static float gl_fEnemyMoveSpriteAnimationDelay[gl_iEnemyType] = { 0.0625 };
// �����ƶ�����֡ͼƬ����
const static int gl_iEnemyMoveFrameCount[gl_iEnemyType] = { 16 };

// ���﹥��֡ͼƬ����
const static int gl_iEnemyAttackFrameCount[gl_iEnemyType] = { 11 };
// ���﹥��֡ͼƬ֡ͼƬ��ʱ
const static float gl_fEnemyAttackFrameDelay[gl_iEnemyType] = { 0.1 };
// �����Ƿ�������
const static std::string gl_sEnemyBullet[gl_iEnemyType] = { "0" }; //0����û�У�1������
// ����Ĺ�������
const static std::string gl_sEnemyPower[gl_iEnemyType] = { "50" };
// �����Ѫ��
const static std::string gl_sEnemyBlood[gl_iEnemyType] = { "550" };
// ������������ṩ�ľ���
const static std::string gl_sEnemyExp[gl_iEnemyType] = { "200" };

#endif