cmake_minimum_required(VERSION 3.22)
project(basicWavetableSynthesisTutorial VERSION 0.1.0)

juce_add_plugin(basicWavetableSynthesisTutorial
    COMPANY_NAME James
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER JSF4
    PLUGIN_CODE Gapp
    FORMATS Standalone
    PRODUCT_NAME "basicWavetableSynthesisTutorial"
)

file(GLOB JUCE_LIBRARY_SOURCES JuceLibraryCode/*.cpp)

set(basicWavetableSynthesisTutorial_SOURCES
    ${JUCE_LIBRARY_SOURCES}
    src/Main.cpp
    src/MainComponent.cpp)
        
target_sources(basicWavetableSynthesisTutorial
    PRIVATE
        ${basicWavetableSynthesisTutorial_SOURCES}
)

target_include_directories(basicWavetableSynthesisTutorial
    PRIVATE
        src
        JuceLibraryCode
)

target_link_libraries(basicWavetableSynthesisTutorial
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(basicWavetableSynthesisTutorial
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=1
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:basicWavetableSynthesisTutorial,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:basicWavetableSynthesisTutorial,JUCE_VERSION>"
)

install(TARGETS basicWavetableSynthesisTutorial RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
