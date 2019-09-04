#include "Round.h"
#include "Endless2.h"
#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "HelloWorldScene.h"
#include "option.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;

int RoundSelect;//关卡设置

Round::Round()
{
}

Round::~Round()
{
}

Scene* Round::createScene()
{
	return Round::create();
}

bool Round::init() {
	if (!Scene::init())
	{
		return false;
	}

	auto rootNode = CSLoader::getInstance()->createNode("Round3.csb");
	addChild(rootNode);

	//Button* button_1 = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	//button_1->addTouchEventListener(CC_CALLBACK_2(Round::Round_1, this));

	//Button* button_2 = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	//button_2->addTouchEventListener(CC_CALLBACK_2(Round::Round_2, this));

	//Button* button_3 = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	//button_3->addTouchEventListener(CC_CALLBACK_2(Round::Round_3, this));

	//Button* endless = dynamic_cast<Button*>(rootNode->getChildByName("Button_4"));
	//endless->addTouchEventListener(CC_CALLBACK_2(Round::Endless, this));

	//Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_5"));
	//button_back->addTouchEventListener(CC_CALLBACK_2(Round::Round_back, this));

	
	auto Round_1 = MenuItemImage::create(
		"Otisburg_normal.png",
		"Otisburg_pressed.png",
		CC_CALLBACK_1(Round::Round_1, this));
	Round_1->setPosition(Vec2(394.91, 635.30));
	Round_1->setScale(0.2232);

	auto Round_2 = MenuItemImage::create(
		"Oldgotham_normal.png",
		"Oldgotham_pressed.png",
		CC_CALLBACK_1(Round::Round_2, this));
	Round_2->setPosition(Vec2(395.12, 523.41));
	Round_2->setScale(0.2232);

	auto Round_3 = MenuItemImage::create(
		"narrow_normal.png",
		"narrow_pressed.png",
		CC_CALLBACK_1(Round::Round_3, this));
	Round_3->setPosition(Vec2(395.43, 391.81));
	Round_3->setScale(0.2232);

	auto Endless = MenuItemImage::create(
		"endless_normal1.png",
		"endless_pressed1.png",
		CC_CALLBACK_1(Round::Endless, this));
	Endless->setPosition(Vec2(395.43, 277.82));
	Endless->setScale(0.2232);

	auto Round_back = MenuItemImage::create(
		"gcpd_normal.png",
		"gcpd_pressed.png",
		CC_CALLBACK_1(Round::Round_back, this));
	Round_back->setPosition(Vec2(95.37, 460.98));
	Round_back->setScale(0.2168);

	auto menu = Menu::create(Round_1, Round_2, Round_3, Endless, Round_back, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

//第一关
void Round::Round_1(Ref* pSender) {
	RoundSelect = 1;
	CCTransitionProgressInOut* reScene;
	reScene = CCTransitionProgressInOut::create(0.5f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundDone.mp3");
}
//第二关
void Round::Round_2(Ref* pSender) {
	RoundSelect = 2;
	CCTransitionProgressInOut* reScene;
	reScene = CCTransitionProgressInOut::create(0.5f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundDone.mp3");
}
//第三关
void Round::Round_3(Ref* pSender) {
	RoundSelect = 3;
	CCTransitionProgressInOut* reScene;
	reScene = CCTransitionProgressInOut::create(0.5f, HelloWorld::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundDone.mp3");
}
//无尽模式
void Round::Endless(Ref* pSender) {
	CCTransitionProgressInOut* reScene;
	reScene = CCTransitionProgressInOut::create(0.5f, Scene2::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Endless.mp3");
}
//返回
void Round::Round_back(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainbgm.mp3",true);
}