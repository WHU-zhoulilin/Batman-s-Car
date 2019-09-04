#include "Start1.h"
#include "SimpleAudioEngine.h"

#include "stdlib.h"
#include "option.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"




USING_NS_CC;

using namespace CocosDenshion;


Start1::Start1()
{
}

Start1::~Start1()
{
}

Scene* Start1::createScene()
{
	return Start1::create();
}

bool Start1::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rootNode = CSLoader::getInstance()->createNode("Start.csb");
	addChild(rootNode);
	//��ť
	/*Button* button = dynamic_cast<Button*>(rootNode->getChildByName("Button_1"));
	button->addTouchEventListener(CC_CALLBACK_2(Start1::begin, this));*/
	//�˵�
	auto begin = MenuItemImage::create(
		"start_normal.png",
		"start_pressed.png",
		CC_CALLBACK_1(Start1::Begin, this));
	begin->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

	auto menu = Menu::create(begin, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	//��������
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("mainbgm.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainbgm.mp3", true);    //���ű�������

	return true;
}


void Start1::Begin(Ref* pSender) {
	//��������ʽ�Ĺ��ɶ����� ��ʱ�뷽��
	CCTransitionSplitRows* reScene;
	reScene = CCTransitionSplitRows::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
}


//void Start1::startgame(Ref* pSender) {
//	Director::getInstance()->replaceScene(HelloWorld::createScene());
//}


//    CCTransitionFadeBL
//    ���ã�����һ���������ɶ����� �����ϵ�����
//    CCTransitionFadeUp
//    ���ã�����һ�����µ��ϣ������۵��Ĺ��ɶ���
//    CCTransitionTurnOffTiles
//    ���ã�����һ�����������ʧ�Ĺ��ɶ���
//    CCTransitionSplitRows
//    ���ã�����һ�����л����л��Ĺ��ɶ���