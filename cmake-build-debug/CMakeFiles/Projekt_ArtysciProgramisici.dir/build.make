# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projekt_ArtysciProgramisici.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projekt_ArtysciProgramisici.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projekt_ArtysciProgramisici.dir/flags.make

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj: CMakeFiles/Projekt_ArtysciProgramisici.dir/flags.make
CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj: ../program/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj"
	C:\dev\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Projekt_ArtysciProgramisici.dir\program\main.cpp.obj -c C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\program\main.cpp

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.i"
	C:\dev\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\program\main.cpp > CMakeFiles\Projekt_ArtysciProgramisici.dir\program\main.cpp.i

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.s"
	C:\dev\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\program\main.cpp -o CMakeFiles\Projekt_ArtysciProgramisici.dir\program\main.cpp.s

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.requires:

.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.requires

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.provides: CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Projekt_ArtysciProgramisici.dir\build.make CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.provides

CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.provides.build: CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj


CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj: CMakeFiles/Projekt_ArtysciProgramisici.dir/flags.make
CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj: ../library/src/Repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj"
	C:\dev\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Projekt_ArtysciProgramisici.dir\library\src\Repository.cpp.obj -c C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\library\src\Repository.cpp

CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.i"
	C:\dev\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\library\src\Repository.cpp > CMakeFiles\Projekt_ArtysciProgramisici.dir\library\src\Repository.cpp.i

CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.s"
	C:\dev\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\library\src\Repository.cpp -o CMakeFiles\Projekt_ArtysciProgramisici.dir\library\src\Repository.cpp.s

CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.requires:

.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.requires

CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.provides: CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Projekt_ArtysciProgramisici.dir\build.make CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.provides.build
.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.provides

CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.provides.build: CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj


# Object files for target Projekt_ArtysciProgramisici
Projekt_ArtysciProgramisici_OBJECTS = \
"CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj" \
"CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj"

# External object files for target Projekt_ArtysciProgramisici
Projekt_ArtysciProgramisici_EXTERNAL_OBJECTS =

Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj
Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj
Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/build.make
Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/linklibs.rsp
Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/objects1.rsp
Projekt_ArtysciProgramisici.exe: CMakeFiles/Projekt_ArtysciProgramisici.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Projekt_ArtysciProgramisici.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projekt_ArtysciProgramisici.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projekt_ArtysciProgramisici.dir/build: Projekt_ArtysciProgramisici.exe

.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/build

CMakeFiles/Projekt_ArtysciProgramisici.dir/requires: CMakeFiles/Projekt_ArtysciProgramisici.dir/program/main.cpp.obj.requires
CMakeFiles/Projekt_ArtysciProgramisici.dir/requires: CMakeFiles/Projekt_ArtysciProgramisici.dir/library/src/Repository.cpp.obj.requires

.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/requires

CMakeFiles/Projekt_ArtysciProgramisici.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projekt_ArtysciProgramisici.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/clean

CMakeFiles/Projekt_ArtysciProgramisici.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug C:\Users\Bartek\Documents\GitHub\Projekt_ArtysciProgramisici\cmake-build-debug\CMakeFiles\Projekt_ArtysciProgramisici.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projekt_ArtysciProgramisici.dir/depend

