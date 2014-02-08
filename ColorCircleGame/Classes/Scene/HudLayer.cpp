#include "HudLayer.h"
#include "Define.h"

HudLayer* HudLayer::m_pCurrent = NULL;

HudLayer::HudLayer()
{
	m_pCurrent = this;
}

HudLayer::~HudLayer()
{
}

bool HudLayer::init()
{
	if (!CCLayer::init())
		return false;

	m_score = 0;
	m_pScore = CCLabelTTF::create("0", "Times New Roman", 22);
	m_pScore->setPosition(CCPoint(g_FrameSize.width - 100, g_FrameSize.height - 50));
	addChild(m_pScore);

	return true;
}

void HudLayer::score( int num )
{
	char str[32];
	m_score += num;
	m_pScore->setString(itoa(m_score, str, 10));
}
