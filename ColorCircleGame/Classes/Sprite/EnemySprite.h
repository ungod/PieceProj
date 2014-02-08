#pragma once

#include "cocos2d.h"
#include "Utils/MiscUtils.h"
#include "BaseSprite.h"
#include "Define.h"

USING_NS_CC;

class PlayerSprite;

class EnemySprite : public BaseSprite
{
public:
	EnemySprite();
	~EnemySprite();

	CREATE_FUNC_WITH_PARAM(EnemySprite, EnemyType);

	virtual bool init(EnemyType etype);
	virtual void update(float delta);

	void interact(PlayerSprite* target);

	CC_SYNTHESIZE_READONLY(EnemyType, m_EnemyType, EnemyType);
	CC_SYNTHESIZE_READONLY(PlayerSprite*, m_Target, Target);
	CC_SYNTHESIZE_READONLY(ElementColor, m_ElementColor, ElementColor);
};