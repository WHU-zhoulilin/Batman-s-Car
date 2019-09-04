#include "SelectorPlayer_4.h"
#include "SelectorPlayer_5.h"
#include "SelectorPlayer_6.h"
#include "option.h"

#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "Round.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace CocosDenshion;

extern int PlayerSelect;

SelectorPlayer_5::SelectorPlayer_5()
{
}

SelectorPlayer_5::~SelectorPlayer_5()
{
}

Scene* SelectorPlayer_5::createScene()
{
	return SelectorPlayer_5::create();
}

bool SelectorPlayer_5::init() {
	if (!Scene::init())
	{
		return false;
	}
	//���csb������
	auto rootNode = CSLoader::getInstance()->createNode("SelectorPlayer_5.csb");
	addChild(rootNode);
	//��ǰ
	Button* button_selector_forward = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button_selector_forward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_5::Selector_4, this));
	//���
	Button* button_selector_backward = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	button_selector_backward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_5::Selector_6, this));
	//ѡ�񲢷���option
	Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	button_back->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_5::back_to_option, this));

	return true;
}
//��ǰ
void SelectorPlayer_5::Selector_4(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_4::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}

//���
void SelectorPlayer_5::Selector_6(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_6::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}


//����option
void SelectorPlayer_5::back_to_option(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	PlayerSelect = 5;


	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");    //���ű�������
}
