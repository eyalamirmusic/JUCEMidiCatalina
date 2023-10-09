#include "MainComponent.h"
#include <BinaryData.h>
#include <juce_audio_utils/juce_audio_utils.h>

//==============================================================================
MainComponent::MainComponent()
{
    juce::MidiFile f;
    auto stream = juce::MemoryInputStream(
        BinaryData::Funky_midi, BinaryData::Funky_midiSize, false);

    f.readFrom(stream);

    setSize(600, 400);
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setFont(juce::Font(16.0f));
    g.setColour(juce::Colours::white);
    g.drawText("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
