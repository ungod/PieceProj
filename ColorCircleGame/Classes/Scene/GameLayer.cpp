#include "GameLayer.h"
#include "AppDelegate.h"
#include "Define.h"
#include "Sprite/PlayerSprite.h"
#include "Sprite/GameBg.h"
#include "Box2D/Box2D.h"
#include "Sprite/EnemySprite.h"

GameLayer* GameLayer::m_pCurrent = NULL;

GameLayer::GameLayer()
{
	m_pCurrent = this;
}

GameLayer::~GameLayer()
{
}

bool GameLayer::init()
{
	if (!CCLayer::init())
		return false;

	scheduleUpdate();

	m_pWorld = new b2World(b2Vec2(0, 0));

	m_pGameBg = GameBg::create();
	addChild(m_pGameBg);

	m_pPlayer = PlayerSprite::create();
	m_pPlayer->setPosition(CCPoint(g_FrameSize.width/2, g_FrameSize.height/2));
	addChild(m_pPlayer);

	m_elapse = 0;
	srand((unsigned int)time(NULL));

	return true;
}

void GameLayer::update( float delta )
{
	if (m_pWorld)
	{
		m_pWorld->Step(delta, 8, 1);
	}

	m_elapse += delta;

	if (m_elapse >= g_EnemyRefreshInterval)
	{
		m_elapse = 0;

		EnemySprite* ep = EnemySprite::create(kBrickEnemy);

		int boxPosXOrY, boxSign, boxPos;
		boxPosXOrY = rand()%2;
		boxSign = rand()%2;
		boxPos = !boxPosXOrY ? (rand()%(int)g_FrameSize.width) : (rand()%(int)g_FrameSize.height);

		CCPoint pos;
		if (boxPosXOrY)//Y
		{
			pos.x = boxSign ? -g_EnemyPosCrack : g_FrameSize.width + g_EnemyPosCrack;
			pos.y = boxPos;
		}
		else//X
		{
			pos.x = boxPos;
			pos.y = boxSign ? -g_EnemyPosCrack : g_FrameSize.height + g_EnemyPosCrack;
		}

		ep->setPosition(pos);
		ep->interact(m_pPlayer);
		addChild(ep);
	}
}