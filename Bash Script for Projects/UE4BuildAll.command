#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

## Build Xcode Project
cd $CUR_FOLDER
xcodebuild -scheme "BlankProgram"
xcodebuild -scheme "CrossCompilerTool"
xcodebuild -scheme "UnrealVersionSelector"
xcodebuild -scheme "UE4EditorServices"
xcodebuild -scheme "ShaderCompileWorker"
xcodebuild -scheme "UE4" -configuration "Development Editor" build
xcodebuild -scheme "UE4" -configuration "Debug Editor" build
