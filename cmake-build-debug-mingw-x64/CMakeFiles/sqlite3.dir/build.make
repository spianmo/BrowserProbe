# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\BrowserProbe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64

# Include any dependencies generated for this target.
include CMakeFiles/sqlite3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/sqlite3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sqlite3.dir/flags.make

CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj: CMakeFiles/sqlite3.dir/flags.make
CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj: CMakeFiles/sqlite3.dir/includes_C.rsp
CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj: ../vendor/sqlite3/sqlite3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sqlite3.dir\vendor\sqlite3\sqlite3.c.obj -c D:\CLionProjects\BrowserProbe\vendor\sqlite3\sqlite3.c

CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\BrowserProbe\vendor\sqlite3\sqlite3.c > CMakeFiles\sqlite3.dir\vendor\sqlite3\sqlite3.c.i

CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionProjects\BrowserProbe\vendor\sqlite3\sqlite3.c -o CMakeFiles\sqlite3.dir\vendor\sqlite3\sqlite3.c.s

# Object files for target sqlite3
sqlite3_OBJECTS = \
"CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj"

# External object files for target sqlite3
sqlite3_EXTERNAL_OBJECTS =

libsqlite3.a: CMakeFiles/sqlite3.dir/vendor/sqlite3/sqlite3.c.obj
libsqlite3.a: CMakeFiles/sqlite3.dir/build.make
libsqlite3.a: CMakeFiles/sqlite3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsqlite3.a"
	$(CMAKE_COMMAND) -P CMakeFiles\sqlite3.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sqlite3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sqlite3.dir/build: libsqlite3.a
.PHONY : CMakeFiles/sqlite3.dir/build

CMakeFiles/sqlite3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sqlite3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sqlite3.dir/clean

CMakeFiles/sqlite3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\BrowserProbe D:\CLionProjects\BrowserProbe D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64 D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64 D:\CLionProjects\BrowserProbe\cmake-build-debug-mingw-x64\CMakeFiles\sqlite3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sqlite3.dir/depend

