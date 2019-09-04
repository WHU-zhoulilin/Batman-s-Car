#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class SelectorPlayer_7 : public cocos2d::Scene
{
public:
	SelectorPlayer_7();
	virtual ~SelectorPlayer_7();

	virtual bool init();
	static cocos2d::Scene* createScene();
	//跳转到第六辆车
	void Selector_6(Ref* pSender, Widget::TouchEventType type);
	//跳转到第八辆车
	void Selector_8(Ref* pSender, Widget::TouchEventType type);
	//返回option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_7);
};