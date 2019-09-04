#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "stdlib.h"

#include"time.h"
#include "Failed.h"
#include "Complete.h"

USING_NS_CC;

using namespace CocosDenshion;
static int counter = 3;
static int PlayerLayer = 4;

static int TotalCarsFast = 20;
static int TotalCarsSlow = 16;
static int TotalCarsPlus = 18;
static int TotalCarsPlus2 = 24;
static int IntervalFast = 2.5;
static int IntervalSlow = 3;
static int IntervalPlus = 2.3;
static int IntervalPlus2 = 2.1;
//�����ֺͻ�����Ч
static int Protected = 1;
static int FirePlayer = 1;
//ģʽ������ѡ��
extern int RoundSelect;
extern int PlayerSelect;
//�ܳ�����ʤ���жϣ�
static int Number = 65;
//����
static int test = 1.1;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}
	//��ȡģ������С
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//С��������(ѡ����)
	/*if (PlayerSelect == 1) {
		player = Sprite::create("Player_1.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 2) {
		player = Sprite::create("Player_2.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 3) {
		player = Sprite::create("Player_3.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 4) {
		player = Sprite::create("Player_4.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 5) {
		player = Sprite::create("Player_5.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 6) {
		player = Sprite::create("Player_6.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 7) {
		player = Sprite::create("Player_7.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 8) {
		player = Sprite::create("Player_8.png");
		player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
		this->addChild(player, 2);
	}*/
	char CarNumber[30] = { 0 };
	sprintf(CarNumber, "Player_%d.png", PlayerSelect);
	player->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 6));
	this->addChild(player, 2);


	//������ɫ

	//�����ƶ�

	this->runAction(Follow::create(player, 
	Rect(-visibleSize.width / 4, 0,
	visibleSize.width * 1.5, visibleSize.height)));

	//����ʱ
	this->schedule(schedule_selector(HelloWorld::time), 1, 5, 4);//����һ��ÿ1sִ��һ�εļ�ʱ��

	//��������
	this->scheduleOnce(schedule_selector(HelloWorld::Loading), 0.1f);//ǰ���뱳������
	this->scheduleOnce(schedule_selector(HelloWorld::BackgroundMusic), 5.0f);//����󱳾�����


	//����ͼƬ(��·����)
    this->schedule(schedule_selector(HelloWorld::roadmove), test, 200, 5);//��·�ƶ���ʱ��

	//�ȴ�����ͼƬ
	this->scheduleOnce(schedule_selector(HelloWorld::RemoveLoadingback), 4);
	loadingbackground = CCSprite::create("LoadingBackground.png");
	loadingbackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(loadingbackground, 3);

	//�ȴ�ͼ��(gif)
	auto loading = Sprite::create("0.png");//��������
	loading->setPosition(Vec2(visibleSize.width - visibleSize.width / 7, visibleSize.height - visibleSize.height / 14));//��������
	loading->setScale(1.5);
	this->addChild(loading, 4);//�������ʾ

	auto myAnimation = Animation::create();//��������֡����
	for (int i = 0; i < 56; i++) {
		char nameSize[100] = { 0 };//������������ĳ���
		sprintf(nameSize, "%d.png", i);//ѭ������
		myAnimation->addSpriteFrameWithFile(nameSize);//�������Ў�����
	}
	myAnimation->setDelayPerUnit(0.04f);// ������֮֡���ʱ����
	myAnimation->setLoops(2);//����ѭ��(-1��ʾ����ѭ��) 
	myAnimation->setRestoreOriginalFrame(false);//�����Ƿ��ڶ������Ž�����ָ�����һ֡
	auto mAninate = Animate::create(myAnimation);//����������������
	loading->runAction(mAninate);//ִ�ж���

	//��������
	/*auto MoveUp = MenuItemImage::create(
		"MoveUp.png",
		"MoveUp.png",
		CC_CALLBACK_1(HelloWorld::MoveUp, this));

	MoveUp->setPosition(Vec2(100, 100));
	auto MoveDown = MenuItemImage::create(
		"MoveDown.png",
		"MoveDown.png",
		CC_CALLBACK_1(HelloWorld::MoveDown, this));

	MoveDown->setPosition(Vec2(100, 40));
	auto MoveLeft = MenuItemImage::create(
		"MoveLeft.png",
		"MoveLeft.png",
		CC_CALLBACK_1(HelloWorld::MoveLeft, this));

	MoveLeft->setPosition(Vec2(40, 40));
	auto MoveRight = MenuItemImage::create(
		"MoveRight.png",
		"MoveRight.png",
		CC_CALLBACK_1(HelloWorld::MoveRight, this));

	MoveRight->setPosition(Vec2(160, 40));

	auto menu = Menu::create(MoveUp, MoveDown, MoveLeft, MoveRight, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);*/

	////�����¼�
	//auto listener = EventListenerKeyboard::create();
	//listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
	//	double PlayerPositionX = player->getPosition().x;
	//	double PlayerPositionY = player->getPosition().y;
	//	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW && PlayerPositionY <= (visibleSize.height - 100)) {
	//		CCMoveBy* moveup = CCMoveBy::create(0.3, Vec2(0, visibleSize.height / 6));
	//		player->runAction(moveup);
	//	}
	//	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW && PlayerPositionX > visibleSize.width / 6) {
	//		CCMoveBy* moveleft = CCMoveBy::create(0.3, Vec2(-visibleSize.width / 6, 0));
	//		player->runAction(moveleft);
	//	}
	//	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW && PlayerPositionX <= (visibleSize.width - visibleSize.width / 6)) {
	//		CCMoveBy* moveright = CCMoveBy::create(0.3, Vec2(visibleSize.width / 6, 0));
	//		player->runAction(moveright);
	//	}
	//	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW && PlayerPositionY > 100) {
	//		CCMoveBy* movedowm = CCMoveBy::create(0.3, Vec2(0, -visibleSize.height / 6));
	//		player->runAction(movedowm);
	//	}
	//};
	//auto dispatcher = Director::getInstance()->getEventDispatcher();
	//dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//�����¼�
	auto KeyListener = EventListenerKeyboard::create();
	KeyListener->onKeyPressed = ([=](EventKeyboard::KeyCode keycode, Event* event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			this->schedule(schedule_selector(HelloWorld::updateright), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			this->schedule(schedule_selector(HelloWorld::updateup), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			this->schedule(schedule_selector(HelloWorld::updateleft), 1 / 60, 10000, 0);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			this->schedule(schedule_selector(HelloWorld::updatedown), 1 / 60, 10000, 0);
			break;
		default:
			break;
		}
	});

	KeyListener->onKeyReleased = ([=](EventKeyboard::KeyCode keycode, Event *event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			this->unschedule(schedule_selector(HelloWorld::updateright));
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			this->unschedule(schedule_selector(HelloWorld::updateup));
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			this->unschedule(schedule_selector(HelloWorld::updateleft));
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			this->unschedule(schedule_selector(HelloWorld::updatedown));
			break;
		}
	});
	_eventDispatcher->addEventListenerWithSceneGraphPriority(KeyListener, this);


	
	//���ùؿ�
	if (RoundSelect == 1) {
		TotalCarsFast = 20;
		TotalCarsSlow = 16;
		TotalCarsPlus = 18;
		TotalCarsPlus2 = 24;
		IntervalFast = 2.5;
		IntervalSlow = 3;
		IntervalPlus = 2.3;
		IntervalPlus2 = 1.6;
		
	}
	else if(RoundSelect == 2){
		TotalCarsFast = 20;
		TotalCarsSlow = 16;
		TotalCarsPlus = 18;
		TotalCarsPlus2 = 24;
		IntervalFast = 2.5;
		IntervalSlow = 3;
		IntervalPlus = 2.3;
		IntervalPlus2 = 1.6;
	}
	else if (RoundSelect == 3) {
		TotalCarsFast = 20;
		TotalCarsSlow = 16;
		TotalCarsPlus = 18;
		TotalCarsPlus2 = 24;
		IntervalFast = 2.5;
		IntervalSlow = 3;
		IntervalPlus = 2.3;
		IntervalPlus2 = 1.6;
	}
	//����������ʱ��

	this->schedule(schedule_selector(HelloWorld::gameLogic), IntervalFast, TotalCarsFast, 9.4);
	this->schedule(schedule_selector(HelloWorld::gameLogic2), IntervalSlow, TotalCarsSlow, 9);
	this->schedule(schedule_selector(HelloWorld::gameLogicplus), IntervalPlus, TotalCarsPlus, 8.5);
	this->schedule(schedule_selector(HelloWorld::gameLogicplus2), IntervalPlus2, TotalCarsPlus2, 8.1);

	//��ɫ������ʱ��
	this->schedule(schedule_selector(HelloWorld::BlueReward), 13, 100, 9);

	

	//������Ӧע��
	auto Listener = EventListenerTouchOneByOne::create();                       //�������㴥���¼�������
	Listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);     //������ʼ
	Listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);     //�����ƶ�
	Listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);     //��������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);   //ע��ַ���

	//�໥�Ӵ������¼�
	//ˢ������
	this->schedule(schedule_selector(HelloWorld::update), 0.45, 100000, 1);
	this->schedule(schedule_selector(HelloWorld::blueupdate), 0.001, 100000, 1);

	//�������ϴ�����������
	_myotherplayer = CCArray::create();//����������������
	_myotherplayer->retain();

	//�������ϴ�����ɫ����
	_bluereward = CCArray::create();
	_bluereward->retain();
	
	//ʤ����ʱ��
	this->schedule(schedule_selector(HelloWorld::Complete_over), 0.01, 100000, 1);

	return true;

}
//ʤ����ʱ��
void HelloWorld::Complete_over(float dt) {
	if (Number <= 0) {
		CCTransitionTurnOffTiles* reScene;
		reScene = CCTransitionTurnOffTiles::create
		(0.5f, Complete::createScene());
		Director::getInstance()->replaceScene(reScene);
		SimpleAudioEngine::sharedEngine()->playEffect("game-victory.mp3");
		Number = 65;
		//�����ֺͻ�����Ч��ʼ��
		Protected = 1;
		FirePlayer = 1;
	}
}


