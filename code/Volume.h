#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Volume : public cocos2d::Scene
{
public:
	Volume();
	virtual ~Volume();

	virtual bool init();
	static cocos2d::Scene* createScene();
	
	void back(cocos2d::Ref* pSender);

	CREATE_FUNC(Volume);
};

