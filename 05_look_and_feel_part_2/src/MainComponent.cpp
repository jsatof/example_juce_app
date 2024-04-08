#include <MainComponent.h>

CustomLookAndFeel::CustomLookAndFeel() {
    setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::ivory);
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::blanchedalmond);
    setColour(juce::Slider::thumbColourId, juce::Colours::black);
}

void CustomLookAndFeel::drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider) {
    float diameter = juce::jmin(width, height);
    float radius = diameter / 2;
    float center_x = float(x + width) / 2.f;
    float center_y = float(y + height) / 2.f;
    float rx = center_x - radius;
    float ry = center_y - radius;

    std::cout << rotaryStartAngle << '\t' << rotaryEndAngle << '\n';
    float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));

    juce::Rectangle<float> area = { rx, ry, diameter, diameter };
    g.setColour(juce::Colours::ivory);
    g.fillEllipse(area);

    g.setColour(juce::Colours::black);
    juce::Path dialTick;
    dialTick.addRectangle(0, -radius, 10.f, radius * 0.33f);
    g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(center_x, center_y));


    g.drawEllipse(rx, ry, diameter, diameter, 5.f);



}

MainComponent::MainComponent() {
    setSize(800, 600);

    dial1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial1.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);

    dial1.setLookAndFeel(&feel);

    addAndMakeVisible(dial1);
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void MainComponent::resized() {
    dial1.setBounds(getLocalBounds());
}
