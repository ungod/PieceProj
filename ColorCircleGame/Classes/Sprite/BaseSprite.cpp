#include "BaseSprite.h"
#include "Scene/GameLayer.h"
#include "Define.h"
#include "Box2D/Box2D.h"

BaseSprite::BaseSprite()
{
}

BaseSprite::~BaseSprite()
{
}

bool BaseSprite::initWithTexture( CCTexture2D *pTexture )
{
	if (!CCPhysicsSprite::initWithTexture(pTexture))
		return false;

	b2World* world = GameLayer::getCurrent()->getb2World();

	if (!world)
		return false;

	b2BodyDef def;
	def.type = b2_dynamicBody;
	m_pB2Body = world->CreateBody(&def);
	m_fPTMRatio = g_PTMRadio;

	m_pB2Body->SetUserData(this);

	return true;
}

void BaseSprite::destroySprite()
{
	m_pB2Body->GetWorld()->DestroyBody(m_pB2Body);
	m_pB2Body = NULL;

	removeFromParentAndCleanup(true);
}