//��������
void HelloWorld::BackgroundMusic(float dt) {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Start.mp3", true);    //���ű�������
}
void HelloWorld::Loading(float dt) {
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loading.mp3",true);
}
//player��Χ���涨ʱ��
int uuu = 0;
void HelloWorld::PlayerFire(float dt) {
	//��ȡģ������С
	auto visibleSize = Director::getInstance()->getVisibleSize();
			auto fire = Sprite::create();//��������
			Vec2 playerposition = player->getPosition();        //���player����
			double playerpositionX = player->getPosition().x;
			double playerpositionY = player->getPosition().y;
			fire->setPosition(Vec2(playerpositionX, playerpositionY - 50));//��������
			fire->setScale(1.3);
			this->addChild(fire, 4);//�������ʾ
			auto myAnimation = Animation::create();//��������֡����
			int i = uuu % 10 + 60;
			uuu++;
			char nameSize[100] = { 0 };//������������ĳ���
			sprintf(nameSize, "%d.png", i);//ѭ������
			myAnimation->addSpriteFrameWithFile(nameSize);//�������Ў�����
			myAnimation->setDelayPerUnit(0.025f);// ������֮֡���ʱ����
			myAnimation->setLoops(1);//����ѭ��(-1��ʾ����ѭ��) 
			myAnimation->setRestoreOriginalFrame(true);//�����Ƿ��ڶ������Ž�����ָ�����һ֡
			auto mAninate = Animate::create(myAnimation);//����������������
			fire->runAction(mAninate);//ִ�ж���
									  //Director::getInstance()->end();//windowsƽ̨�Ͱ�׿��Ҫ������һ��
			//this->scheduleOnce(schedule_selector(HelloWorld::RemoveFire), 0.25);










		}


