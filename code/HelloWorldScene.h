#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
	//把汽车们设为共有
	cocos2d::Sprite* player;
	cocos2d::CCSprite* myotherplayer;
	cocos2d::CCSprite* loadingbackground;
	cocos2d::Sprite* boom;
	cocos2d::CCSprite* iOtherplayer;
	cocos2d::CCObject *Otherplayer;

    static cocos2d::Scene* createScene();

    virtual bool init();

	//背景音乐
	void Loading(float dt);//前四秒背景音乐
	void BackgroundMusic(float dt);//四秒后背景音乐

	//胜利计时器
	void Complete_over(float dt);

	//等待界面
	void RemoveLoadingback(float delta);

	//计时器
	cocos2d::Label * label;
	void time(float delta);
	void timeover(float delta);
    
	//自定义小汽车
	void myDefine(cocos2d::CCNode* who);

	//爆炸音乐
	void BoomMusic(float delta);

	//player周围火焰定时器
	void PlayerFire(float delta);
	//删除小车周围火焰
	void RemoveFire(float delta);

	//蓝色奖励
	cocos2d::Label* bluelabel;
	cocos2d::CCSprite* bluereward;
	void createbluereward();
	void BlueReward(float dt);
	void myDefine_bluereward(cocos2d::CCNode* who);//蓝色奖励自定义消失
	cocos2d::CCArray* _bluereward;//创建集合储存蓝色奖励
	void blueupdate(float delta);//蓝色定时器
	void blueWuDi(float delta);
	void WuDitimeover(float delta);//删除无敌时间
	void Protecting(float delta);//创造player



	void roadmove(float dt);//道路移动的回调函数
	void roaddisappear(cocos2d::CCNode* who);//道路消失

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	//汽车上下左右移动
	/*void MoveUp(cocos2d::Ref* pSender);
	void MoveDown(cocos2d::Ref* pSender);
	void MoveLeft(cocos2d::Ref* pSender);
	void MoveRight(cocos2d::Ref* pSender);*/
	void updateright(float dt);
	void updateup(float dt);
	void updateleft(float dt);
	void updatedown(float dt);


	//创造其他汽车
	void CreateOtherPlayerFast();
	void CreateOtherPlayerSlow();
	void CreateOtherPlayerPlus();
	void CreateOtherPlayerPlus2();
	cocos2d::CCArray* _myotherplayer;

	//定时器
	void gameLogic(float dt);
	void gameLogic2(float dt);
	void gameLogicplus(float dt);
	void gameLogicplus2(float dt);

    //点击时的操作
	bool onTouchBegan(cocos2d:: Touch* touch, cocos2d:: Event* event);
	void onTouchMoved(cocos2d:: Touch* touch, cocos2d:: Event* event);
	void onTouchEnded(cocos2d:: Touch* touch, cocos2d:: Event* event);

	//刷新坐标myotherplayer;	//创建集合储存其他汽车

	void update(float delta);
	void GameOver(float delta);//判断是否结束			  
	void RemoveProtect(float delta);  //删除保护罩

    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

};

#endif

//virtual bool onTouchBegan(Touch *touch, Event *unused_event);
//
//virtual void onTouchMoved(Touch *touch, Event *unused_event);
//
//virtual void onTouchEnded(Touch *touch, Event *unused_event);
//
////点击移动的计划任务
//void toch_Move(float dt);


#ifndef __First3DLayer_H__
#define __First3DLayer_H__

#include "cocos2d.h"
#include "3d/CCAnimation3D.h"
#include "3d/CCAnimate3D.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace ui;
using namespace cocos2d::extension;
#define N 5000000
//class First3DLayer : public cocos2d::Layer
//{
//public:
//	Camera * camera;			//摄像机
//								//	GameSceneManager *gsm;
//	float degree = 0;
//
//	Sprite3D* back1;
//	Sprite3D* back2;
//	//	Sprite3D* upSpeed;
//	MotionStreak *myStreak; 		//拖尾
//	Sprite *progress;			//进度条的背景
//								//	LoadingBar *loadingbar;		// 子弹的进度条
//	Animate *protectAnim;
//	ControlPotentiometer *potentiometer;	//圆盘进度条
//	float progressNum = 500;					//倒计时
//	BillBoard *temp;						//保护罩
//	BillBoard *tempProgress;
//
//	DirectionLight *directionLight;			//定向光
//	bool attackFlag = false;
//	bool attackAnimFlag = false;
//	bool protectFlag = false;
//	bool protectAnimFlag = false;
//	//-----------------------------
//	static std::vector<Sprite3D*> enemyVec;
//	static std::vector<BillBoard*> bulletVec;
//	static std::vector<BillBoard*> explosionVec;
//	static std::vector<Sprite3D*> enemyDel;
//	static std::vector<BillBoard*> bulletDel;
//	static std::vector<BillBoard*> explosionDel;
//	///-------------------------
//	virtual bool init();
//	void createPlane();		//创建第几关
//	void updateCreateMissile(float f);
//	void update(float f);
//	void changeCamera(float x);
//	void deletePlane();				//删除飞机的定时回调
//	void createMissile();			//创建导弹
//	void resetGame();				//重置游戏信息
//	void attackAll();				//攻击所有敌机
//	void attackAllFinish();			//攻击敌机技能结束
//	void protectMyself();			//保护飞机
//	void protectMyselfFinish();		//保护飞机技能结束
//	void updateProgress();
//	void startGame();				//开始游戏
//	void clearAllBullets();			//清除所有子弹
//									//获取世界坐标
//	void getAnimPoint(Vec3 nearP, Vec3 farP);
//	//飞机的触摸监听
//	bool onMyTouchBegan1(Touch* touch, Event* event);
//	void onMyTouchMoved(Touch* touch, Event* event);
//	void onMyTouchEnded(Touch* touch, Event* event);
//
//private:
//	int planeId;			//飞机编号
//	int gameLevel;			//游戏关卡
//	int attackGrade;		//攻击力等级
//	int bloodGrade;			//血量
//	int bulletsGrade;		//子弹的攻击速度
//	int goldGrade;			//金币加成
//	float enemy2Num[N];				//敌机2号编号
//	float enemy3Num[N];				//敌机3号编号
//	void getProperty();				//获取游戏的属性
//	void playerBullets(float dt);	//玩家飞机子弹回调方法
//	Animate *boomAnim;				//大爆炸
//									//    void changePro();				//改变进度条
//	bool touchFlag = false;			//触摸标志位
//};
//
//enum Complete
//{
//	loseEnum, winEnum
//};

#endif
