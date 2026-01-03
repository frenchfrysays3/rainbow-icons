#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void update(float dt) {
        PlayerObject::update(dt);

        // 1. Get time safely
        auto time = cocos2d::CCDirector::sharedDirector()->getTotalFrames() / 60.0f;
        
        // 2. Calculate rainbow
        float speed = 2.0f;
        float hue = fmod(time * speed * 60.0f, 360.0f);
        cocos2d::ccColor3B rainbowColor = geode::cocos::colorFromHSV(hue, 1.0f, 1.0f);

        // 3. Use the public functions to set colors (safest for all platforms)
        this->setColor(rainbowColor);
        this->setSecondColor(rainbowColor);
        
        // Glow is often the part that crashes the build
        // For now, let's keep it simple to ensure it builds!
    }
};