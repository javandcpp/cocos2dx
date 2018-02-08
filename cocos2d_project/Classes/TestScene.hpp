//
//  TestScene.hpp
//  cocos2d_project
//
//  Created by developer on 2/8/18.
//
//

#ifndef TestScene_hpp
#define TestScene_hpp

#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
#include <stdio.h>

class TestScene:public cocos2d::Scene{
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestScene);

};

#endif /* TestScene_hpp */
