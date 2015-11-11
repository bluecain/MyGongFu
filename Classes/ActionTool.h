/*
** 工具类：创建动画
*/

#ifndef __ACTION_TOOL_H__
#define __ACTION_TOOL_H__

#include "cocos2d.h"

USING_NS_CC;

class ActionTool{
public:
	static Animate* animationWithFrameName(const char *frameName, int iloops, float delay);
	static Animate* animationWithFrameAndNum(const char *frameName, int num, float delay);
};

#endif 