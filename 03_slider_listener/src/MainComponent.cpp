#include <MainComponent.h>

MainComponent::MainComponent() {
    setSize(600, 400);

    frequency_slider.setRange(50, 5000);
    frequency_slider.setTextValueSuffix(" Hz");
    frequency_slider.addListener(this);
    frequency_label.setText("Frequency", juce::NotificationType::dontSendNotification);
    frequency_label.attachToComponent(&frequency_slider, true);

    duration_slider.setRange(1.0 / frequency_slider.getMaximum(), 1.0 / frequency_slider.getMinimum());
    duration_slider.setTextValueSuffix(" s");
    duration_slider.addListener(this);
    duration_label.setText("Duration", juce::NotificationType::dontSendNotification);
    duration_label.attachToComponent(&duration_slider, true);

    // set an initial value, and trigger listeners
    frequency_slider.setValue(69.0);

    // make scale factor more logarithmic
    frequency_slider.setSkewFactorFromMidPoint(500.0);
    duration_slider.setSkewFactorFromMidPoint(0.003);

    // make text boxes have a clearer value
    frequency_slider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 120, frequency_slider.getTextBoxHeight());
    duration_slider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 120, duration_slider.getTextBoxHeight());


    addAndMakeVisible(frequency_slider);
    addAndMakeVisible(frequency_label);
    addAndMakeVisible(duration_slider);
    addAndMakeVisible(duration_label);
}

void MainComponent::sliderValueChanged(juce::Slider *slider) {
    if (slider == &frequency_slider) {
        duration_slider.setValue(1.0 / frequency_slider.getValue());
    } else if (slider == &duration_slider) {
        frequency_slider.setValue(1.0 / duration_slider.getValue());
    }
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int border = 120;


    duration_slider.setBounds(area);
    frequency_slider.setBounds(border, 20, getWidth() - border, 20);
    duration_slider.setBounds(border, 50, getWidth() - border, 50);
}
