#pragma once

#include <Geode/Geode.hpp>

class VoidMenu : public cocos2d::CCLayer {
public:
    static VoidMenu* create();
    bool init() override;

private:
    void onFPS(cocos2d::CCObject*);
    void onPractice(cocos2d::CCObject*);
    void onPerformance(cocos2d::CCObject*);
    void onVisuals(cocos2d::CCObject*);
    void onAbout(cocos2d::CCObject*);
};
