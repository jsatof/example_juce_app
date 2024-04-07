cmake_minimum_required(VERSION 3.22)
project(houseTutorial VERSION 0.1.0)

juce_add_plugin(houseTutorial
    COMPANY_NAME James
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER JSF4
    PLUGIN_CODE Gapp
    FORMATS Standalone
    PRODUCT_NAME "House GUI App"
)

set(houseTutorial_SOURCES
        src/Main.cpp
        src/MainComponent.cpp
        src/GrassComponent.cpp
        src/RoofComponent.cpp
        src/SunComponent.cpp
        src/TextComponent.cpp
        src/WallComponent.cpp)

target_sources(houseTutorial
    PRIVATE
        ${houseTutorial_SOURCES}
)

target_include_directories(houseTutorial
    PRIVATE
        include
)

target_link_libraries(houseTutorial
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_compile_definitions(houseTutorial
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_USE_CUSTOM_PLUGIN_STANDALONE_APP=1
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:houseTutorial,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:houseTutorial,JUCE_VERSION>"
)

install(TARGETS houseTutorial RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