////ɾ��С����Χ����
//void HelloWorld::RemoveFire(float delta) {
//	loadingbackground->removeFromParentAndCleanup(true);
//}

//ɾ���ȴ��ı���ͼƬ
void HelloWorld::RemoveLoadingback(float delta) {
	loadingbackground->removeFromParent();
}




//����ʱ����ʼ�׶Σ�

void HelloWorld::time(float delta) {
	auto visibleSize = Director::getInstance()->getVisibleSize();//��ȡģ������С
	    if (counter > -1) {
		    char _counter[100] = { 0 };
		    sprintf(_counter, "%d", counter);
		    label = Label::createWithTTF(_counter, "fonts/Marker Felt.ttf", 80);
		    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		    this->addChild(label, 4);
		    this->scheduleOnce(schedule_selector(HelloWorld::timeover), 0.9f);
			label->setColor(ccc3(0, 206, 209));
		    counter--;
	    }
	    if (counter == -1) {
			label->removeFromParent();
			label = Label::createWithTTF("GO", "fonts/Marker Felt.ttf", 80);
		    label->setColor(ccc3(0, 206, 209));
		    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		    this->addChild(label, 4);
		    this->scheduleOnce(schedule_selector(HelloWorld::timeover), 0.9f);
		    counter--;
	    }
	}
