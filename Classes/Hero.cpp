/*!
 * \class Hero
 *
 * \ingroup GroupName
 *
 * \brief Ӣ��ʵ����
 *
 * TODO: long description
 *
 * \note 
 *
 * \author SuooL
 *
 * \version 1.0
 *
 * \date ���� 2015
 *
 * Contact: hu1020935219@gmail.com
 *
 */

#include "Hero.h"
#include "ActionTool.h"

USING_NS_CC;

// �����Է���
void Hero::InitHeroSprite(char *hero_name, int m_iLevel)
{
	// ���Գ�ʼ��
	m_HeroSprite = NULL;
	m_bCanCrazy = false;   
	m_bIsAction = false;
	m_bIsJumping = false;
	HeroDirecton = false;    	// �����˶�
	Hero_name = NULL;
	IsRunning = false;
	IsAttack = false;
	IsHurt = false;
	IsDead = false;
	m_iCurrentMp = 0.0f;
	m_iTotleMp = 100.0f;
	m_iSpeed = 5;
	Hero_name = hero_name;
	m_iCurrentHp = m_iTotleHp = 300.0f*m_iLevel;
	percentage = 100.0f;

	this->m_HeroSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(hero_name));
	this->addChild(m_HeroSprite);
}

Sprite* Hero::GetSprite()
{
	return m_HeroSprite;
}

// ��������
// ���ö���
void Hero::SetAnimation(const char *frameName, float delay, bool run_directon)
{
	// ��������
	if (HeroDirecton != run_directon)
	{
		HeroDirecton = run_directon;
		m_HeroSprite->setFlippedX(run_directon);
	}
	if (IsRunning || IsHurt || IsAttack)
		return;

	/* ������������ */
	Animate* action = ActionTool::animationWithFrameName(frameName, -1, delay);
	m_HeroSprite->runAction(action);
	IsRunning = true;
}

// ֹͣ����
void Hero::StopAnimation()
{
	if (!IsRunning)
		return;
	m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���

	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_HeroSprite, true);//��ԭ���ľ���ɾ����
	this->m_HeroSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(Hero_name));//�ָ�����ԭ������ͼ����
	m_HeroSprite->setFlippedX(HeroDirecton);
	this->addChild(m_HeroSprite);
	IsRunning = false;
}

// ����
void Hero::JumpUpAnimation(const char *name_each, float delay, bool run_directon)
{
	// ��������
	if (HeroDirecton != run_directon)
	{
		HeroDirecton = run_directon;
		m_HeroSprite->setFlippedX(run_directon);
	}
	if (IsHurt || IsAttack || IsDead)
		return;

	// ������������ 
	Animate* action = ActionTool::animationWithFrameName(name_each, -1, delay);
	m_HeroSprite->runAction(action);
	m_bIsJumping = true;
}

// ����
void Hero::JumpDownAnimation(const char *name_each, float delay, bool run_directon)
{
	// ��������
	if (HeroDirecton != run_directon)
	{
		HeroDirecton = run_directon;
		m_HeroSprite->setFlippedX(run_directon);
	}
	if (IsHurt || IsAttack)
		return;

	/* ������������ */
	Animate* action = ActionTool::animationWithFrameName(name_each, -1, delay);
	m_HeroSprite->runAction(action);
	m_bIsJumping = true;
}

// ����
void Hero::JumpEnd()
{
	m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���

	// �ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_HeroSprite, true);//��ԭ���ľ���ɾ����
	this->m_HeroSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(Hero_name));//�ָ�����ԭ������ͼ����
	m_HeroSprite->setFlippedX(HeroDirecton);
	this->addChild(m_HeroSprite);
	m_bIsJumping = false;
}

// ����
void Hero::AttackAnimation(const char *name_each, float delay, bool run_directon)
{
	// ��������
	if (HeroDirecton != run_directon)
	{
		HeroDirecton = run_directon;
		m_HeroSprite->setFlippedX(run_directon);
	}
	if (IsAttack || m_bIsJumping)
		return;
	// ��������
	Animate* act = ActionTool::animationWithFrameName(name_each, 1, delay);
	// �����ص��������������������AttackEnd()
	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Hero::AttackEnd));
	// ������������
	ActionInterval* attackact = Sequence::create(act, callFunc, NULL);
	IsAttack = true;
	m_HeroSprite->runAction(attackact);
}

// ��������
void Hero::AttackEnd()
{
	m_HeroSprite->setFlippedX(HeroDirecton);
	IsAttack = false;
	if (m_bCanCrazy == true)
	{
		m_bCanCrazy = false;
		m_iCurrentMp = 0;
	}
}

// ����
void Hero::HurtByMonsterAnimation(const char *name_each, float delay, bool run_directon)
{
	if (IsHurt || IsDead)
		return;
	//��������
	if (IsRunning || IsAttack)
	{
		m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���
		//�ָ�����ԭ���ĳ�ʼ����ͼ 
		this->removeChild(m_HeroSprite, true);//��ԭ���ľ���ɾ����
		m_HeroSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(Hero_name));//�ָ�����ԭ������ͼ����
		m_HeroSprite->setFlippedX(HeroDirecton);
		this->addChild(m_HeroSprite);
		IsRunning = false;
		IsAttack = false;
	}

	Animate* action = ActionTool::animationWithFrameName(name_each, 1, delay);
	//�����ص����������˶�����������HurtEnd()
	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Hero::HurtByMonsterEnd));
	//������������
	ActionInterval* hurtackact = Sequence::create(action, callFunc, NULL);

	m_HeroSprite->runAction(hurtackact);
	IsHurt = true;


}

// ���˽���
void Hero::HurtByMonsterEnd()
{
	m_iCurrentHp -= 20.0f;
	IsHurt = false;
	percentage = m_iCurrentHp / m_iTotleHp * 100.0f;
	if (m_iCurrentHp < 0.0f)
	{
		DeadAnimation("dead", 0, HeroDirecton);
	}
}

// ����
void Hero::DeadAnimation(const char *name_each, float delay, bool run_directon)
{
	m_HeroSprite->stopAllActions();
	// ��������
	if (HeroDirecton != run_directon)
	{
		HeroDirecton = run_directon;
		m_HeroSprite->setFlippedX(run_directon);
	}
	// ��������
	Animate* act = ActionTool::animationWithFrameName(name_each, 1, delay);
	//�����ص��������������������AttackEnd()
	CallFunc* callFunc = CallFunc::create(this, callfunc_selector(Hero::DeadEnd));
	//������������
	ActionInterval* attackact = Sequence::create(act, callFunc, NULL);
	m_HeroSprite->runAction(attackact);
	Director::getInstance()->getScheduler()->setTimeScale(0.5);
}

// ��������
void Hero::DeadEnd()
{
	IsDead = true;
	//�ָ�����������
	this->removeChild(m_HeroSprite, true);  //��ԭ���ľ���ɾ����
	m_HeroSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("monsterDie6.png")); //�ָ�����������
	m_HeroSprite->setFlippedX(HeroDirecton);
	this->addChild(m_HeroSprite);

}

// �ж�λ��
bool Hero::JudgePosition(Size visibleSize)
{
	if (this->getPositionX() > (visibleSize.width / 2.0 + 2.0) || (this->getPositionX() < visibleSize.width / 2.0 - 2.0)) // ���鵽��mid?
		return false;
	else
		return true;//�����м�λ��
}
