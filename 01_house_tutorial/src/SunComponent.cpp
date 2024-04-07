#include "SunComponent.h"

SunComponent::SunComponent() {}

void SunComponent::paint(juce::Graphics& g) {
    g.setColour(juce::Colours::yellow);
    g.drawEllipse(400.f, 50.f, 50.f, 50.f, 10.f);
}

void SunComponent::resized() {}
