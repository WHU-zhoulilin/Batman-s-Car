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
	//��ת����һ����
	void Selector_1(Ref* pSender, Widget::TouchEventType type);

	//��ת����������
	void Selector_3(Ref* pSender, Widget::TouchEventType type);
	//����option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_2);
};