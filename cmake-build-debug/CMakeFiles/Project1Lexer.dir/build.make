# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project1Lexer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project1Lexer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project1Lexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project1Lexer.dir/flags.make

CMakeFiles/Project1Lexer.dir/main.cpp.obj: CMakeFiles/Project1Lexer.dir/flags.make
CMakeFiles/Project1Lexer.dir/main.cpp.obj: CMakeFiles/Project1Lexer.dir/includes_CXX.rsp
CMakeFiles/Project1Lexer.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Project1Lexer.dir/main.cpp.obj: CMakeFiles/Project1Lexer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project1Lexer.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1Lexer.dir/main.cpp.obj -MF CMakeFiles\Project1Lexer.dir\main.cpp.obj.d -o CMakeFiles\Project1Lexer.dir\main.cpp.obj -c "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\main.cpp"

CMakeFiles/Project1Lexer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1Lexer.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\main.cpp" > CMakeFiles\Project1Lexer.dir\main.cpp.i

CMakeFiles/Project1Lexer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1Lexer.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\main.cpp" -o CMakeFiles\Project1Lexer.dir\main.cpp.s

# Object files for target Project1Lexer
Project1Lexer_OBJECTS = \
"CMakeFiles/Project1Lexer.dir/main.cpp.obj"

# External object files for target Project1Lexer
Project1Lexer_EXTERNAL_OBJECTS =

Project1Lexer.exe: CMakeFiles/Project1Lexer.dir/main.cpp.obj
Project1Lexer.exe: CMakeFiles/Project1Lexer.dir/build.make
Project1Lexer.exe: CMakeFiles/Project1Lexer.dir/linklibs.rsp
Project1Lexer.exe: CMakeFiles/Project1Lexer.dir/objects1.rsp
Project1Lexer.exe: CMakeFiles/Project1Lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project1Lexer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project1Lexer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project1Lexer.dir/build: Project1Lexer.exe
.PHONY : CMakeFiles/Project1Lexer.dir/build

CMakeFiles/Project1Lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project1Lexer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project1Lexer.dir/clean

CMakeFiles/Project1Lexer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer" "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer" "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug" "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug" "C:\Users\coler\OneDrive\Documents\BYU Summer 2022\CS 236\Project1Lexer\cmake-build-debug\CMakeFiles\Project1Lexer.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project1Lexer.dir/depend

