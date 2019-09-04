#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class SelectorPlayer_2 : public cocos2d::Scene
{
public:
	SelectorPlayer_2();
	virtual ~SelectorPlayer_2();

	virtual bool init();
	static cocos2d::Scene* createScene();
	//跳转到第一辆车
	void Selector_1(Ref* pSender, Widget::TouchEventType type);

	//跳转到第三辆车
	void Selector_3(Ref* pSender, Widget::TouchEventType type);
	//返回option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_2);
};