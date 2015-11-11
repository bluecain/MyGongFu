/*!
 * \file Hero.h
 * \date 2015/05/08 22:13
 *
 * \author SuooL
 * Contact: hu1020935219@gmail.com
 *
 * \brief Ӣ��ʵ����
 *
 * TODO: long description
 *
 * \note
*/
#ifndef __Hero__H__
#define __Hero__H__

#include "cocos2d.h"
USING_NS_CC;

class Hero : public Node
{
public:
	// ����ͼƬ������Ӣ��
	void InitHeroSprite(char *hero_name, int iLevel);
	// ���ص�ǰӢ��
	Sprite* GetSprite();

	// ���ö�����run_directonΪ����������false����,frameNameΪͼƬ֡����
	void SetAnimation(const char *frameName, float delay, bool run_directon);
	// ֹͣ����
	void StopAnimation();
	// ���𶯻�
	void JumpUpAnimation(const char *name_each, float delay, bool run_directon);
	// ���䶯��
	void JumpDownAnimation(const char *name_each, float delay, bool run_directon);
	// ���䶯������
	void JumpEnd();
	// ��������
	void AttackAnimation(const char *name_each, float delay, bool run_directon);
	// ������������
	void AttackEnd();
	// ��������
	void DeadAnimation(const char *name_each, float delay, bool run_directon);
	// ������������
	void DeadEnd();
	// ���˶���
	void HurtByMonsterAnimation(const char *name_each, float delay, bool run_directon);
	// ���˶�������
	void HurtByMonsterEnd();
	// �ж�Ӣ���Ƿ��˶����˴��ڵ��м�λ��,visibleSizeΪ��ǰ���ڵĴ�С  
	bool JudgePosition(Size visibleSize);

	bool IsDead;

	// HP & MP ֵ
	float m_iCurrentHp;
	float m_iTotleHp;
	float m_iCurrentMp;
	float m_iTotleMp;

	float percentage;
	float m_iSpeed;

	bool m_bIsAction;          // �鿴��ǰ�Ƿ��Ѿ��ڴ����
	bool m_bIsJumping;         // �鿴�Ƿ�����
	bool IsRunning;  // �ж��Ƿ����ܶ���
	bool IsAttack;  // �ж��Ƿ��ڹ�������
	
	bool IsHurt; // �ж��Ƿ�����
	
	bool HeroDirecton; // Ӣ���˶��ķ���
	bool m_bCanCrazy; // �ж��Ƿ��ڿ�״̬

	CREATE_FUNC(Hero);
private:
	Sprite* m_HeroSprite; // ����
	char *Hero_name; // ���������ʼ״̬�ľ���ͼƬ����
};
#endif