#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d::ui;

class Round : public cocos2d::Scene
{
public:
	Round();
	virtual ~Round();

	virtual bool init();
	static cocos2d::Scene* createScene();

	//��һ��
	void Round_1(Ref* pSender);
	//�ڶ���
	void Round_2(Ref* pSender);
	//������
	void Round_3(Ref* pSender);
	//�޾�ģʽ
	void Endless(Ref* pSender);
	//����
	void Round_back(Ref* pSender);

	CREATE_FUNC(Round);

};

