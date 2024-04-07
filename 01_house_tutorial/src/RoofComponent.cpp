#include "RoofComponent.h"

RoofComponent::RoofComponent() {}

void RoofComponent::paint(juce::Graphics& g) {
    g.setColour(juce::Colours::red);
    juce::Path p;

    p.startNewSubPath(200, 190);
    p.lineTo(400, 190);
    p.lineTo(300, 140);
    p.closeSubPath();

    g.fillPath(p);
}

void RoofComponent::resized() {}
