cmake_minimum_required(VERSION 3.22)
project(lookAndFeelTutorialPart2 VERSION 0.1.0)

juce_add_plugin(lookAndFeelTutorialPart2
    COMPANY_NAME James
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER JSF4
    PLUGIN_CODE Gapp
    FORMATS Standalone
    PRODUCT_NAME "lookAndFeelGUIApp2"
)

set(lookAndFeelTutorialPart2_SOURCES
        src/Main.cpp
        src/MainComponent.cpp)
        
target_sources(lookAndFeelTutorialPart2
    PRIVATE
        ${lookAndFeelTutorialPart2_SOURCES}
)

target_include_directories(lookAndFeelTutorialPart2
    PRIVATE
        src
)

target_link_libraries(lookAndFeelTutorialPart2
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(lookAndFeelTutorialPart2
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=1
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:lookAndFeelTutorialPart2,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:lookAndFeelTutorialPart2,JUCE_VERSION>"
)

install(TARGETS lookAndFeelTutorialPart2 RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
