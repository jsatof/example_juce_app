#include "MainComponent.h"

MainComponent::MainComponent() {
    setSize(600, 400);
    addAndMakeVisible(m_wall);
    addAndMakeVisible(m_grass);
    addAndMakeVisible(m_roof);
    addAndMakeVisible(m_sun);
    addAndMakeVisible(m_text);
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::skyblue);
}

void MainComponent::resized() {
    m_wall.setBounds(getLocalBounds());
    m_grass.setBounds(getLocalBounds());
    m_roof.setBounds(getLocalBounds());
    m_sun.setBounds(getLocalBounds());
    m_text.setBounds(getLocalBounds());
}
