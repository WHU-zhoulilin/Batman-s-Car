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
	//��ת����������
	void Selector_6(Ref* pSender, Widget::TouchEventType type);
	//��ת���ڰ�����
	void Selector_8(Ref* pSender, Widget::TouchEventType type);
	//����option
	void back_to_option(Ref* pSender, Widget::TouchEventType type);


	CREATE_FUNC(SelectorPlayer_7);
};