#include "cocos2d.h"


class Limitless : public cocos2d::Scene
{
public:
	Limitless();
	virtual ~Limitless();

	virtual bool init();
	static cocos2d::Scene* createScene();
	

	CREATE_FUNC(Limitless);
};

