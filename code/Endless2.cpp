#include "SimpleAudioEngine.h"
#include "Endless.h"
#include "stdlib.h"
#include "Endless2.h"
#include "Endless.h"
#include <fstream>

USING_NS_CC;
using namespace std;
int score=0;
int MaxScore;
Scene* Scene2::createScene()
{
	return Scene2::create();
}

bool Scene2::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	addChild(Endless::createLayer());
	auto MaxLabel = Label::createWithTTF("MaxScore", "fonts/Marker Felt.ttf", 24);
	MaxLabel->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 10));
	this->addChild(MaxLabel, 1);
	auto YourLabel = Label::createWithTTF("YourScore", "fonts/Marker Felt.ttf", 24);
	YourLabel->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	this->addChild(YourLabel, 1);

	ifstream myIn;
	myIn.open("D:\\MaxScore.txt", ios::in);
	myIn >> MaxScore;

	char MaxScoreName[10] = { 0 };sprintf(MaxScoreName, "%d", MaxScore);
	auto MaxScoreLabel = Label::createWithTTF
	(MaxScoreName, "fonts/Marker Felt.ttf", 24);
	MaxScoreLabel->setPosition(Vec2(visibleSize.width - 20,visibleSize.height - 10));
	this->addChild(MaxScoreLabel, 1);

	this->schedule(schedule_selector(Scene2::scoreup), 1, 100000, 0);

	return true;
}

void Scene2::scoreup(float dt)
{
	score++;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	sprintf(scoreName, "%d", score);
	scoreLabel = Label::createWithTTF(scoreName, "fonts/Marker Felt.ttf", 24);
	scoreLabel->setPosition(Vec2(visibleSize.width - 20, visibleSize.height -100));
	addChild(scoreLabel,1);
	this->scheduleOnce(schedule_selector(Scene2::xiaoshi), 0.9f);
}
void Scene2::xiaoshi(float dt)
{
	scoreLabel->removeFromParent();
}

