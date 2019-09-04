#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Help : public cocos2d::Scene
{
public:
	Help();
	virtual ~Help();

	virtual bool init();
	static cocos2d::Scene* createScene();

	void back(cocos2d::Ref* pSender);

	CREATE_FUNC(Help);
};

