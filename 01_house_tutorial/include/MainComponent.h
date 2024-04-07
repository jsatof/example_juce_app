#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include <juce_gui_extra/juce_gui_extra.h>
#include <WallComponent.h>
#include <GrassComponent.h>
#include <RoofComponent.h>
#include <SunComponent.h>
#include <TextComponent.h>

class MainComponent final : public juce::Component {
public:
    MainComponent();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    WallComponent m_wall;
    GrassComponent m_grass;
    RoofComponent m_roof;
    SunComponent m_sun;
    TextComponent m_text;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
