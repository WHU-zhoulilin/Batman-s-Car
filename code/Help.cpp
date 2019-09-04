#include "Help.h"
#include "Volume.h"
#include "option.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "stdlib.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace cocos2d::ui;


Help::Help()
{
}


Help::~Help()
{
}

Scene* Help::createScene()
{
	return Help::create();
}

bool Help::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto rootNode = CSLoader::getInstance()->createNode("Help.csb");
	addChild(rootNode);

	//·µ»Ø°´Å¥
	auto back = MenuItemImage::create(
		"back_normal_help.png",
		"back_pressed_help.png",
		CC_CALLBACK_1(Help::back, this));
	back->setPosition(Vec2(320, 81.14));
	back->setScale(0.2693);

	auto menu = Menu::create(back, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Help::back(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundDone.mp3");
}