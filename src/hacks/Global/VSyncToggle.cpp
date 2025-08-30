#ifdef GEODE_IS_WINDOWS

#include <modules/config/config.hpp>
#include <modules/gui/gui.hpp>
#include <modules/gui/components/toggle.hpp>
#include <modules/hack/hack.hpp>

namespace eclipse::hacks::Global {
    class $hack(VSyncToggle) {
        void init() override {
            auto tab = gui::MenuTab::find("tab.global");
            tab->addToggle("global.vsync-toggle", "global.v-sync.toggle")
               ->handleKeybinds()
               ->setDescription()
               ->callback([](bool v) {
                   GameManager::sharedState()->setGameVariable("0030", v);
                   cocos2d::CCApplication::sharedApplication()->toggleVerticalSync(v);
               })->disableSaving();

            config::set("global.v-sync.toggle", vsync);
        }
        bool vsync = GameManager::sharedState()->getGameVariable("0030");
        config::setTemp("global.v-sync.toggle", vsync);
             
        [[nodiscard]] const char* getId() const override { return "V-Sync Toggle"; }
    };

    REGISTER_HACK(VSyncToggle)
}

#endif
