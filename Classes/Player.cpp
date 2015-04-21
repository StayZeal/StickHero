/*
 * Player.cpp
 *
 *  Created on: 2015年4月11日
 *      Author: Administrator
 */

#include "Player.h"
USING_NS_CC;

bool Player::init() {

	_player = Sprite::create("res/image/anim1/stay1.png");
	_player->setAnchorPoint(Vec2(0.5, 0));

	Vector<SpriteFrame*> frameVector;
	for (int i = 1; i <= 5; i++) {

		char pngName[260] = { 0 };
		sprintf(pngName, "res/image/anim1/stay%d.png", i);
		frameVector.pushBack(SpriteFrame::create(pngName, Rect(0, 0, 54, 58)));

	}
	StayAnimation = Animation::createWithSpriteFrames(frameVector, 0.1);
	StayAnimation->setRestoreOriginalFrame(false);
	StayAnimation->setLoops(10000);
	StayAnimate = Animate::create(StayAnimation);

	StayAnimate->retain();

	//2
	frameVector.clear();
	for (int i = 1; i <= 5; i++) {

		char pngName[260] = { 0 };
		sprintf(pngName, "res/image/anim1/walk%d.png", i);
		frameVector.pushBack(SpriteFrame::create(pngName, Rect(0, 0, 54, 58)));
	}
	WalkAnimation = Animation::createWithSpriteFrames(frameVector, 1);
	WalkAnimation->setRestoreOriginalFrame(false);
	WalkAnimation->setLoops(10000);
	WalkAnimate = Animate::create(WalkAnimation);


	/**
	 * 在析构函数中进行释放，否则会被自动释放；导致空指针
	 */
	WalkAnimate->retain();

	return true;
}

//3
void Player::SetPosition(Vec2 _pos) {
	log("%s","Player::SetPosition()");
	_player->setPosition(_pos);
}

//4
void Player::Stay() {
	//_player->runAction(WalkAnimate);
	_player->runAction(StayAnimate);
}
//5
void Player::Stop() {
	_player->stopAllActions();
}
//6
void Player::Walk( ) {
	log("Player::Walk start");
	/* MoveTo* move = MoveTo::create(0.2, _dec);
	_player->runAction(move);*/
	_player->runAction(WalkAnimate);
	log("Player::Walk end");
}
//7
void Player::Start(Vec2 _dec) {
	MoveTo* move = MoveTo::create(0.2f, _dec);
	_player->runAction(move);
}

Sprite* Player::getPlayer() {
	return _player;
}

Animate* Player::getWalkAnimate(){

	log("Player::getWalkAnimate()");
	if(WalkAnimate!=nullptr){
		log("WalkAnimate is not null");
		return WalkAnimate;
	}else{
		log("WalkAnimate is null");
		return nullptr;
	}
}
Animate* Player::getStayAnimate(){

	return StayAnimate;
}
Player::~Player(){
	StayAnimate->release();
	WalkAnimate->release();
}



