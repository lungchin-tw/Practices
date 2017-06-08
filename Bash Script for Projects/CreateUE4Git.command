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
git config http.postBuffer 524288000
## git config --global core.compressoin 0
git clone https://github.com/EpicGames/UnrealEngine.git
## git clone --depth 1 https://github.com/EpicGames/UnrealEngine.git
## cd UnrealEngine
## git fetch --unshallow
## git fetch --depth=2147483647
## git pull --all
