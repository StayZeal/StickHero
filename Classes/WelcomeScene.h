/*
 * WelcomeScene.h
 *
 *  Created on: 2015年4月11日
 *      Author: Administrator
 */

#ifndef WELCOMESCENE_H_
#define WELCOMESCENE_H_
#include "cocos2d.h"
USING_NS_CC;
class WelcomeScene : public Scene {
public:
	WelcomeScene();
	virtual ~WelcomeScene();
	virtual bool init(); //在对象使用Create()方法时回调用这个函数，所以它的作用就是初始化这个对象，因为二义性问题，所以一定要记得加上virtual关键字。
	CREATE_FUNC(WelcomeScene); //这是引擎为每一个节点实现Create()方法而定义的一个宏指令。
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event);
};

#endif /* WELCOMESCENE_H_ */
