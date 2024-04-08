#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::AudioAppComponent, juce::Slider::Listener {
public:
    MainComponent();
    ~MainComponent() override;

    void sliderValueChanged(juce::Slider *slider) override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    juce::Slider frequency_slider;
    juce::Label frequency_label;
    juce::Slider amplitude_slider;
    juce::Label amplitude_label;

    juce::Array<float> wavetable;
    size_t wavetable_size;
    double frequency;
    double phase;
    double increment;
    float amplitude;
    double current_sample_rate;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
