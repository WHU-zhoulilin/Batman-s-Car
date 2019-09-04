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
	//���csb������
	auto rootNode = CSLoader::getInstance()->createNode("SelectorPlayer_3.csb");
	addChild(rootNode);
	//��ǰ
	Button* button_selector_forward = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button_selector_forward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::Selector_2, this));
	//���
	Button* button_selector_backward = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	button_selector_backward->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::Selector_4, this));
	//ѡ�񲢷���option
	Button* button_back = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));
	button_back->addTouchEventListener(CC_CALLBACK_2(SelectorPlayer_3::back_to_option, this));

	return true;
}
//��ǰ
void SelectorPlayer_3::Selector_2(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_2::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������

}
//���
void SelectorPlayer_3::Selector_4(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, SelectorPlayer_4::createScene());
	Director::getInstance()->replaceScene(reScene);

	SimpleAudioEngine::sharedEngine()->playEffect("ChangPlayer.mp3");    //���ű�������
}
//����option
void SelectorPlayer_3::back_to_option(Ref* pSender, Widget::TouchEventType type) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	PlayerSelect = 3;

	SimpleAudioEngine::sharedEngine()->playEffect("Selectorplayer.mp3");    //���ű�������
}
