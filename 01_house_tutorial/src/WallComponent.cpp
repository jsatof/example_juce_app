#include "WallComponent.h"

WallComponent::WallComponent() {}

void WallComponent::paint(juce::Graphics& g) {
    juce::Rectangle<float> rect = { 200, 200, 200, 120 };
    g.fillCheckerBoard(rect, 20, 10, juce::Colours::sandybrown, juce::Colours::saddlebrown);
}

void WallComponent::resized() {}
