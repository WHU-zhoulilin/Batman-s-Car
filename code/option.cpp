#include "option.h"
#include "SelectorPlayer_1.h"
#include "Volume.h"
#include "Help.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "Round.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

int PlayerSelect = 1;

using namespace CocosDenshion;

option::option()
{
}


option::~option()
{
}


Scene* option::createScene()
{
	return option::create();
}

bool option::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rootNode = CSLoader::getInstance()->createNode("Option2.csb");
	addChild(rootNode);

	//³µ¿â
	//Button* Selector_1 = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	//Selector_1->addTouchEventListener(CC_CALLBACK_2(option::Selector_1, this));

	auto Selector_1 = MenuItemImage::create(
		"select_normal1.png",
		"select_pressed1.png",
		CC_CALLBACK_1(option::Selector_1, this));
	Selector_1->setPosition(Vec2(146,69));
	Selector_1->setScale(0.5941);


	//ÉèÖÃ
	auto Volume = MenuItemImage::create(
		"setting_normal1.png",
		"setting_pressed1.png",
		CC_CALLBACK_1(option::Volume, this));
	Volume->setPosition(Vec2(146.76, 192.96));
	Volume->setScale(0.5941);
	//°ïÖú
	auto help = MenuItemImage::create(
		"help_normal.png",
		"help_pressed.png",
		CC_CALLBACK_1(option::help, this));
	help->setPosition(Vec2(499.78, 193.6));
	help->setScale(0.5899);
	//³ö»÷
	//Button* ChuJi_Round = dynamic_cast<Button*>(rootNode->getChildByName("Button_6"));
	//ChuJi_Round->addTouchEventListener(CC_CALLBACK_2(option::ChuJi, this));
	auto ChuJi = MenuItemImage::create(
		"go_normal1.png",
		"go_pressed2.png",
		CC_CALLBACK_1(option::ChuJi, this));
	ChuJi->setPosition(Vec2(505.66,68.58));
	ChuJi->setScale(0.5940);


	auto menu = Menu::create(Selector_1, ChuJi, Volume , help, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}
//³µ¿â
void option::Selector_1(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_1::createScene());
	Director::getInstance()->replaceScene(reScene);
	//±³¾°ÒôÀÖ
	//²¥·Å±³¾°ÒôÀÖ
	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");
}
//ÉèÖÃ
void option::Volume(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, Volume::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
}
//°ïÖú
void option::help(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, Help::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
}
//³ö»÷
void option::ChuJi(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, Round::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("SelectRoundBgm.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundBgm.mp3"); 
}


