cmake_minimum_required(VERSION 3.22)
project(exampleGUIApp VERSION 0.1.0)

juce_add_plugin(exampleGUIApp
    COMPANY_NAME James
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER JSF4
    PLUGIN_CODE Gapp
    FORMATS Standalone
    PRODUCT_NAME "Example GUI App"
)

set(exampleGUIApp_SOURCES
        src/Main.cpp
        src/MainComponent.cpp)

target_sources(exampleGUIApp
    PRIVATE
        ${exampleGUIApp_SOURCES}
)

target_include_directories(exampleGUIApp
    PRIVATE
        include
)

target_link_libraries(exampleGUIApp
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(exampleGUIApp
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=1
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:exampleGUIApp,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:exampleGUIApp,JUCE_VERSION>"
)

install(TARGETS exampleGUIApp RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
