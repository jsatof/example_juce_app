#include <MainComponent.h>

MainComponent::MainComponent() {
    setSize(600, 400);

    slider1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    slider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);

    slider2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    slider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);

    slider3.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    slider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);

    addAndMakeVisible(slider1);
    addAndMakeVisible(slider2);
    addAndMakeVisible(slider3);
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void MainComponent::resized() {
    int border = 10;

    juce::Rectangle<int> area = getLocalBounds();
    juce::Rectangle<int> sliderArea = area.removeFromTop(area.getHeight() / 2);

    slider1.setBounds(sliderArea.removeFromLeft(area.getWidth() / 2).reduced(border)); // reduced() removes 10px around the region
    slider2.setBounds(sliderArea.removeFromRight(area.getWidth() / 2));

    slider3.setBounds(area);
}
