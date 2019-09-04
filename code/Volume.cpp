#include "Volume.h"
#include "option.h"

#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "stdlib.h"

USING_NS_CC;

using namespace CocosDenshion;
using namespace cocos2d::ui;

Volume::Volume()
{
}

Volume::~Volume()
{
}
Scene* Volume::createScene()
{
	return Volume::create();
}

bool Volume::init() {
	if (!Scene::init())
	{
		return false;
	}
	auto rootNode = CSLoader::getInstance()->createNode("Volume.csb");
	addChild(rootNode);



	//���ű�������
	/*SimpleAudioEngine::getInstance()->playBackgroundMusic("forget.mp3", true);*/

	Button * btnmusic = dynamic_cast<Button*>(rootNode->getChildByName("Button_3"));                  //���ְ�ť

	Slider * music_slider = dynamic_cast<Slider*>(rootNode->getChildByName("Slider_2"));
	float musicpercent = UserDefault::getInstance()->getFloatForKey("musicPercent");
	float musicpercent1 = 0;
	if (musicpercent1 == 0.0f)
	{
		musicpercent1 = 100.0f;
	}
	music_slider->setPercent(musicpercent1);//����ԭʼ������������Ϊ100

	btnmusic->addClickEventListener([=](Ref*sender) {                      //������ͼ
		float musicv = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
		//SimpleAudioEngine::getInstance()->playEffect("forget.mp3");
		if (musicv != 0)
		{
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0);
			music_slider->setPercent(0);
			btnmusic->loadTextureNormal("sound_off.png");    //�㻬�����ұ߾���ʱ��ͼƬ
		}
		if (musicv == 0)
		{
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1);
			music_slider->setPercent(100);
			btnmusic->loadTextureNormal("sound_on.png");//�㻬�����ұ߿�������ʱ��ͼƬ
		}
	});

	//���û�����ͬ�����������Ĵ�С
	music_slider->addEventListener([=](Ref*pSender, Slider::EventType type)
	{
		if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
		{
			float pece1 = music_slider->getPercent();
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(pece1 / 100.0);
			//UserDefault::getInstance()->setFloatForKey("musicPercent",pece);
			if (pece1 == 0)
			{
				btnmusic->loadTextureNormal("sound_off.png");  //����������ʱ�ұߵ�ͼ��
			}
			else
			{
				btnmusic->loadTextureNormal("sound_on.png");
			}
		}
	});

	//���ذ�ť
	auto back = MenuItemImage::create(
		"back_normal.png",
		"back_pressed.png",
		CC_CALLBACK_1(Volume::back, this));
	back->setPosition(Vec2(538.83, 270.17));
	back->setScale(0.45);

	auto menu = Menu::create(back , NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void Volume::back(Ref* pSender) {
	CCTransitionCrossFade* reScene;
	reScene = CCTransitionCrossFade::create(0.5f, option::createScene());
	Director::getInstance()->replaceScene(reScene);
	SimpleAudioEngine::sharedEngine()->playEffect("press_LuShi.mp3");
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("SelectRoundDone.mp3");
}