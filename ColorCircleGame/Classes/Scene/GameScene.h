#pragma once 

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public CCScene
{
public:
	GameScene();
	~GameScene();

	CREATE_FUNC(GameScene);

protected:
	virtual bool init();

};