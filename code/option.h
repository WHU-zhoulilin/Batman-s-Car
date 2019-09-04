#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class option : public cocos2d::Scene
{
public:
	option();
	virtual ~option();

	virtual bool init();
	static cocos2d::Scene* createScene();

	void help(cocos2d::Ref* pSender);

	void Volume(cocos2d::Ref* pSender);

	void ChuJi(cocos2d::Ref* pSender);
	//选择第一辆车
	void Selector_1(cocos2d::Ref* pSender);

	CREATE_FUNC(option);
};
