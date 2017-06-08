#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
UE4_SOURCE_FOLDER=/Users/$USER/Documents/UnrealEngine-4.15
PROJECT=PrototypeProject

cd $CUR_FOLDER

## Generate XCode Project
echo "$CUR_FOLDER"/"$PROJECT".uproject
cd "$UE4_SOURCE_FOLDER"/Engine/Build/BatchFiles/Mac
sh "$UE4_SOURCE_FOLDER"/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh -project="$CUR_FOLDER"/"$PROJECT".uproject -game -engine -progress
