/*
 * BackgroundLayer.h
 *
 *  Created on: 2015年4月11日
 *      Author: Administrator
 */

#ifndef BACKGROUNDLAYER_H_
#define BACKGROUNDLAYER_H_
#include "cocos2d.h"
#include "Player.h"
#include "SimpleAudioEngine.h"
#include "GameOverLayer.h"
USING_NS_CC;
class BackgroundLayer:public Layer {
private:
	static const int STICK_SPEED=5;//棍子增长的速度，即游戏的难度；
	bool isStart = false;
	Size MyWinSize;
	Menu* menu;
	Sprite* GameName;
	Sprite* Image_One;
	Sprite* Image_Two;
	Sprite* stageSprite[3];
	int stageNumber=1;//初始值设为1
	int NowStage=0;//player所在的stage
	int LastStage=2;//player所在前一个stage
	int NextStage=1;//player将要走到的stage
	Player* player;
	Sprite* stick;
	double TouchLength;//用来存储我们棍子的长度
	double DestLengthMin;
	double DestLengthMax;
    int scoreCount=0;
	bool successFlag=false;//true表示player能够成功移动到下一个梯子
	bool moveComplete=false;//true表示移动到下一个平台动作完毕。



	Vec2 StickPoint;
    int kickId;

    GameOverLayer* gameOverLayer;

	EventListenerTouchOneByOne* touchListener;

public:
	CREATE_FUNC(BackgroundLayer);
	virtual bool init();
	virtual void Start(Ref* pSender);
	void bgMove(float);//背景的移动

	virtual void addStage();
	virtual void stageMove();
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);

	void addStick();
	void StickLength(float);
	void StopStick();
	void RotateStickAndGo();
	void stickCallBack(bool successFlag);
	void initStick();//隐藏stick
	void stopAudio(int audioId);
};

#endif /* BACKGROUNDLAYER_H_ */
