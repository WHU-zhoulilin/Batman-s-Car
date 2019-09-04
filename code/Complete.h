#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Complete : public cocos2d::Scene
{
public:
	Complete();
	virtual ~Complete();

	virtual bool init();
	static cocos2d::Scene* createScene();

	void Sure_complete(Ref* pSender);

	CREATE_FUNC(Complete);
};

