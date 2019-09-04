#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Round : public cocos2d::Scene
{
public:
	Round();
	virtual ~Round();

	virtual bool init();
	static cocos2d::Scene* createScene();

	//第一关
	void Round_1(Ref* pSender);
	//第二关
	void Round_2(Ref* pSender);
	//第三关
	void Round_3(Ref* pSender);
	//无尽模式
	void Endless(Ref* pSender);
	//返回
	void Round_back(Ref* pSender);

	CREATE_FUNC(Round);

};

