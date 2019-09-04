#include "SelectorPlayer_2.h"
#include "SelectorPlayer_3.h"
#include "SelectorPlayer_4.h"
#include "option.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "Round.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;

extern int PlayerSelect;

SelectorPlayer_3::SelectorPlayer_3()
{
}

SelectorPlayer_3::~SelectorPlayer_3()
{
}

Scene* SelectorPlayer_3::createScene()
{
	return SelectorPlayer_3::create();
}

bool SelectorPlayer_3::init() {
	if (!Scene::init())
	{
		return false;
	}
	//添加csb到界面
	auto rootNode = CSLoader::getInstance()->createNode("SelectorPlayer_3.csb");
	addChild(rootNode);
	//向前
	Button* button_selector_forward = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button_selector_forward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::Selector_2, this));
	//向后
	Button* button_selector_backward = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	button_selector_backward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::Selector_4, this));
	//选择并返回option
	Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	button_back->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::back_to_option, this));

	return true;
}
//向前
void SelectorPlayer_3::Selector_2(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_2::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //播放背景音乐

}
//向后
void SelectorPlayer_3::Selector_4(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_4::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //播放背景音乐
}
//返回option
void SelectorPlayer_3::back_to_option(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	PlayerSelect = 3;

	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");    //播放背景音乐
}
