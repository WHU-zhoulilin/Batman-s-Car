#pragma once
#include "cocos2d.h"
class Endless :public cocos2d::CCLayer
{
public:
	//背景音乐
	void BackgroundMusic(float dt);
	void Loading(float dt);

	cocos2d::CCSprite * player;
	cocos2d::CCArray * _player1;//敌方小车数组
	cocos2d::Label * scoreLabel;
	void gameover(float dt);
	static cocos2d::Layer * createLayer();

	void myDefine(cocos2d::CCNode * who);
	virtual bool init();
	void road(float dt);
	void newplayer(float dt);
	void updateright(float dt);
	void updateup(float dt);
	void updateleft(float dt);
	void updatedown(float dt);


	Endless();
	virtual ~Endless();
	CREATE_FUNC(Endless);
};

