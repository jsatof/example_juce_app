#include <MainComponent.h>

CustomLookAndFeel::CustomLookAndFeel() {
    setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::chocolate);
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::blanchedalmond);
    setColour(juce::Slider::thumbColourId, juce::Colours::black);
}

MainComponent::MainComponent() {
    setSize(600, 400);

    dial1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);

    dial2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);

    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);

    dial1.setLookAndFeel(&feel);
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void MainComponent::resized() {
    const int border = 20;
    const int dialWidth = getWidth() / 2 - border;
    const int dialHeight = getHeight() - 100 - border;

    dial1.setBounds(border, border, dialWidth, dialHeight);
    dial2.setBounds(getWidth() / 2, border, dialWidth, dialHeight);
}
