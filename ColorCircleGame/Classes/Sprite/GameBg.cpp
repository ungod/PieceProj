#include "GameBg.h"
#include "Resource.h"

GameBg::GameBg()
{
}

GameBg::~GameBg()
{
}

bool GameBg::init()
{
	if (!CCSprite::initWithTexture(getTextureRes(g_GameBg_B)))
		return false;

	setAnchorPoint(CCPoint(0, 0));

	return true;
}

void GameBg::changeBgColor( ElementColor color )
{
	switch (color)
	{
	case kRed:
		setTexture(getTextureRes(g_GameBg_R));
		break;
	case kGreen:
		setTexture(getTextureRes(g_GameBg_G));
		break;
	case kBlue:
		setTexture(getTextureRes(g_GameBg_B));
		break;
	default:
		break;
	}
}
