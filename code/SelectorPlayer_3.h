#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class SelectorPlayer_3 : public cocos2d::Scene
{
public:
	SelectorPlayer_3();
	virtual ~SelectorPlayer_3();

	virtual bool init();
	static cocos2d::Scene* createScene();

	//��ת���ڶ�����
	void Selector_2(Ref* pSender, Widget::TouchEventType type);
	//��ת����������
	void Selector_4(Ref* pSender, Widget::TouchEventType type);
	//����option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);

	CREATE_FUNC(SelectorPlayer_3);
};