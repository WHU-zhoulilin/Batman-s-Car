#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
	//����������Ϊ����
	cocos2d::Sprite* player;
	cocos2d::CCSprite* myotherplayer;
	cocos2d::CCSprite* loadingbackground;
	cocos2d::Sprite* boom;
	cocos2d::CCSprite* iOtherplayer;
	cocos2d::CCObject *Otherplayer;

    static cocos2d::Scene* createScene();

    virtual bool init();

	//��������
	void Loading(float dt);//ǰ���뱳������
	void BackgroundMusic(float dt);//����󱳾�����

	//ʤ����ʱ��
	void Complete_over(float dt);

	//�ȴ�����
	void RemoveLoadingback(float delta);

	//��ʱ��
	cocos2d::Label * label;
	void time(float delta);
	void timeover(float delta);
    
	//�Զ���С����
	void myDefine(cocos2d::CCNode* who);

	//��ը����
	void BoomMusic(float delta);

	//player��Χ���涨ʱ��
	void PlayerFire(float delta);
	//ɾ��С����Χ����
	void RemoveFire(float delta);

	//��ɫ����
	cocos2d::Label* bluelabel;
	cocos2d::CCSprite* bluereward;
	void createbluereward();
	void BlueReward(float dt);
	void myDefine_bluereward(cocos2d::CCNode* who);//��ɫ�����Զ�����ʧ
	cocos2d::CCArray* _bluereward;//�������ϴ�����ɫ����
	void blueupdate(float delta);//��ɫ��ʱ��
	void blueWuDi(float delta);
	void WuDitimeover(float delta);//ɾ���޵�ʱ��
	void Protecting(float delta);//����player



	void roadmove(float dt);//��·�ƶ��Ļص�����
	void roaddisappear(cocos2d::CCNode* who);//��·��ʧ

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	//�������������ƶ�
	/*void MoveUp(cocos2d::Ref* pSender);
	void MoveDown(cocos2d::Ref* pSender);
	void MoveLeft(cocos2d::Ref* pSender);
	void MoveRight(cocos2d::Ref* pSender);*/
	void updateright(float dt);
	void updateup(float dt);
	void updateleft(float dt);
	void updatedown(float dt);


	//������������
	void CreateOtherPlayerFast();
	void CreateOtherPlayerSlow();
	void CreateOtherPlayerPlus();
	void CreateOtherPlayerPlus2();
	cocos2d::CCArray* _myotherplayer;

	//��ʱ��
	void gameLogic(float dt);
	void gameLogic2(float dt);
	void gameLogicplus(float dt);
	void gameLogicplus2(float dt);

    //���ʱ�Ĳ���
	bool onTouchBegan(cocos2d:: Touch* touch, cocos2d:: Event* event);
	void onTouchMoved(cocos2d:: Touch* touch, cocos2d:: Event* event);
	void onTouchEnded(cocos2d:: Touch* touch, cocos2d:: Event* event);

	//ˢ������myotherplayer;	//�������ϴ�����������

	void update(float delta);
	void GameOver(float delta);//�ж��Ƿ����			  
	void RemoveProtect(float delta);  //ɾ��������

    
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
////����ƶ��ļƻ�����
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
//	Camera * camera;			//�����
//								//	GameSceneManager *gsm;
//	float degree = 0;
//
//	Sprite3D* back1;
//	Sprite3D* back2;
//	//	Sprite3D* upSpeed;
//	MotionStreak *myStreak; 		//��β
//	Sprite *progress;			//�������ı���
//								//	LoadingBar *loadingbar;		// �ӵ��Ľ�����
//	Animate *protectAnim;
//	ControlPotentiometer *potentiometer;	//Բ�̽�����
//	float progressNum = 500;					//����ʱ
//	BillBoard *temp;						//������
//	BillBoard *tempProgress;
//
//	DirectionLight *directionLight;			//�����
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
//	void createPlane();		//�����ڼ���
//	void updateCreateMissile(float f);
//	void update(float f);
//	void changeCamera(float x);
//	void deletePlane();				//ɾ���ɻ��Ķ�ʱ�ص�
//	void createMissile();			//��������
//	void resetGame();				//������Ϸ��Ϣ
//	void attackAll();				//�������ел�
//	void attackAllFinish();			//�����л����ܽ���
//	void protectMyself();			//�����ɻ�
//	void protectMyselfFinish();		//�����ɻ����ܽ���
//	void updateProgress();
//	void startGame();				//��ʼ��Ϸ
//	void clearAllBullets();			//��������ӵ�
//									//��ȡ��������
//	void getAnimPoint(Vec3 nearP, Vec3 farP);
//	//�ɻ��Ĵ�������
//	bool onMyTouchBegan1(Touch* touch, Event* event);
//	void onMyTouchMoved(Touch* touch, Event* event);
//	void onMyTouchEnded(Touch* touch, Event* event);
//
//private:
//	int planeId;			//�ɻ����
//	int gameLevel;			//��Ϸ�ؿ�
//	int attackGrade;		//�������ȼ�
//	int bloodGrade;			//Ѫ��
//	int bulletsGrade;		//�ӵ��Ĺ����ٶ�
//	int goldGrade;			//��Ҽӳ�
//	float enemy2Num[N];				//�л�2�ű��
//	float enemy3Num[N];				//�л�3�ű��
//	void getProperty();				//��ȡ��Ϸ������
//	void playerBullets(float dt);	//��ҷɻ��ӵ��ص�����
//	Animate *boomAnim;				//��ը
//									//    void changePro();				//�ı������
//	bool touchFlag = false;			//������־λ
//};
//
//enum Complete
//{
//	loseEnum, winEnum
//};

#endif
