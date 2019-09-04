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
//保护罩和火焰特效
static int Protected = 1;
static int FirePlayer = 1;
//模式和汽车选择
extern int RoundSelect;
extern int PlayerSelect;
//总车数（胜利判断）
static int Number = 65;
//测试
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
	//获取模拟器大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//小汽车部署(选车后)
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


	//背景颜色

	//背景移动

	this->runAction(Follow::create(player, 
	Rect(-visibleSize.width / 4, 0,
	visibleSize.width * 1.5, visibleSize.height)));

	//倒计时
	this->schedule(schedule_selector(HelloWorld::time), 1, 5, 4);//开启一个每1s执行一次的计时器

	//背景音乐
	this->scheduleOnce(schedule_selector(HelloWorld::Loading), 0.1f);//前四秒背景音乐
	this->scheduleOnce(schedule_selector(HelloWorld::BackgroundMusic), 5.0f);//四秒后背景音乐


	//背景图片(道路滚动)
    this->schedule(schedule_selector(HelloWorld::roadmove), test, 200, 5);//道路移动定时器

	//等待背景图片
	this->scheduleOnce(schedule_selector(HelloWorld::RemoveLoadingback), 4);
	loadingbackground = CCSprite::create("LoadingBackground.png");
	loadingbackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(loadingbackground, 3);

	//等待图标(gif)
	auto loading = Sprite::create("0.png");//创建精灵
	loading->setPosition(Vec2(visibleSize.width - visibleSize.width / 7, visibleSize.height - visibleSize.height / 14));//设置坐标
	loading->setScale(1.5);
	this->addChild(loading, 4);//加入层显示

	auto myAnimation = Animation::create();//创建序列帧动画
	for (int i = 0; i < 56; i++) {
		char nameSize[100] = { 0 };//设置名字数组的长度
		sprintf(nameSize, "%d.png", i);//循环遍历
		myAnimation->addSpriteFrameWithFile(nameSize);//加入序列幀动画
	}
	myAnimation->setDelayPerUnit(0.04f);// 设置两帧之间的时间间隔
	myAnimation->setLoops(2);//设置循环(-1表示无限循环) 
	myAnimation->setRestoreOriginalFrame(false);//设置是否在动画播放结束后恢复到第一帧
	auto mAninate = Animate::create(myAnimation);//创建动画动作对象
	loading->runAction(mAninate);//执行动作

	//上下左右
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

	////键盘事件
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

	//键盘事件
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


	
	//设置关卡
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
	//其他汽车定时器

	this->schedule(schedule_selector(HelloWorld::gameLogic), IntervalFast, TotalCarsFast, 9.4);
	this->schedule(schedule_selector(HelloWorld::gameLogic2), IntervalSlow, TotalCarsSlow, 9);
	this->schedule(schedule_selector(HelloWorld::gameLogicplus), IntervalPlus, TotalCarsPlus, 8.5);
	this->schedule(schedule_selector(HelloWorld::gameLogicplus2), IntervalPlus2, TotalCarsPlus2, 8.1);

	//蓝色奖励定时器
	this->schedule(schedule_selector(HelloWorld::BlueReward), 13, 100, 9);

	

	//触摸响应注册
	auto Listener = EventListenerTouchOneByOne::create();                       //创建单点触摸事件监听器
	Listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);     //触摸开始
	Listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);     //触摸移动
	Listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);     //触摸结束
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);   //注册分发器

	//相互接触产生事件
	//刷新坐标
	this->schedule(schedule_selector(HelloWorld::update), 0.45, 100000, 1);
	this->schedule(schedule_selector(HelloWorld::blueupdate), 0.001, 100000, 1);

	//创建集合储存其他汽车
	_myotherplayer = CCArray::create();//创建汽车集合容器
	_myotherplayer->retain();

	//创建集合储存蓝色奖励
	_bluereward = CCArray::create();
	_bluereward->retain();
	
	//胜利计时器
	this->schedule(schedule_selector(HelloWorld::Complete_over), 0.01, 100000, 1);

	return true;

}
//胜利计时器
void HelloWorld::Complete_over(float dt) {
	if (Number <= 0) {
		CCTransitionTurnOffTiles* reScene;
		reScene = CCTransitionTurnOffTiles::create
		(0.5f, Complete::createScene());
		Director::getInstance()->replaceScene(reScene);
		SimpleAudioEngine::sharedEngine()->playEffect("game-victory.mp3");
		Number = 65;
		//保护罩和火焰特效初始化
		Protected = 1;
		FirePlayer = 1;
	}
}


