/*
 * GameOverLayer.h
 *
 *  Created on: 2015年4月15日
 *      Author: Administrator
 */

#ifndef GAMEOVERLAYER_H_
#define GAMEOVERLAYER_H_
#include "cocos2d.h"
class GameOverLayer : public cocos2d::Layer{
public:
	GameOverLayer();
	virtual ~GameOverLayer();
	virtual bool init();
	CREATE_FUNC(GameOverLayer);
	void reStart();
	void home();
};

#endif /* GAMEOVERLAYER_H_ */
