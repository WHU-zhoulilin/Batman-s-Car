#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Start1 : public cocos2d::Scene
{
public:
	Start1();
	virtual ~Start1();

	virtual bool init();

	//设置道路定义
	Sprite* pRoad1;
	Sprite* pRoad2;

	static cocos2d::Scene* createScene();
	

	void Begin(Ref* pSender);

	CREATE_FUNC(Start1);

};