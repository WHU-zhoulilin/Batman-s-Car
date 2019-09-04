#include "SelectorPlayer_1.h"
#include "SelectorPlayer_2.h"
#include "SelectorPlayer_3.h"
#include "option.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "Round.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;

extern int PlayerSelect;

SelectorPlayer_2::SelectorPlayer_2()
{
}

SelectorPlayer_2::~SelectorPlayer_2()
{
}

Scene* SelectorPlayer_2::createScene()
{
	return SelectorPlayer_2::create();
}

bool SelectorPlayer_2::init() {
	if (!Scene::init())
	{
		return false;
	}
	//���csb������
	auto rootNode = CSLoader::getInstance()->createNode("SelectorPlayer_2.csb");
	addChild(rootNode);
	//��ǰ
	Button* button_selector_forward = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button_selector_forward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_2::Selector_1, this));
	//���
	Button* button_selector_backward = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	button_selector_backward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_2::Selector_3, this));
	//ѡ�񲢷���option
	Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	button_back->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_2::back_to_option, this));

	return true;
}
//��ǰ
void SelectorPlayer_2::Selector_1(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_1::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}
//���
void SelectorPlayer_2::Selector_3(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_3::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}

//����option
void SelectorPlayer_2::back_to_option(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	PlayerSelect = 2;

	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");    //���ű�������
}