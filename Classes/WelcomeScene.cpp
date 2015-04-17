/*
 * WelcomeScene.cpp
 *
 *  Created on: 2015年4月11日
 *      Author: Administrator
 */

#include "WelcomeScene.h"
#include "BackgroundLayer.h"
#include "jni.h"
#include "../platform/android/jni/JniHelper.h"
USING_NS_CC;
bool WelcomeScene::init(){
	if(!Scene::init()){
		return false;
	}



	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed=CC_CALLBACK_2(WelcomeScene::onKeyPressed,this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(WelcomeScene::onKeyReleased,this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
     _eventDispatcher->addEventListenerWithFixedPriority(keyBoardListener,1);
	auto background = BackgroundLayer::create();

	this->addChild(background);

	return true;
}

void WelcomeScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event){

	/*log("WelcomeScene::onKeyPressed");
	if(keyCode == EventKeyboard::KeyCode::KEY_BACK){
		JniMethodInfo jmi ;
		bool isHave = JniHelper::getStaticMethodInfo(jmi,"org/cocos2dx.cpp/AppActivity","exitGame","()V");

		if (isHave) {
			log("%s","find success");
			jmi.env->CallStaticVoidMethod(jmi.classID, jmi.methodID);
		}else{
			log("%s","find failed");
		}
	}*/
}
void WelcomeScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event){

	if(keyCode == EventKeyboard::KeyCode::KEY_BACK){
			JniMethodInfo jmi ;
			bool isHave = JniHelper::getStaticMethodInfo(jmi,"org/cocos2dx.cpp/AppActivity","exitGame","()V");

			if (isHave) {
				log("%s","find success");
				jmi.env->CallStaticVoidMethod(jmi.classID, jmi.methodID);
			}else{
				log("%s","find failed");
			}
		}
}
WelcomeScene::WelcomeScene() {
}

WelcomeScene::~WelcomeScene() {
}

