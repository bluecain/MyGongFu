/*
** 
*/

#include "ActionTool.h"

Animate* ActionTool::animationWithFrameName(const char *frameName, int iloops, float delay)
{
	SpriteFrame* frame = NULL;
	Animation* animation = Animation::create();
	int index = 1;
	// ����֡���� 
	do
	{
		String * name = String::createWithFormat("%s%d.png", frameName, index++);
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name->getCString());
		if (frame == NULL)
		{
			break;
		}
		animation->addSpriteFrame(frame);
	} while (true);
	animation->setDelayPerUnit(delay);  // ÿ֡���ż��
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(iloops);
	// ������������
	Animate* action = Animate::create(animation);
	return action;
}

Animate* ActionTool::animationWithFrameAndNum(const char *frameName, int framecount, float delay)
{
	SpriteFrame* frame = NULL;
	Animation* animation = Animation::create();
	// ����ͼƬ֡
	for (int index = 1; index <= framecount; index++)
	{
		String * name = String::createWithFormat("%s%d.png", frameName, index++);
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name->getCString());
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(delay);
	animation->setRestoreOriginalFrame(true);
	Animate* animate = Animate::create(animation);

	/*
	// �ڶ���ʵ�ַ�ʽ����һ��֡ͼƬ���������飬����Animation
	Vector<SpriteFrame*> animFrames;
	char str[20];
	for (int k = 1; k <= framecount; k++)
	{
	sprintf(str, "%s%d.png", frameName, k);
	SpriteFrame *frame = SpriteFrameCache::getInstance()->spriteFrameByName(str);
	animFrames.pushBack(frame);
	}
	return Animate::create(Animation::createWithSpriteFrames(animFrames, delay));
	*/

	return animate;
}