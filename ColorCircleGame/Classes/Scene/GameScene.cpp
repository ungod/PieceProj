#include "GameScene.h"
#include "GameLayer.h"
#include "HudLayer.h"
#include "DebugLayer.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
	if (!CCScene::init())
		return false;
	
	addChild(GameLayer::create());
	addChild(DebugLayer::create());
	addChild(HudLayer::create());

	return true;
}

