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
UE4_SOURCE_FOLDER=/Users/$(whoami)/Documents/UnrealEngine-4.15

## Pack Mac Server
"$UE4_SOURCE_FOLDER"/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -nop4 -project="$CUR_FOLDER"/"$PROJECT".uproject -cook -cookall -NumCookersToSpawn=2 -platform=Mac -clientconfig=Development -serverconfig=Development -server -stage -UnVersioned -serverplatform=Mac -noclient -build -archive -archivedirectory="$CUR_FOLDER"/Packed -utf8output -compile
