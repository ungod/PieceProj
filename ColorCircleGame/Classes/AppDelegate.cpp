#include "AppDelegate.h"
#include "Resource.h"
#include "Scene/GameScene.h"
#include "Define.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	char path[16];
	g_FrameSize = CCSize(960, 640);
	sprintf(path, "%dx%d", (int)g_FrameSize.width, (int)g_FrameSize.height);

	CCFileUtils::sharedFileUtils()->addSearchPath(path);

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pEGLView->setViewName("FuckingGame");
	pEGLView->setFrameSize(g_FrameSize.width, g_FrameSize.height);
    pDirector->setOpenGLView(pEGLView);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	//init all game resource
	initResource();

    // create a scene. it's an autorelease object
    CCScene *pScene = GameScene::create();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
