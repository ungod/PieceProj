#include "DebugLayer.h"
#include "GameLayer.h"
#include "Define.h"
#include "Utils\GLES-Render.h"

DebugLayer::DebugLayer()
{
	m_pWorld = NULL;
	m_pDebugDraw = NULL;
}

DebugLayer::~DebugLayer()
{
}

void DebugLayer::initPhysicDebug()
{
	if (!GameLayer::getCurrent())
		return;

	m_pWorld = GameLayer::getCurrent()->getb2World();

	if (!m_pWorld)
		return;

	m_pDebugDraw = new GLESDebugDraw( g_PTMRadio );
	m_pWorld->SetDebugDraw(m_pDebugDraw);

	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	m_pDebugDraw->SetFlags(flags);
}


bool DebugLayer::init()
{
	if (!CCLayer::init())
		return false;

	initPhysicDebug();

	return true;
}

void DebugLayer::draw()
{
	CCLayer::draw();

	if (m_pWorld)
	{
		ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
		kmGLPushMatrix();
		m_pWorld->DrawDebugData();
		kmGLPopMatrix();
	}
}