#include "Complete.h"
#include "Round.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;


Complete::Complete()
{
}

Complete::~Complete()
{
}

Scene* Complete::createScene()
{
	return Complete::create();
}

bool Complete::init() {
	auto rootNode = CSLoader::getInstance()->createNode("complete.csb");
    addChild(rootNode);

	auto Sure_complete = MenuItemImage::create(
		"sure2_normal.png",
		"sure2_pressed.png",
		CC_CALLBACK_1(Complete::Sure_complete, this));
	Sure_complete->setPosition(Vec2(375.89, 243.46));

	auto menu = Menu::create(Sure_complete, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Complete::Sure_complete(Ref* pSender) {
	CCTransitionProgressOutIn* reScene;
	reScene = CCTransitionProgressOutIn::create(0.5f, Round::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundBgm.mp3");
}
