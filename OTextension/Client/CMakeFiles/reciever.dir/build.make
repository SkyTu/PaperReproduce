# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/txy/PaperReproduce/OTextension/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/txy/PaperReproduce/OTextension/Client

# Include any dependencies generated for this target.
include CMakeFiles/reciever.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/reciever.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reciever.dir/flags.make

CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o: CMakeFiles/reciever.dir/flags.make
CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o: /home/txy/PaperReproduce/OTextension/PrimeGroup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/txy/PaperReproduce/OTextension/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o -c /home/txy/PaperReproduce/OTextension/PrimeGroup.cpp

CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/txy/PaperReproduce/OTextension/PrimeGroup.cpp > CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.i

CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/txy/PaperReproduce/OTextension/PrimeGroup.cpp -o CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.s

CMakeFiles/reciever.dir/reciever.cpp.o: CMakeFiles/reciever.dir/flags.make
CMakeFiles/reciever.dir/reciever.cpp.o: reciever.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/txy/PaperReproduce/OTextension/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reciever.dir/reciever.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/reciever.dir/reciever.cpp.o -c /home/txy/PaperReproduce/OTextension/Client/reciever.cpp

CMakeFiles/reciever.dir/reciever.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reciever.dir/reciever.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/txy/PaperReproduce/OTextension/Client/reciever.cpp > CMakeFiles/reciever.dir/reciever.cpp.i

CMakeFiles/reciever.dir/reciever.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reciever.dir/reciever.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/txy/PaperReproduce/OTextension/Client/reciever.cpp -o CMakeFiles/reciever.dir/reciever.cpp.s

# Object files for target reciever
reciever_OBJECTS = \
"CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o" \
"CMakeFiles/reciever.dir/reciever.cpp.o"

# External object files for target reciever
reciever_EXTERNAL_OBJECTS =

reciever: CMakeFiles/reciever.dir/home/txy/PaperReproduce/OTextension/PrimeGroup.cpp.o
reciever: CMakeFiles/reciever.dir/reciever.cpp.o
reciever: CMakeFiles/reciever.dir/build.make
reciever: CMakeFiles/reciever.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/txy/PaperReproduce/OTextension/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable reciever"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reciever.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reciever.dir/build: reciever

.PHONY : CMakeFiles/reciever.dir/build

CMakeFiles/reciever.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reciever.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reciever.dir/clean

CMakeFiles/reciever.dir/depend:
	cd /home/txy/PaperReproduce/OTextension/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/txy/PaperReproduce/OTextension/Client /home/txy/PaperReproduce/OTextension/Client /home/txy/PaperReproduce/OTextension/Client /home/txy/PaperReproduce/OTextension/Client /home/txy/PaperReproduce/OTextension/Client/CMakeFiles/reciever.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reciever.dir/depend
