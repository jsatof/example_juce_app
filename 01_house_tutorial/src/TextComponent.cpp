#include "TextComponent.h"

TextComponent::TextComponent() {}

void TextComponent::paint(juce::Graphics& g) {
    juce::Font font = {"Amiga", "", 24.f};
    g.setFont(font);
    g.drawText("The Audio Programmer", 10, 10, 400, 60, juce::Justification::topLeft);
}

void TextComponent::resized() {}
