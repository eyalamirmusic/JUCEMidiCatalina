project(GuiAppExample VERSION 0.0.1)

juce_add_gui_app(GuiAppExample
        PRODUCT_NAME "GUI App Bug")

target_sources(GuiAppExample
        PRIVATE
        Main.cpp
        MainComponent.cpp)

target_compile_definitions(GuiAppExample
        PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:GuiAppExample,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:GuiAppExample,JUCE_VERSION>")

target_link_libraries(GuiAppExample
        PRIVATE
        MIDICatalinaBug_Resources
        juce::juce_gui_extra
        juce::juce_audio_utils
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
