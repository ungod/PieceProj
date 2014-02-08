#include "EnemySprite.h"
#include "Box2D/Box2D.h"
#include "Resource.h"
#include "PlayerSprite.h"
#include "Define.h"

EnemySprite::EnemySprite()
{
	m_EnemyType = kBrickEnemy;
	m_Target = NULL;
	m_ElementColor = kRed;
}

EnemySprite::~EnemySprite()
{
}

bool EnemySprite::init( EnemyType etype )
{
	setTag(kEnemySprite);

	m_EnemyType = etype;
	switch (m_EnemyType)
	{
	case kBrickEnemy:
		{
			if (!initWithTexture(getTextureRes(g_RedBrick_1)))
				return false;

			int ty = rand()%3;
			m_ElementColor = (ElementColor)ty;

			ccColor3B c;
			if (m_ElementColor == kRed)
				c = ccRED;
			else if (m_ElementColor == kGreen)
				c = ccGREEN;
			else
				c = ccBLUE;

			setColor(c);

			CCSize size = getContentSize();

			b2PolygonShape shape;
			shape.SetAsBox(size.width/2/g_PTMRadio, size.height/2/g_PTMRadio);

			b2Filter filter;
			filter.categoryBits = g_EnemyCategoryBits;
			filter.maskBits = g_EnemyMaskBits;

			b2FixtureDef fix;
			fix.shape = &shape;
			fix.friction = 0.5f;
			fix.density = 1.0f;
			fix.filter = filter;

			m_pB2Body->CreateFixture(&fix);
		}
		break;
	case kTriangleEnemy:
		break;
	default:
		break;
	}
	scheduleUpdate();
	return true;
}

void EnemySprite::interact( PlayerSprite* target )
{
	m_Target = target;

	if (!m_Target) return;

	switch (m_EnemyType)
	{
	case kBrickEnemy:
		{
			CCPoint vec = m_Target->getPosition() - getPosition();
			b2Vec2 impulse(vec.x/g_PTMRadio, vec.y/g_PTMRadio);

			m_pB2Body->SetLinearVelocity(impulse);
			m_pB2Body->SetAngularVelocity(g_RedBrickAngularVelocity);
		}
		break;
	case kTriangleEnemy:
		break;
	default:
		break;
	}
}

void EnemySprite::update( float delta )
{
	CCRect rect = CCRect(-g_EnemyPosCrack, -g_EnemyPosCrack, g_FrameSize.width+g_EnemyPosCrack*2, g_FrameSize.height+g_EnemyPosCrack*2);

	if (!rect.containsPoint(getPosition()))
	{
		unscheduleUpdate();
		destroySprite();
	}
}
