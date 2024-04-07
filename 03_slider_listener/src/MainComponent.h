#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include <juce_gui_extra/juce_gui_extra.h>

class MainComponent final : public juce::Component, juce::Slider::Listener {
public:
    MainComponent();

    void paint(juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider *slider) override;

private:
    juce::Slider frequency_slider;
    juce::Label frequency_label;

    juce::Slider duration_slider;
    juce::Label duration_label;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
