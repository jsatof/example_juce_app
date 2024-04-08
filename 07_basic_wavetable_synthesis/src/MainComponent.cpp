#include <MainComponent.h>

MainComponent::MainComponent() {
    setSize(800, 600);

    if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio))
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

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    amplitude = 0.20;
    frequency = 440;
    phase = 0;
    increment = frequency * double(wavetable_size) / sampleRate;

    // one cycle of the sine wave
    for (size_t i = 0; i < wavetable_size; ++i) {
        wavetable.insert(i, std::sin(2.0 * juce::MathConstants<double>::pi * i / double(wavetable_size)));
    }
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) {
    float *const left = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float *const right = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

    for (int sample = 0; sample < bufferToFill.numSamples; ++sample) {
        left[sample] = wavetable[int(phase)] * amplitude;
        right[sample] = wavetable[int(phase)] * amplitude;
        phase = std::fmod((phase + increment), wavetable_size);
    }
}

void MainComponent::releaseResources() {}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {}

