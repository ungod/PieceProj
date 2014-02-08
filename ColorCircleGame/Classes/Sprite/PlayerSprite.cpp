#include "PlayerSprite.h"
#include "Resource.h"
#include "Box2D/Box2D.h"
#include "AppDelegate.h"
#include "Define.h"
#include "Scene/GameLayer.h"
#include "EnemySprite.h"
#include "Scene/HudLayer.h"

# define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 1 : 0 )
# define KEY_UP(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 0 : 1 )

PlayerSprite::PlayerSprite()
{
	m_bIsTouch = false;
}

PlayerSprite::~PlayerSprite()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool PlayerSprite::init()
{
	if (!BaseSprite::initWithTexture(getTextureRes(g_Circle)))
		return false;

	setTag(kPlayerSprite);

	b2CircleShape circle;
	circle.m_radius = (float)g_CircleRadius/g_PTMRadio;

	b2Filter filter;
	filter.categoryBits = g_PlayerCategoryBits;
	filter.maskBits = g_PlayerMaskBits;

	b2FixtureDef fix;
	fix.shape = &circle;
	fix.density = 1.0f;
	fix.friction = 0.3f;
	fix.filter = filter;

	m_pB2Body->CreateFixture(&fix);

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

	scheduleUpdate();

	return true;
}

bool PlayerSprite::containsTouchLocation(CCTouch* touch)
{
	CCSize size = getContentSize();
	CCRect rect = CCRect(-size.width/2, -size.height/2, size.width, size.height);

	return rect.containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool PlayerSprite::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	if (m_bIsTouch) return false;
	if (!containsTouchLocation(pTouch)) return false;

	m_bIsTouch = true;

	return true;
}

void PlayerSprite::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{
	if (!m_bIsTouch) return;

	CCNode* parent = getParent();
	if (parent)
	{
		setPosition(parent->convertTouchToNodeSpace(pTouch));
	}
}

void PlayerSprite::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{
	m_bIsTouch = false;
}

void PlayerSprite::update( float delta )
{
	b2ContactEdge* ce = m_pB2Body->GetContactList();
	list<BaseSprite*> desList;

	while (ce)
	{
		b2Body* body = ce->contact->GetFixtureA()->GetBody();
		BaseSprite* sprite = (BaseSprite*)body->GetUserData();

		if (sprite->getTag() == kEnemySprite)
		{
			desList.push_back(sprite);
		}
		ce = ce->next;
	}

	for (list<BaseSprite*>::iterator it = desList.begin(); it != desList.end(); it++)
	{
		CCPoint dir = (*it)->getPosition() - getPosition();
		dir = dir.normalize();

		float sita = CC_RADIANS_TO_DEGREES(acos(dir.dot(CCPoint(0, 1))));
		ElementColor hitColor;

		//cos值域在(0,180)，修正在(180,360)的情况
		if (dir.x < 0)
		{
			sita = 360 - sita;
		}
		sita += getRotation();

		while (sita < 0) 
		{
			sita += 360;
		}
		sita = (int)sita % 360;

		if (sita >=0 && sita < 120)
		{
			hitColor = kGreen;
		}
		else if (sita >= 120 && sita < 240)
		{
			hitColor = kRed;
		}
		else
		{
			hitColor = kBlue;
		}

		EnemySprite* esp = dynamic_cast<EnemySprite*>(*it);
		if (!esp) continue;

		if (hitColor == esp->getElementColor())
		{
			HudLayer::getCurrent()->score(g_ScoreStep);
		}

		GameLayer::getCurrent()->getGameBg()->changeBgColor(esp->getElementColor());

		(*it)->destroySprite();
	}
	desList.clear();

	keyBoardHandle();
}

void PlayerSprite::keyBoardHandle()
{
	if (KEY_DOWN('A'))
	{
		setRotation(getRotation()+5);
	}
	else if(KEY_DOWN('D'))
	{
		setRotation(getRotation()-5);
	}
}