//背景音乐
void HelloWorld::BackgroundMusic(float dt) {
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Start.mp3", true);    //播放背景音乐
}
void HelloWorld::Loading(float dt) {
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loading.mp3",true);
}
//player周围火焰定时器
int uuu = 0;
void HelloWorld::PlayerFire(float dt) {
	//获取模拟器大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
			auto fire = Sprite::create();//创建精灵
			Vec2 playerposition = player->getPosition();        //获得player坐标
			double playerpositionX = player->getPosition().x;
			double playerpositionY = player->getPosition().y;
			fire->setPosition(Vec2(playerpositionX, playerpositionY - 50));//设置坐标
			fire->setScale(1.3);
			this->addChild(fire, 4);//加入层显示
			auto myAnimation = Animation::create();//创建序列帧动画
			int i = uuu % 10 + 60;
			uuu++;
			char nameSize[100] = { 0 };//设置名字数组的长度
			sprintf(nameSize, "%d.png", i);//循环遍历
			myAnimation->addSpriteFrameWithFile(nameSize);//加入序列幀动画
			myAnimation->setDelayPerUnit(0.025f);// 设置两帧之间的时间间隔
			myAnimation->setLoops(1);//设置循环(-1表示无限循环) 
			myAnimation->setRestoreOriginalFrame(true);//设置是否在动画播放结束后恢复到第一帧
			auto mAninate = Animate::create(myAnimation);//创建动画动作对象
			fire->runAction(mAninate);//执行动作
									  //Director::getInstance()->end();//windows平台和安卓主要调用这一句
			//this->scheduleOnce(schedule_selector(HelloWorld::RemoveFire), 0.25);










		}


////删除小车周围火焰
//void HelloWorld::RemoveFire(float delta) {
//	loadingbackground->removeFromParentAndCleanup(true);
//}

//删除等待的背景图片
void HelloWorld::RemoveLoadingback(float delta) {
	loadingbackground->removeFromParent();
}




//倒计时（开始阶段）