//��ʱ��
void HelloWorld::timeover(float delta) {//��δ���ÿ1s�ᱻִ��һ��
	if (counter >= -2) {
		label->removeFromParent();
	}
}

void HelloWorld::WuDitimeover(float delta) {
	bluelabel->removeFromParent();
}







//��ɫ�������޵�10�룩
void HelloWorld::createbluereward() {
	auto visibleSize = Director::getInstance()->getVisibleSize();	//��ȡģ������С
														
	int x = rand() % 8;    //���������ɫ����
	x = x + 1;

	//������ɫ����
	bluereward = CCSprite::create("bluereward.png");
	bluereward->setPosition(Vec2(visibleSize.width / 9 * x, visibleSize.height));
	this->addChild(bluereward, 2);

	//��ɫ������������
	_bluereward->addObject(bluereward);

	//����ɫ�����ƶ�����ʧ
	CCMoveTo* move = CCMoveTo::create(3, ccp(visibleSize.width / 9 * x, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine_bluereward));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	bluereward->runAction(action);
}

void HelloWorld::myDefine_bluereward(CCNode* who) {
	who->removeFromParentAndCleanup(true);
}










//��·�ƶ��Ļص�����
void HelloWorld::roadmove(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();//��ȡģ������С

	//������·
	if (RoundSelect == 1) {
		auto road = Sprite::create("road_1.png");
		road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(road, 0);
		//�õ�·�ƶ�����ʧ
		CCMoveBy* move = CCMoveBy::create(test, ccp(0, -visibleSize.height * 2 - visibleSize.height / 2));
		CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::roaddisappear));
		CCSequence*action = CCSequence::create(move, disappear, NULL);
		road->runAction(action);
	}
	else if (RoundSelect == 2) {
		auto road = Sprite::create("road_2.png");
		road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(road, 0);
		//�õ�·�ƶ�����ʧ
		CCMoveBy* move = CCMoveBy::create(test, ccp(0, -visibleSize.height * 2));
		CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::roaddisappear));
		CCSequence*action = CCSequence::create(move, disappear, NULL);
		road->runAction(action);
	}
	else if (RoundSelect == 3) {
		auto road = Sprite::create("road_3.png");
		road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(road, 0);
		CCMoveBy* move = CCMoveBy::create(test, ccp(0, -visibleSize.height * 2));
		CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::roaddisappear));
		CCSequence*action = CCSequence::create(move, disappear, NULL);
		road->runAction(action);
	}
}
	
	


