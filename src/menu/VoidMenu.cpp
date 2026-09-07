#include "VoidMenu.hpp"

using namespace geode::prelude;

VoidMenu* VoidMenu::create() {
    auto ret = new VoidMenu();

    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool VoidMenu::init() {
    if (!CCLayer::init())
        return false;

    auto size = CCDirector::sharedDirector()->getWinSize();

    auto background = CCLayerColor::create(
        ccc4(12, 12, 18, 245)
    );

    background->setContentSize({320.f, 400.f});
    background->setPosition({
        (size.width - 320.f) / 2.f,
        (size.height - 400.f) / 2.f
    });

    this->addChild(background);

    auto title = CCLabelBMFont::create(
        "VOID DASH",
        "bigFont.fnt"
    );

    title->setScale(.7f);
    title->setPosition({160.f, 365.f});
    background->addChild(title);

    auto menu = CCMenu::create();
    menu->setPosition({160.f, 205.f});
    background->addChild(menu);

    auto makeButton = [&](char const* text,
                          SEL_MenuHandler callback) {
        auto label = CCLabelBMFont::create(
            text,
            "goldFont.fnt"
        );

        label->setScale(.65f);

        auto button = CCMenuItemLabel::create(
            label,
            this,
            callback
        );

        menu->addChild(button);
    };

    makeButton("FPS", menu_selector(VoidMenu::onFPS));
    makeButton("Practice", menu_selector(VoidMenu::onPractice));
    makeButton("Performance", menu_selector(VoidMenu::onPerformance));
    makeButton("Visuals", menu_selector(VoidMenu::onVisuals));
    makeButton("About", menu_selector(VoidMenu::onAbout));

    menu->alignItemsVerticallyWithPadding(14.f);

    auto credit = CCLabelBMFont::create(
        "Code assistance: ChatGPT",
        "chatFont.fnt"
    );

    credit->setScale(.55f);
    credit->setPosition({160.f, 22.f});
    background->addChild(credit);

    return true;
}

void VoidMenu::onFPS(CCObject*) {
    log::info("FPS menu opened");
}

void VoidMenu::onPractice(CCObject*) {
    log::info("Practice menu opened");
}

void VoidMenu::onPerformance(CCObject*) {
    log::info("Performance menu opened");
}

void VoidMenu::onVisuals(CCObject*) {
    log::info("Visual menu opened");
}

void VoidMenu::onAbout(CCObject*) {
    log::info("VoidDash");
    log::info("Geometry Dash 2.2081");
    log::info("Code assistance: ChatGPT");
}
