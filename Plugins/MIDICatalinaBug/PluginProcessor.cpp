#include <shared_plugin_helpers/shared_plugin_helpers.h>
#include <BinaryData.h>

struct CatalinaMIDIBug : PluginHelpers::ProcessorBase
{
    CatalinaMIDIBug()
    {
        juce::MidiFile f;
        auto stream = juce::MemoryInputStream(
            BinaryData::Funky_midi, BinaryData::Funky_midiSize, false);

        f.readFrom(stream);
    }

    void processBlock(juce::AudioBuffer<float>& buffer,
                      juce::MidiBuffer& midiMessages) override
    {
        juce::ignoreUnused(midiMessages);
        buffer.clear();
    }
};

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CatalinaMIDIBug();
}
