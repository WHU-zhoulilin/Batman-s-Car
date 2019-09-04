#include "Endless.h"
#include "Failed.h"
#include "stdlib.h"
#include "time.h"
#include <fstream>
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace CocosDenshion;
using namespace std;

//extern carNumber;
extern int score;
extern int MaxScore;
Layer * Endless::createLayer ()
{
	return Endless::create();
}
bool Endless::init()
{
	//±³¾°ÒôÀÖ
	this->scheduleOnce(schedule_selector(Endless::Loading), 0.1f);//Ç°ËÄÃë±³¾°ÒôÀÖ
	this->scheduleOnce(schedule_selector(Endless::BackgroundMusic), 5.0f);//ËÄÃëºó±³¾°ÒôÀÖ

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	player = CCSprite::create("player.png");
	player->setPosition(Vec2(visibleSize.width / 2, 0));
	this->addChild(player, 1);

	this->runAction(Follow::create(player, Rect(-visibleSize.width /4, 0, visibleSize.width *1.5, visibleSize.height)));

	_player1 = CCArray::create();
	_player1->retain();
	this->schedule(schedule_selector(Endless::newplayer), 1, 10000, 0);
	this->schedule(schedule_selector(Endless::road), 1.1, 10000, 0);
	this->schedule(schedule_selector(Endless::gameover), 0.1, 10000, 0);
	auto KeyListener = EventListenerKeyboard::create();
	KeyListener->onKeyPressed = ([=](EventKeyboard::KeyCode keycode, Event* event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			this->schedule(schedule_selector(Endless::updateright), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			this->schedule(schedule_selector(Endless::updateup), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			this->schedule(schedule_selector(Endless::updateleft), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			this->schedule(schedule_selector(Endless::updatedown), 1 / 60, 10000, 0);
			break;
		default:
			break;
		}
	});
	KeyListener->onKeyReleased = ([=](EventKeyboard::KeyCode keycode, Event *event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			this->unschedule(schedule_selector(Endless::updateright));
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			this->unschedule(schedule_selector(Endless::updateup));
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			this->unschedule(schedule_selector(Endless::updateleft));
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			this->unschedule(schedule_selector(Endless::updatedown));
			break;
		}
	});
	_eventDispatcher->addEventListenerWithSceneGraphPriority(KeyListener, this);
	return true;
}
//±³¾°ÒôÀÖ
void Endless::BackgroundMusic(float dt) {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Endless.mp3", true);    //²¥·Å±³¾°ÒôÀÖ
}
void Endless::Loading(float dt) {
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loading.mp3", true);
}

void Endless::road(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto road = CCSprite::create("road_1.png");
	road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(road,0);
	CCMoveBy* move = CCMoveBy::create(1.1, ccp(0, -visibleSize.height * 2 - visibleSize.height / 2));
	auto disppear = CCCallFuncN::create(this, callfuncN_selector(Endless::myDefine));
	auto action = CCSequence::create(move, disppear, NULL);
	road->runAction(action);

}
int i = 0;
void Endless::newplayer(float dt)
{
	i++;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(0));
	int x = rand() % 10;
	auto player1 = Sprite::create("otherplayer.png");
	player1->setPosition(Vec2(visibleSize.width / 10 * x + player1->getContentSize().width,
		visibleSize.height + player1->getContentSize().height));
	this->addChild(player1,1);
	_player1->addObject(player1);

	CCMoveTo * move = CCMoveTo::create(2, Vec2(player1->getContentSize().width + visibleSize.width / 10 * x,
		-200 - i));
	auto disppear = CCCallFuncN::create(this, callfuncN_selector(Endless::myDefine));
	auto action = CCSequence::create(move, disppear, NULL);
	player1->runAction(action);
}

void Endless::gameover(float dt)
{
	CCObject * player1;
	CCARRAY_FOREACH(this->_player1, player1)
	{
		CCSprite * iplayer1 = (CCSprite *)player1;
		if (iplayer1->getBoundingBox().intersectsRect(player->getBoundingBox()))
		{
			if (score > MaxScore)
			{
				MaxScore = score;
				ofstream myOut;
				myOut.open("D:\\MaxScore.txt", ios::out);
				myOut << MaxScore;
			}
			score = 0;
			CCTransitionSplitRows* reScene;
			reScene = CCTransitionSplitRows::create(0.5f, Failed::createScene());
			Director::getInstance()->replaceScene(reScene);
		}
	}
}
void Endless::updateright(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * mover = CCMoveBy::create(0.3, Vec2(visibleSize.width / 80, 0));
	player->runAction(mover);
}
void Endless::updateup(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moveu = CCMoveBy::create(0.3, Vec2(0, visibleSize.width / 80));
	player->runAction(moveu);
}
void Endless::updateleft(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * movel = CCMoveBy::create(0.3, Vec2(-visibleSize.width / 80, 0));
	player->runAction(movel);
}
void Endless::updatedown(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moved = CCMoveBy::create(0.3, Vec2(0, -visibleSize.width / 80));
	player->runAction(moved);
}
void Endless::myDefine(CCNode * who)
{

	who->removeFromParent();
}
Endless::Endless()
{
}


Endless::~Endless()
{
}
