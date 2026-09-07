#include "Performance.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace VoidDash {

void initializePerformance() {
    bool lowMemory =
        Mod::get()->getSettingValue<bool>("low-memory");

    if (lowMemory) {
        log::info("VoidDash Low Memory Mode: ON");
    }
}

}
