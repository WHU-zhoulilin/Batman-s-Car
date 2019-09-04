#include "SelectorPlayer_1.h"
#include "SelectorPlayer_7.h"
#include "SelectorPlayer_8.h"
#include "option.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "Round.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;

extern int PlayerSelect;

SelectorPlayer_8::SelectorPlayer_8()
{
}

SelectorPlayer_8::~SelectorPlayer_8()
{
}

Scene* SelectorPlayer_8::createScene()
{
	return SelectorPlayer_8::create();
}

bool SelectorPlayer_8::init() {
	if (!Scene::init())
	{
		return false;
	}
	//���csb������
	auto rootNode = CSLoader::getInstance()->createNode("SelectorPlayer_8.csb");
	addChild(rootNode);
	//��ǰ
	Button* button_selector_forward = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button_selector_forward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_8::Selector_7, this));
	//���
	Button* button_selector_backward = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	button_selector_backward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_8::Selector_1, this));
	//ѡ�񲢷���option
	Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	button_back->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_8::back_to_option, this));

	return true;
}
//��ǰ
void SelectorPlayer_8::Selector_7(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_7::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}
//���
void SelectorPlayer_8::Selector_1(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_1::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}

//����option
void SelectorPlayer_8::back_to_option(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	PlayerSelect = 8;

	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");    //���ű�������
}
