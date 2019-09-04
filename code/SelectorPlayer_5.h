#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class SelectorPlayer_5 : public cocos2d::Scene
{
public:
	SelectorPlayer_5();
	virtual ~SelectorPlayer_5();

	virtual bool init();
	static cocos2d::Scene* createScene();
	//跳转到第四辆车
	void Selector_4(Ref* pSender, Widget::TouchEventType type);

	//跳转到第六辆车
	void Selector_6(Ref* pSender, Widget::TouchEventType type);
	//返回option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_5);
};