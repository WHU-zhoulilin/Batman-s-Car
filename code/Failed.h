#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Failed : public cocos2d::Scene
{
public:
	Failed();
	virtual ~Failed();

	virtual bool init();
	static cocos2d::Scene* createScene();

	void Sure_failed(cocos2d::Ref* pSender);

	CREATE_FUNC(Failed);
};

