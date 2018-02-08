//
//  TestScene.cpp
//  cocos2d_project
//
//  Created by developer on 2/8/18.
//
//

#include "TestScene.hpp"
#include "spine/SkeletonAnimation.h"


USING_NS_CC;
using namespace std;

cocos2d::Scene* TestScene::createScene()
{
    return TestScene::create();
}

bool TestScene::init()
{
    
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    const string json="spineboy-ess.json";
    const string altas="spineboy.atlas";

    auto skeletonNode =spine::SkeletonAnimation::createWithJsonFile(json,altas,0.2f);
    skeletonNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    skeletonNode->setAnimation(0, "run", true);//true是指循环播放walk动作
    this->addChild(skeletonNode);
    return true;
}

void TestScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
