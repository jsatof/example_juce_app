#include <MainComponent.h>

MainComponent::MainComponent() {
    setSize(800, 600);

    frequency_slider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    frequency_slider.setRange(50.0, 500.0);
    frequency_slider.addListener(this);
    frequency_slider.setValue(440.0);
    frequency_slider.setTextValueSuffix("Hz");
    addAndMakeVisible(frequency_slider);

    frequency_label.setText("Frequency", juce::NotificationType::dontSendNotification);
    frequency_label.attachToComponent(&frequency_slider, true);
    addAndMakeVisible(frequency_label);

    amplitude_slider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    amplitude_slider.setRange(0.0, 1.0);
    amplitude_slider.addListener(this);
    amplitude_slider.setValue(0.20);
    amplitude_slider.setTextValueSuffix("");
    addAndMakeVisible(amplitude_slider);

    amplitude_label.setText("Volume", juce::NotificationType::dontSendNotification);
    amplitude_label.attachToComponent(&amplitude_slider, true);
    addAndMakeVisible(amplitude_label);

    if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio)
        && !juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request(juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels(granted ? 2 : 0, 2); });
    } else {
        setAudioChannels(2, 2);
    }
}

MainComponent::~MainComponent() {
    shutdownAudio();
}

void MainComponent::sliderValueChanged(juce::Slider *slider) {
    if (slider == &frequency_slider) {
        frequency = frequency_slider.getValue();
    } else if (slider == &amplitude_slider) {
        amplitude = amplitude_slider.getValue();
    }
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    amplitude = amplitude_slider.getValue();
    frequency = frequency_slider.getValue();
    phase = 0;
    current_sample_rate = sampleRate;

    // one cycle of the sine wave
    for (size_t i = 0; i < wavetable_size; ++i) {
        wavetable.insert(i, std::sin(-2.0 * juce::MathConstants<double>::pi * i / double(wavetable_size)));
    }
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) {
    float *const left = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float *const right = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

    for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
        left[sample] = wavetable[int(phase)] * amplitude;
        right[sample] = wavetable[int(phase)] * amplitude;

        increment = frequency * double(wavetable_size) / current_sample_rate;
        phase = std::fmod((phase + increment), wavetable_size);
    }
}

void MainComponent::releaseResources() {}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    const int label_space = 100;
    frequency_slider.setBounds(label_space, 20, getWidth() - label_space, 20);
    amplitude_slider.setBounds(label_space, 50, getWidth() - label_space, 50);
}

