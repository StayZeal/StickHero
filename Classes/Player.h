/*
 * Player.h
 *
 *  Created on: 2015年4月11日
 *      Author: Administrator
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "cocos2d.h"
USING_NS_CC;

class Player{
private:
	Sprite* _player;
	Animation* WalkAnimation;
	Animation* StayAnimation;
	Animate* WalkAnimate;
	Animate* StayAnimate;
public:
	bool init();
	Sprite* getPlayer();
	//CREATE_FUNC(Player);
	void SetPosition(Vec2);
	void Walk(Vec2);
	void Stay();
	void Stop();
	void Start(Vec2);

};

#endif /* PLAYER_H_ */