void HelloWorld::time(float delta) {
	auto visibleSize = Director::getInstance()->getVisibleSize();//获取模拟器大小
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
//计时器
void HelloWorld::timeover(float delta) {//这段代码每1s会被执行一次
	if (counter >= -2) {
		label->removeFromParent();
	}
}

void HelloWorld::WuDitimeover(float delta) {
	bluelabel->removeFromParent();
}







//蓝色奖励（无敌10秒）
void HelloWorld::createbluereward() {
	auto visibleSize = Director::getInstance()->getVisibleSize();	//获取模拟器大小
														
	int x = rand() % 8;    //随机产生蓝色奖励
	x = x + 1;

	//创作蓝色奖励
	bluereward = CCSprite::create("bluereward.png");
	bluereward->setPosition(Vec2(visibleSize.width / 9 * x, visibleSize.height));
	this->addChild(bluereward, 2);

	//蓝色奖励加入数组
	_bluereward->addObject(bluereward);

	//让蓝色奖励移动后，消失
	CCMoveTo* move = CCMoveTo::create(3, ccp(visibleSize.width / 9 * x, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine_bluereward));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	bluereward->runAction(action);
}

void HelloWorld::myDefine_bluereward(CCNode* who) {
	who->removeFromParentAndCleanup(true);
}










//道路移动的回调函数
void HelloWorld::roadmove(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();//获取模拟器大小

	//创建道路
	if (RoundSelect == 1) {
		auto road = Sprite::create("road_1.png");
		road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(road, 0);
		//让道路移动后，消失
		CCMoveBy* move = CCMoveBy::create(test, ccp(0, -visibleSize.height * 2 - visibleSize.height / 2));
		CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::roaddisappear));
		CCSequence*action = CCSequence::create(move, disappear, NULL);
		road->runAction(action);
	}
	else if (RoundSelect == 2) {
		auto road = Sprite::create("road_2.png");
		road->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(road, 0);
		//让道路移动后，消失
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
	
	


//自定义道路消失
void HelloWorld::roaddisappear(CCNode* who) {
	who->removeFromParentAndCleanup(true);
}





//刷新坐标(碰撞检测)
void HelloWorld::update(float delta) {
	//获取模拟器大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//数组比较
	CCARRAY_FOREACH(this->_myotherplayer, Otherplayer) {
		iOtherplayer = (CCSprite*)Otherplayer;
		if (iOtherplayer->boundingBox().intersectsRect(player->boundingBox()) && Protected == 1) {
			//动图gif添加
			boom = Sprite::create();//创建精灵
			boom->setPosition(Vec2(player->getPosition().x, player->getPosition().y));//设置坐标
			this->addChild(boom, 5);//加入层显示

			auto myAnimation = Animation::create();                //创建序列帧动画
			for (int i = 1; i < 10; i++) {
				char nameSize[100] = { 0 };                         //设置名字数组的长度
				sprintf(nameSize, "boomB%d.png", i);                //循环遍历
				myAnimation->addSpriteFrameWithFile(nameSize);       //加入序列幀动画
			}
			myAnimation->setDelayPerUnit(0.05f);                     // 设置两帧之间的时间间隔
			myAnimation->setLoops(2);                               //设置循环(-1表示无限循环) 
			myAnimation->setRestoreOriginalFrame(true);              //设置是否在动画播放结束后恢复到第一帧
			auto mAninate = Animate::create(myAnimation);//创建动画动作对象
			boom->runAction(mAninate);//执行动作
			//Director::getInstance()->end();//windows平台和安卓主要调用这一句
			this->scheduleOnce(schedule_selector(HelloWorld::BoomMusic), 0.46f);//删除爆炸
			this->scheduleOnce(schedule_selector(HelloWorld::GameOver), 0.47f);//判断是否结束
			
		}
		else if (iOtherplayer->boundingBox().intersectsRect(player->boundingBox()) && Protected == 2) {
			this->scheduleOnce(schedule_selector(HelloWorld::RemoveProtect), 0.46f);//删除保护罩
			Protected = 1;
		}
	}
	
}
//删除保护罩
void HelloWorld::RemoveProtect(float delta) {
	iOtherplayer->removeFromParentAndCleanup(true);//删除蓝色小汽车
	_myotherplayer->removeObject(Otherplayer);//删除蓝色小汽车
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 playerPosition = player->getPosition();//获得原小车坐标
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
	//背景移动
	this->runAction(Follow::create(player, Rect(-visibleSize.width / 4, 0, visibleSize.width * 1.5, visibleSize.height)));
}
//判断是否结束
void HelloWorld::GameOver(float delta) {
	if (FirePlayer == 1) {
		FirePlayer = 2;
		//player周围火焰定时器
		this->schedule(schedule_selector(HelloWorld::PlayerFire), 0.025);
	}
	else if (FirePlayer == 2) {
		CCTransitionSplitRows* reScene;
		reScene = CCTransitionSplitRows::create(0.8f, Failed::createScene());
		Director::getInstance()->replaceScene(reScene);
		SimpleAudioEngine::sharedEngine()->playEffect("game-fail.mp3");
		Number = 65;
		//保护罩和火焰特效初始化
		Protected = 1;
		FirePlayer = 1;
	}
}
//爆炸音乐
void HelloWorld::BoomMusic(float delta) {
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("boom.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("boom.mp3");    //播放背景音乐
}

void HelloWorld::blueupdate(float delta) {
	//获取模拟器大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//蓝色奖励碰撞检测
	CCObject * Bluereward;
	CCARRAY_FOREACH(this->_bluereward, Bluereward) {
		CCSprite * ibluereward = (CCSprite*)Bluereward;
		if (ibluereward->boundingBox().intersectsRect(player->boundingBox()) && Protected == 1) {
			ibluereward->removeFromParentAndCleanup(true);//删除蓝色小汽车
			_bluereward->removeObject(Bluereward);//删除蓝色小汽车
			Protected = 2;
			SimpleAudioEngine::sharedEngine()->playEffect("blue_reward.mp3");
			this->scheduleOnce(schedule_selector(HelloWorld::Protecting), 0.01f);
		}
	}
}

//创造保护罩下的player(选车后)
void HelloWorld::Protecting(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 playerPosition = player->getPosition();            //获得原小车坐标
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

	//背景移动
	this->runAction(Follow::create(player, Rect(-visibleSize.width / 4, 0, visibleSize.width * 1.5, visibleSize.height)));
}



//点击时的操作
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

//定时器
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

//上下左右移动
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
//	//移动
//	/*CCMoveBy * ObstructMove = CCMoveBy::create(2, Vec2(0, -visibleSize.height + 50));
//	otherplayer->runAction(ObstructMove);*/
//	CCMoveTo* move = CCMoveTo::create(2, ccp(125, 10));
//	CCCallFuncN* selfDefineAction = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
//	移动完消失
//	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
//	CCSequence*action = CCSequence::create(move, disappear, NULL);
//	otherplayer->runAction(action);
//#endif
//}
void HelloWorld::updateright(float dt){
	double PlayerPositionX = player->getPosition().x;//获取坐标
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * mover = CCMoveBy::create(0.3, Vec2(visibleSize.width / 80, 0));
	if (PlayerPositionX <= (visibleSize.width - visibleSize.width / 6)){
		player->runAction(mover);
	}
}
void HelloWorld::updateup(float dt)
{
	double PlayerPositionY = player->getPosition().y;//获取坐标
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moveu = CCMoveBy::create(0.3, Vec2(0, visibleSize.width / 80));
	if (PlayerPositionY <= (visibleSize.height - 100)) {
		player->runAction(moveu);
	}
}
void HelloWorld::updateleft(float dt)
{
	double PlayerPositionX = player->getPosition().x;//获取坐标
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * movel = CCMoveBy::create(0.3, Vec2(-visibleSize.width / 80, 0));
	if (PlayerPositionX > (visibleSize.width / 6)) {
		player->runAction(movel);
	}
}
void HelloWorld::updatedown(float dt)
{
	double PlayerPositionY = player->getPosition().y;//获取坐标
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCMoveBy * moved = CCMoveBy::create(0.3, Vec2(0, -visibleSize.width / 80));
	if (PlayerPositionY > 100) {
		player->runAction(moved);
	}
}

//用定时器创作其他汽车
void HelloWorld::CreateOtherPlayerFast() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//随机产生小车
	int x = rand() % 8;
	x = x + 1;

	//创造一个小车
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 9  * x, visibleSize.height));
	this->addChild(myotherplayer, 2);

	_myotherplayer->addObject(myotherplayer);//把汽车加入集合

	//让小车移动后，消失
	CCMoveTo* move = CCMoveTo::create(IntervalFast, ccp(visibleSize.width / 9 * x, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerSlow() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//随机产生小车
	int y = rand() % 9;
	y = y + 1;

	//创造一个小车
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 9 * y, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//把汽车加入集合

											 //让小车移动后，消失
	CCMoveTo* move = CCMoveTo::create(IntervalSlow, ccp(visibleSize.width / 9 * y, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerPlus() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//随机产生小车
	int i = rand() % 10;
	i = i + 1;

	//创造一个小车
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 11 * i, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//把汽车加入集合

											 //让小车移动后，消失
	CCMoveTo* move = CCMoveTo::create(IntervalPlus, ccp(visibleSize.width / 11 * i, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}
void HelloWorld::CreateOtherPlayerPlus2() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//随机产生小车
	int i = rand() % 10;
	i = i + 1;

	//创造一个小车
	myotherplayer = Sprite::create("otherplayer.png");
	myotherplayer->setPosition(ccp(visibleSize.width / 11 * i, visibleSize.height));
	this->addChild(myotherplayer, 2);


	_myotherplayer->addObject(myotherplayer);//把汽车加入集合

											 //让小车移动后，消失
	CCMoveTo* move = CCMoveTo::create(IntervalPlus2, ccp(visibleSize.width / 11 * i, -300));
	CCCallFuncN* disappear = CCCallFuncN::create(this, callfuncN_selector(HelloWorld::myDefine));
	CCSequence*action = CCSequence::create(move, disappear, NULL);
	myotherplayer->runAction(action);
}

//自定义小汽车
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
