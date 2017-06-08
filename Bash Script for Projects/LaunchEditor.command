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
EDITOR=$UE4_SOURCE_FOLDER/Engine/Binaries/Mac/UE4Editor.app//Contents/MacOS/UE4Editor
##EDITOR=$UE4_SOURCE_FOLDER/Engine/Binaries/Mac/UE4Editor-Mac-Debug.app//Contents/MacOS/UE4Editor-Mac-Debug

##-log -AbsLog=$CUR_FOLDER/Player2.log

$EDITOR $CUR_FOLDER/$PROJECT.uproject
