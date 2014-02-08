#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Define.h"

USING_NS_CC;
USING_NS_CC_EXT;

class GameBg : public CCSprite
{
public:
	GameBg();
	~GameBg();

	CREATE_FUNC(GameBg);

	void changeBgColor(ElementColor color);

protected:
	virtual bool init();
};