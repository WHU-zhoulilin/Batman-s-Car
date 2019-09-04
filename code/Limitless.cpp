#include "Limitless.h"
#include "SimpleAudioEngine.h"
#include "stdlib.h"

#include"time.h"
#include "Failed.h"
#include "Complete.h"

USING_NS_CC;

using namespace CocosDenshion;


Limitless::Limitless()
{
}

Limitless::~Limitless()
{
}

Scene* Limitless::createScene()
{
	return Limitless::create();
}

bool Limitless::init() {



	return true;
}
bool Endless::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	player = CCSprite::create("bat1.png");
	player->setPosition(Vec2(visibleSize.width / 2, 0));
	this->addChild(player, 1);

	this->runAction(Follow::create(player, Rect(-visibleSize.width / 4, 0, visibleSize.width *1.5, visibleSize.height)));

	_player1 = CCArray::create();
	_player1->retain();
	this->schedule(schedule_selector(Endless::newplayer), 1, 10000, 0);
	this->schedule(schedule_selector(Endless::road), 1, 10000, 0);
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

void Endless::road(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto road = CCSprite::create("road2.png");
	road->setAnchorPoint(Vec2(0, 0));
	road->setPosition(Vec2(0, 0));
	this->addChild(road, 0);
	CCMoveBy * move = CCMoveBy::create(11, Vec2(0, -12602));
	auto disppear = CCCallFuncN::create(this, callfuncN_selector(Endless::myDefine));
	auto action = CCSequence::create(move, disppear, NULL);
	road->runAction(action);

}
void Endless::newplayer(float dt)
{
	score++;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(0));
	int x = rand() % 10;
	auto player1 = Sprite::create("player1.jpg");
	player1->setPosition(Vec2(visibleSize.width / 10 * x + player1->getContentSize().width,
		visibleSize.height + player1->getContentSize().height));
	this->addChild(player1, 1);
	_player1->addObject(player1);

	CCMoveTo * move = CCMoveTo::create(2, Vec2(player1->getContentSize().width + visibleSize.width / 10 * x,
		-200 - score));
	auto disppear = CCCallFuncN::create(this, callfuncN_selector(Endless::myDefine));
	auto action = CCSequence::create(move, disppear, NULL);
	player1->runAction(action);
	sprintf(scoreName, "%d", score);
	scoreLabel = Label::createWithTTF(scoreName, "fonts/Marker Felt.ttf", 24);
	scoreLabel->setPosition(Vec2(visibleSize.width - 20, visibleSize.height - 10));
	this->addChild(scoreLabel);
	this->scheduleOnce(schedule_selector(Endless::xiaoshi), 0.95f);
}
void Endless::xiaoshi(float dt)
{
	scoreLabel->removeFromParent();
}
void Endless::gameover(float dt)
{
	CCObject * player1;
	CCARRAY_FOREACH(this->_player1, player1)
	{
		CCSprite * iplayer1 = (CCSprite *)player1;
		if (iplayer1->getBoundingBox().intersectsRect(player->getBoundingBox()))
		{
			Director::getInstance()->end();
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