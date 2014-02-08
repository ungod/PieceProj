#pragma once 

#include "cocos2d.h"
#include "Utils/MiscUtils.h"
#include "Sprite/GameBg.h"

USING_NS_CC;

class PlayerSprite;
class b2World;

class GameLayer : public CCLayer
{
public:
	GameLayer();
	~GameLayer();

	CREATE_FUNC(GameLayer);
	DEF_CURRENT(GameLayer);

protected:
	virtual bool init();
	virtual void update(float delta);

	CC_SYNTHESIZE_READONLY(GameBg*, m_pGameBg, GameBg);
	CC_SYNTHESIZE_READONLY(PlayerSprite*, m_pPlayer, PlayerSprite);
	CC_SYNTHESIZE_READONLY(b2World*, m_pWorld, b2World);

private:
	float m_elapse;
};