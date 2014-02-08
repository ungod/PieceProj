#pragma once 

#include "cocos2d.h"
#include "Utils\MiscUtils.h"

USING_NS_CC;

class HudLayer : public CCLayer
{
public:
	HudLayer();
	~HudLayer();

	CREATE_FUNC(HudLayer);
	DEF_CURRENT(HudLayer);

	void score(int num);

protected:
	virtual bool init();

protected:
	CCLabelTTF* m_pScore;
	int m_score;
};