#pragma once

#include <string>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

void initResource();
CCTexture2D* getTextureRes(string name);

extern string g_Circle;
extern string g_RedBrick_1;

extern string g_GameBg_R;
extern string g_GameBg_B;
extern string g_GameBg_G;
extern string g_GameBg_Default;
