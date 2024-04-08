cmake_minimum_required(VERSION 3.22)
project(lookAndFeelTutorial VERSION 0.1.0)

juce_add_plugin(lookAndFeelTutorial
    COMPANY_NAME James
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER JSF4
    PLUGIN_CODE Gapp
    FORMATS Standalone
    PRODUCT_NAME "lookAndFeelGUIApp"
)

set(lookAndFeelTutorial_SOURCES
        src/Main.cpp
        src/MainComponent.cpp)
        
target_sources(lookAndFeelTutorial
    PRIVATE
        ${lookAndFeelTutorial_SOURCES}
)

target_include_directories(lookAndFeelTutorial
    PRIVATE
        src
)

target_link_libraries(lookAndFeelTutorial
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(lookAndFeelTutorial
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=1
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:lookAndFeelTutorial,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:lookAndFeelTutorial,JUCE_VERSION>"
)

install(TARGETS lookAndFeelTutorial RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
