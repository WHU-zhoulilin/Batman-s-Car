#include "Failed.h"
#include "Round.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;


using namespace CocosDenshion;

Failed::Failed()
{
}

Failed::~Failed()
{
}

Scene* Failed::createScene()
{
	return Failed::create();
}

bool Failed::init() {
	auto rootNode = CSLoader::getInstance()->createNode("failed.csb");
	addChild(rootNode);

	auto Sure_failed = MenuItemImage::create(
		"sure2_normal.png",
		"sure2_pressed.png",
		CC_CALLBACK_1(Failed::Sure_failed, this));
	Sure_failed->setPosition(Vec2(375.89, 243.46));

	auto menu = Menu::create(Sure_failed, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Failed::Sure_failed(Ref* pSender) {
	CCTransitionProgressOutIn* reScene;
	reScene = CCTransitionProgressOutIn::create(0.5f, Round::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundBgm.mp3");
}
