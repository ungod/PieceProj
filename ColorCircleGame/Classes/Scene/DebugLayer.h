#pragma once 

#include "cocos2d.h"

class GLESDebugDraw;
class b2World;

USING_NS_CC;

class DebugLayer : public CCLayer
{
public:
	DebugLayer();
	~DebugLayer();

	CREATE_FUNC(DebugLayer);

protected:
	virtual bool init();
	virtual void draw();

	void initPhysicDebug();

private:
	GLESDebugDraw* m_pDebugDraw;
	b2World*	m_pWorld;
};