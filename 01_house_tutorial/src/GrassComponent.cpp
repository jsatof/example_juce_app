#include "GrassComponent.h"

GrassComponent::GrassComponent() {}

void GrassComponent::paint(juce::Graphics& g) {
    g.setColour(juce::Colours::green);
    g.drawLine(10, 325, getWidth() - 10, 325, 10.f);
}

void GrassComponent::resized() {}
