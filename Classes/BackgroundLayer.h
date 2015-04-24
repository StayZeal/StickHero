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
	static const int STICK_SPEED = 2;//棍子增长的速度，即游戏的难度；
	static const int BG_SPEED = 50;
	bool isStart;
	Size MyWinSize;
	Menu* menu;
	Sprite* GameName;
	Sprite* Image_One;
	Sprite* Image_Two;
	Sprite* stageSprite[3];
	int stageNumber;//初始值设为1
	int NowStage;//player所在的stage
	int LastStage;//player所在前一个stage
	int NextStage;//player将要走到的stage
/*
	int stageNumber=1;//初始值设为1
	int NowStage=0;//player所在的stage
	int LastStage=2;//player所在前一个stage
	int NextStage=1;//player将要走到的stage
*/
	Player* player;
	Sprite* stick;
	double TouchLength;//用来存储我们棍子的长度
	double DestLengthMin;
	double DestLengthMax;
    int scoreCount;
	bool successFlag;//true表示player能够成功移动到下一个梯子
	bool moveComplete;//true表示移动到下一个平台动作完毕。
	Label* scoreTitle;//记录分数


	Vec2 StickPoint;
    int kickId;

    GameOverLayer* gameOverLayer;

	EventListenerTouchOneByOne* touchListener;

public:
	BackgroundLayer();
	CREATE_FUNC(BackgroundLayer);
	bool init();
	void Start(Ref* pSender);
	void bgMove(float);//背景的移动

	void addStage();
	void stageMove();
	bool onTouchBegan(Touch* pTouch, Event* pEvent);
	void onTouchMoved(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);

	void addStick();
	void StickLength(float);
	void StopStick();
	void RotateStickAndGo();
	void stickCallBack(bool successFlag);
	void initStick();//隐藏stick
	void stopAudio(int audioId);
	void gameOver();
};

#endif /* BACKGROUNDLAYER_H_ */
