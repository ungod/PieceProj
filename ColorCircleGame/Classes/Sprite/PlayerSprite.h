#pragma once

#include "cocos2d.h"
#include "BaseSprite.h"

USING_NS_CC;

class PlayerSprite : public BaseSprite, public CCTargetedTouchDelegate
{
public:
	PlayerSprite();
	~PlayerSprite();

	CREATE_FUNC(PlayerSprite);

	virtual bool init();
	virtual void update(float delta);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	bool containsTouchLocation(CCTouch* touch);
	void keyBoardHandle();
private:
	bool m_bIsTouch;
};