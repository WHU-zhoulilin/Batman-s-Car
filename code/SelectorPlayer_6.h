#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class SelectorPlayer_6 : public cocos2d::Scene
{
public:
	SelectorPlayer_6();
	virtual ~SelectorPlayer_6();

	virtual bool init();
	static cocos2d::Scene* createScene();
	//��ת����������
	void Selector_5(Ref* pSender, Widget::TouchEventType type);
	//��ת����������
	void Selector_7(Ref* pSender, Widget::TouchEventType type);
	//����option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_6);
};