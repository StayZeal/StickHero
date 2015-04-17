/*
 * GameOverLayer.cpp
 *
 *  Created on: 2015年4月15日
 *      Author: Administrator
 */

#include "GameOverLayer.h"
#include "WelcomeScene.h"
USING_NS_CC;
bool GameOverLayer::init(){

	if(!Layer::init()){
		return false;
	}

	Size  MyWinSize = Director::getInstance()->getVisibleSize();

	MenuItemSprite *reStartBtn = MenuItemSprite::create(Sprite::create("res/image/uires_5.png"),
			Sprite::create("res/image/uires_5.png"),
			NULL,
			CC_CALLBACK_0(GameOverLayer::reStart,this)
			);
	MenuItemSprite * homeBtn = MenuItemSprite::create(Sprite::create("res/image/uires_8.png"),
			Sprite::create("res/image/uires_8.png"),
			NULL,
			CC_CALLBACK_0(GameOverLayer::home,this)
			);

	reStartBtn->setPosition(MyWinSize.width/2+reStartBtn->getContentSize().width/2,MyWinSize.height/2 +8);
	homeBtn->setPosition(MyWinSize.width/2-homeBtn->getContentSize().width/2,MyWinSize.height/2 +8);
	Menu *menu = Menu::create(reStartBtn,homeBtn,NULL);
	menu->setPosition(0,0);
	this->addChild(menu);
	return true;
}

void GameOverLayer::reStart(){

	log("GameOverLayer::reStart()");
	WelcomeScene* sence  = WelcomeScene::create();
	TransitionFade *trans = TransitionFade::create(0.2f,sence);
	Director::getInstance()->replaceScene(trans);
}

void GameOverLayer::home(){

	log("GameOverLayer::home");
}
GameOverLayer::GameOverLayer() {
}

GameOverLayer::~GameOverLayer() {
}

