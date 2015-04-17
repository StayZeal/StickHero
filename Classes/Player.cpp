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

	//2
	frameVector.clear();
	for (int i = 1; i <= 5; i++) {

		char pngName[260] = { 0 };
		sprintf(pngName, "walk%d.png", i);
		frameVector.pushBack(SpriteFrame::create(pngName, Rect(0, 0, 54, 58)));
	}
	WalkAnimation = Animation::createWithSpriteFrames(frameVector, 1);
	WalkAnimation->setRestoreOriginalFrame(false);
	WalkAnimation->setLoops(10000);
	WalkAnimate = Animate::create(WalkAnimation);

	return true;
}

//3
void Player::SetPosition(Vec2 _pos) {
	log("%s","Player::SetPosition()");
	_player->setPosition(_pos);
}

//4
void Player::Stay() {
	_player->runAction(StayAnimate);
}
//5
void Player::Stop() {
	_player->stopAllActions();
}
//6
void Player::Walk(Vec2 _dec) {
	log("Player::Walk");
	MoveTo* move = MoveTo::create(1.5f, _dec);
	_player->runAction(move);
}
//7
void Player::Start(Vec2 _dec) {
	MoveTo* move = MoveTo::create(0.2f, _dec);
	_player->runAction(move);
}

Sprite* Player::getPlayer() {
	return _player;
}




