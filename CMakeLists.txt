#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required (VERSION 3.10)

project (azsphere_ext_library C)

azsphere_configure_tools(TOOLS_REVISION "21.07")
azsphere_configure_api(TARGET_API_SET "10")

# External Library Add
add_library(MyStaticLib STATIC delay.c)

# Create executable
add_executable (${PROJECT_NAME} main.c)

# add the external library to the "target_link_libraries" list
target_link_libraries (${PROJECT_NAME} MyStaticLib applibs pthread gcc_s c)

azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "HardwareDefinitions/mt3620_rdb" TARGET_DEFINITION "template_appliance.json")
azsphere_target_add_image_package(${PROJECT_NAME})
