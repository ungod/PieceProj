#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

enum SpriteType
{
	kPlayerSprite = 0,
	kEnemySprite
};

enum ElementColor
{
	kRed = 0,
	kGreen,
	kBlue
};

enum EnemyType
{
	kBrickEnemy = 0,
	kTriangleEnemy
};

extern CCSize g_FrameSize;

extern const int g_PTMRadio;
extern const int g_CircleRadius;

extern const float g_EnemyInterval;
extern const float g_EnemyRefreshInterval;
extern const float g_RedBrickAngularVelocity;

extern const uint16 g_PlayerCategoryBits;
extern const uint16 g_PlayerMaskBits;
extern const uint16 g_EnemyCategoryBits;
extern const uint16 g_EnemyMaskBits;

extern const int g_ScoreStep;
extern const int g_EnemyPosCrack;