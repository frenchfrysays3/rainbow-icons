#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
	void update(float dt) {
		// Call the original update function so the game doesn't break
		PlayerObject::update(dt);

		// 1. Get the current time from the global director
        auto time = cocos2d::CCDirector::sharedDirector()->getTotalFrames() / 60.0f;
        
        // 2. Calculate the Rainbow color
        // Speed: multiply 'time' by a higher number for faster rainbow
        float speed = 2.0f;
        float hue = fmod(time * speed * 60.0f, 360.0f);
        
        // 3. Convert HSV to a color Geometry Dash understands (ccColor3B)
        // We use a Geode helper for this!
        cocos2d::ccColor3B rainbowColor = geode::utils::cocos::colorFromHSV(hue, 1.0f, 1.0f);

        // 4. Apply the color to the player
        // This covers both Primary and Secondary colors
        this->setColor(rainbowColor);
        this->setSecondColor(rainbowColor);

        // Optional: If you want the glow to be rainbow too
        if (this->m_hasGlow) {
            this->m_glowColor = rainbowColor;
            this->updateGlowColor();
        }
	}
}