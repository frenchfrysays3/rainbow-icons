#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void update(float dt) {
        // Call original update
        PlayerObject::update(dt);

        // 1. Get current time
        auto time = cocos2d::CCDirector::sharedDirector()->getTotalFrames() / 60.0f;
        
        // 2. Calculate hue
        float speed = 2.0f;
        float hue = fmod(time * speed * 60.0f, 360.0f);
        
        // 3. Corrected Namespace for Geode 4.x
        cocos2d::ccColor3B rainbowColor = geode::cocos::colorFromHSV(hue, 1.0f, 1.0f);

        // 4. Apply colors
        this->setColor(rainbowColor);
        this->setSecondColor(rainbowColor);

        if (this->m_hasGlow) {
            this->m_glowColor = rainbowColor;
            this->updateGlowColor();
        }
    }
}; // <--- Added the semicolon here