//�Զ����·��ʧ
void HelloWorld::roaddisappear(CCNode* who) {
	who->removeFromParentAndCleanup(true);
}





//ˢ������(��ײ���)
void HelloWorld::update(float delta) {
	//��ȡģ������С
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//����Ƚ�
	CCARRAY_FOREACH(this->_myotherplayer, Otherplayer) {
		iOtherplayer = (CCSprite*)Otherplayer;
		if (iOtherplayer->boundingBox().intersectsRect(player->boundingBox()) && Protected == 1) {
			//��ͼgif���
			boom = Sprite::create();//��������
			boom->setPosition(Vec2(player->getPosition().x, player->getPosition().y));//��������
			this->addChild(boom, 5);//�������ʾ

			auto myAnimation = Animation::create();                //��������֡����
			for (int i = 1; i < 10; i++) {
				char nameSize[100] = { 0 };                         //������������ĳ���
				sprintf(nameSize, "boomB%d.png", i);                //ѭ������
				myAnimation->addSpriteFrameWithFile(nameSize);       //�������Ў�����
			}
			myAnimation->setDelayPerUnit(0.05f);                     // ������֮֡���ʱ����
			myAnimation->setLoops(2);                               //����ѭ��(-1��ʾ����ѭ��) 
			myAnimation->setRestoreOriginalFrame(true);              //�����Ƿ��ڶ������Ž�����ָ�����һ֡
			auto mAninate = Animate::create(myAnimation);//����������������
			boom->runAction(mAninate);//ִ�ж���
			//Director::getInstance()->end();//windowsƽ̨�Ͱ�׿��Ҫ������һ��
			this->scheduleOnce(schedule_selector(HelloWorld::BoomMusic), 0.46f);//ɾ����ը
			this->scheduleOnce(schedule_selector(HelloWorld::GameOver), 0.47f);//�ж��Ƿ����
			
		}
		else if (iOtherplayer->boundingBox().intersectsRect(player->boundingBox()) && Protected == 2) {
			this->scheduleOnce(schedule_selector(HelloWorld::RemoveProtect), 0.46f);//ɾ��������
			Protected = 1;
		}
	}
	
}
//ɾ��������
void HelloWorld::RemoveProtect(float delta) {
	iOtherplayer->removeFromParentAndCleanup(true);//ɾ����ɫС����
	_myotherplayer->removeObject(Otherplayer);//ɾ����ɫС����
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 playerPosition = player->getPosition();//���ԭС������
	player->removeFromParentAndCleanup(true);
	if (PlayerSelect == 1) {
		player = Sprite::create("Player_1.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 2) {
		player = Sprite::create("Player_2.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 3) {
		player = Sprite::create("Player_3.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 4) {
		player = Sprite::create("Player_4.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 5) {
		player = Sprite::create("Player_5.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 6) {
		player = Sprite::create("Player_6.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 7) {
		player = Sprite::create("Player_7.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 8) {
		player = Sprite::create("Player_8.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	//�����ƶ�
	this->runAction(Follow::create(player, Rect(-visibleSize.width / 4, 0, visibleSize.width * 1.5, visibleSize.height)));
}
//�ж��Ƿ����
void HelloWorld::GameOver(float delta) {
	if (FirePlayer == 1) {
		FirePlayer = 2;
		//player��Χ���涨ʱ��
		this->schedule(schedule_selector(HelloWorld::PlayerFire), 0.025);
	}
	else if (FirePlayer == 2) {
		CCTransitionSplitRows* reScene;
		reScene = CCTransitionSplitRows::create(0.8f, Failed::createScene());
		Director::getInstance()->replaceScene(reScene);
		SimpleAudioEngine::sharedEngine()->playEffect("game-fail.mp3");
		Number = 65;
		//�����ֺͻ�����Ч��ʼ��
		Protected = 1;
		FirePlayer = 1;
	}
}
//��ը����
void HelloWorld::BoomMusic(float delta) {
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("boom.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("boom.mp3");    //���ű�������
}

void HelloWorld::blueupdate(float delta) {
	//��ȡģ������С
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//��ɫ������ײ���
	CCObject * Bluereward;
	CCARRAY_FOREACH(this->_bluereward, Bluereward) {
		CCSprite * ibluereward = (CCSprite*)Bluereward;
		if (ibluereward->boundingBox().intersectsRect(player->boundingBox()) && Protected == 1) {
			ibluereward->removeFromParentAndCleanup(true);//ɾ����ɫС����
			_bluereward->removeObject(Bluereward);//ɾ����ɫС����
			Protected = 2;
			SimpleAudioEngine::sharedEngine()->playEffect("blue_reward.mp3");
			this->scheduleOnce(schedule_selector(HelloWorld::Protecting), 0.01f);
		}
	}
}

//���챣�����µ�player(ѡ����)
void HelloWorld::Protecting(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 playerPosition = player->getPosition();            //���ԭС������
	player->removeFromParentAndCleanup(true);

	/*if (PlayerSelect == 1) {
		player = Sprite::create("Player_1_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 2) {
		player = Sprite::create("Player_2_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 3) {
		player = Sprite::create("Player_3_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 4) {
		player = Sprite::create("Player_4_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 5) {
		player = Sprite::create("Player_5_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 6) {
		player = Sprite::create("Player_6_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 7) {
		player = Sprite::create("Player_7_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}
	else if (PlayerSelect == 8) {
		player = Sprite::create("Player_8_protected.png");
		player->setPosition(playerPosition);
		this->addChild(player, 2);
	}*/
	char playerNumber[30] = { 0 };
	sprintf(playerNumber, "Player_%d_protected.png", PlayerSelect);
	player = Sprite::create(playerNumber);
	player->setPosition(playerPosition);
	this->addChild(player, 2);

	//�����ƶ�
	this->runAction(Follow::create(player, Rect(-visibleSize.width / 4, 0, visibleSize.width * 1.5, visibleSize.height)));
}



//���ʱ�Ĳ���
bool HelloWorld::onTouchBegan(Touch* touch, Event* event) {
	CCLOG("KAISHI");
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event* event) {
	CCLOG("MOVE");
}
void HelloWorld::onTouchEnded(Touch* touch, Event* event) {
	CCLOG("ENDEN");
}

//��ʱ��
void HelloWorld::gameLogic(float dt) {
	this->CreateOtherPlayerFast();
}
void HelloWorld::gameLogic2(float dt) {
	this->CreateOtherPlayerSlow();
}
void HelloWorld::gameLogicplus(float dt) {
	this->CreateOtherPlayerPlus();
}
void HelloWorld::gameLogicplus2(float dt) {
	this->CreateOtherPlayerPlus2();
}
void HelloWorld::BlueReward(float dt)
{
	this->HelloWorld::createbluereward();
}

//���������ƶ�
//void HelloWorld::MoveUp(Ref* pSender) {
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	CCMoveBy *moveup = CCMoveBy::create(0.3, Vec2(0, visibleSize.height / 6));
//	player->runAction(moveup);
//}
//void HelloWorld::MoveDown(Ref* pSender) {
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	CCMoveBy *moveup = CCMoveBy::create(0.3, Vec2(0, -visibleSize.height / 6));
//	player->runAction(moveup);
//}
//void HelloWorld::MoveLeft(Ref* pSender) {
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	CCMoveBy *moveup = CCMoveBy::create(0.3, Vec2(-visibleSize.width/6, 0));
//	player->runAction(moveup);
//}
//void HelloWorld::MoveRight(Ref* pSender) {
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	CCMoveBy *moveup = CCMoveBy::create(0.3, Vec2(visibleSize.width / 6, 0));
//	player->runAction(moveup);
//#if 0
//	//�ƶ�
//	/*CCMoveBy * ObstructMove = CCMoveBy::create(2, Vec2(0, -visibleSize.height + 50));
//	otherplayer->runAction(ObstructMove);*/
//	CCMoveTo* move = CCMoveTo::create(2, ccp(125, 10));
//	CCCallFuncN* selfDefineAction = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
//	�ƶ�����ʧ
//	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
//	CCSequence*action = CCSequence::create(move, disappear, NULL);
//	otherplayer->runAction(action);
//#endif
//}
void HelloWorld::updateright(float dt){
	double PlayerPositionX = player->getPosition().x;//��ȡ����
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * mover = CCMoveBy::create(0.3, Vec2(visibleSize.width / 80, 0));
	if (PlayerPositionX <= (visibleSize.width - visibleSize.width / 6)){
		player->runAction(mover);
	}
}
void HelloWorld::updateup(float dt)
{
	double PlayerPositionY = player->getPosition().y;//��ȡ����
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moveu = CCMoveBy::create(0.3, Vec2(0, visibleSize.width / 80));
	if (PlayerPositionY <= (visibleSize.height - 100)) {
		player->runAction(moveu);
	}
}
void HelloWorld::updateleft(float dt)
{
	double PlayerPositionX = player->getPosition().x;//��ȡ����
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * movel = CCMoveBy::create(0.3, Vec2(-visibleSize.width / 80, 0));
	if (PlayerPositionX > (visibleSize.width / 6)) {
		player->runAction(movel);
	}
}
void HelloWorld::updatedown(float dt)
{
	double PlayerPositionY = player->getPosition().y;//��ȡ����
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moved = CCMoveBy::create(0.3, Vec2(0, -visibleSize.width / 80));
	if (PlayerPositionY > 100) {
		player->runAction(moved);
	}
}

//�ö�ʱ��������������
void HelloWorld::CreateOtherPlayerFast() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//�������С��
	int x = rand() % 8;
	x = x + 1;

	//����һ��С��
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 9  * x, visibleSize.height));
	this->addChild(myotherplayer, 2);

	_myotherplayer->addObject(myotherplayer);//���������뼯��

	//��С���ƶ�����ʧ
	CCMoveTo* move = CCMoveTo::create(IntervalFast, ccp(visibleSize.width / 9 * x, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerSlow() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//�������С��
	int y = rand() % 9;
	y = y + 1;

	//����һ��С��
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 9 * y, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//���������뼯��

											 //��С���ƶ�����ʧ
	CCMoveTo* move = CCMoveTo::create(IntervalSlow, ccp(visibleSize.width / 9 * y, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerPlus() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//�������С��
	int i = rand() % 10;
	i = i + 1;

	//����һ��С��
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 11 * i, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//���������뼯��

											 //��С���ƶ�����ʧ
	CCMoveTo* move = CCMoveTo::create(IntervalPlus, ccp(visibleSize.width / 11 * i, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerPlus2() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//�������С��
	int i = rand() % 10;
	i = i + 1;

	//����һ��С��
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 11 * i, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//���������뼯��

											 //��С���ƶ�����ʧ
	CCMoveTo* move = CCMoveTo::create(IntervalPlus2, ccp(visibleSize.width / 11 * i, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}

//�Զ���С����
void HelloWorld::myDefine(CCNode* who) {
	//who->setPosition(ccp(0, 0));
	//who->setScale(1);
	who->removeFromParentAndCleanup(true);
	Number--;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
