#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT=PrototypeProject
UE4_SOURCE_FOLDER=/Users/$USER/Documents/UnrealEngine-4.15
EDITOR=$UE4_SOURCE_FOLDER/Engine/Binaries/Mac/UE4Editor.app//Contents/MacOS/UE4Editor


$EDITOR $CUR_FOLDER/$PROJECT.uproject -run=cook -CookAll targetplatform=MacServer+MacNoEditor+Mac+IOS -NumCookersToSpawn=2 -Compressed -abslog=$CUR_FOLDER/Cook.log