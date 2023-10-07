project(MIDICatalinaBug VERSION 0.0.1)

juce_add_plugin(MIDICatalinaBug
        COMPANY_NAME "Eyal-Amir"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT TRUE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE EAex
        PLUGIN_CODE MIpl
        FORMATS VST3 Standalone
        PRODUCT_NAME "Catalina MIDI Bug")

target_sources(MIDICatalinaBug PRIVATE PluginProcessor.cpp)

juce_add_binary_data(MIDICatalinaBug_Resources SOURCES Funky.midi)
set_target_properties(MIDICatalinaBug PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

target_compile_definitions(MIDICatalinaBug
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(MIDICatalinaBug PRIVATE
        shared_plugin_helpers
        juce_audio_utils
        juce_recommended_config_flags
        juce_recommended_lto_flags
        juce_recommended_warning_flags
        MIDICatalinaBug_Resources)