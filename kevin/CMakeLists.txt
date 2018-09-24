# BASIC PROJECT SETTINGS
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(ACE)

#----------------------------------------------------------------------------

# SET C++ STANDARD (REQUIRED BY ROOT)
set(CMAKE_CXX_STANDARD 14)

#----------------------------------------------------------------------------

# FIND GEANT4
find_package(Geant4 REQUIRED ui_all vis_all)

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)

#----------------------------------------------------------------------------

# INCLUDES
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIRS})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)


#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(ACE src/ACE.cc ${sources} ${headers})
target_link_libraries(ACE ${Geant4_LIBRARIES} ${ROOT_LIBRARIES} )
#target_link_libraries(ACE ${Geant4_LIBRARIES} $(root-config --libdir) )

#----------------------------------------------------------------------------


# LINK AGAINST Geant4
#target_link_libraries(ACE ${Geant4_LIBRARIES})
