#include "Resource.h"

#define  INIT_TEX(va, ch) \
va = ch; \
CCTextureCache::sharedTextureCache()->addImage(va.c_str())

string g_Circle;
string g_RedBrick_1;

string g_GameBg_R;
string g_GameBg_G;
string g_GameBg_B;
string g_GameBg_Default;

void initResource()
{
	INIT_TEX(g_Circle, "qiuti.png");
	INIT_TEX(g_RedBrick_1, "h_3.png");

	INIT_TEX(g_GameBg_R, "ys_dbj_h.png");
	INIT_TEX(g_GameBg_G, "ys_dbj_lv.png");
	INIT_TEX(g_GameBg_B, "ys_dbj_l.png");
	INIT_TEX(g_GameBg_Default, "ys_dbj.png");
}

CCTexture2D* getTextureRes( string name )
{
	return CCTextureCache::sharedTextureCache()->textureForKey(name.c_str());
}