#pragma once
#ifndef __SCENE_2_H__
#define __SCENE_2_H__

#include "cocos2d.h"

USING_NS_CC;
//using namespace cocostudio::timeline;


class Scene2 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	char scoreName[50] = { 0 };
	cocos2d::Label * scoreLabel;
	void scoreup(float dt	);
	void xiaoshi(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(Scene2);
};
#endif

