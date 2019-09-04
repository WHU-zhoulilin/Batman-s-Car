#include "Start1.h"
#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "option.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"




USING_NS_CC;

using namespace CocosDenshion;


Start1::Start1()
{
}

Start1::~Start1()
{
}

Scene* Start1::createScene()
{
	return Start1::create();
}

bool Start1::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rootNode = CSLoader::getInstance()->createNode("Start.csb");
	addChild(rootNode);
	//按钮
	/*Button* button = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button->addTouchEventListener(CC_CALLBACK_2(Start1::begin, this));*/
	//菜单
	auto begin = MenuItemImage::create(
		"start_normal.png",
		"start_pressed.png",
		CC_CALLBACK_1(Start1::Begin, this));
	begin->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

	auto menu = Menu::create(begin, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	//背景音乐
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("mainbgm.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainbgm.mp3", true);    //播放背景音乐

	return true;
}


void Start1::Begin(Ref* pSender) {
	//扇形条形式的过渡动画， 逆时针方向
	CCTransitionSplitRows* reScene;
	reScene = CCTransitionSplitRows::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
}


//void Start1::startgame(Ref* pSender) {
//	Director::getInstance()->replaceScene(HelloWorld::createScene());
//}


//    CCTransitionFadeBL
//    作用：创建一个部落格过渡动画， 从右上到左下
//    CCTransitionFadeUp
//    作用：创建一个从下到上，条形折叠的过渡动画
//    CCTransitionTurnOffTiles
//    作用：创建一个随机方格消失的过渡动画
//    CCTransitionSplitRows
//    作用：创建一个分行划分切换的过渡动画