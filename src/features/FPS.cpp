#include "FPS.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace VoidDash {

void initializeFPS() {
    auto fps = Mod::get()->getSettingValue<int64_t>("fps-cap");

    log::info("VoidDash FPS target: {}", fps);
}

}
