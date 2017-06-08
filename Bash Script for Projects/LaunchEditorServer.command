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
UE4_SOURCE_FOLDER=/Users/zentech/Documents/UnrealEngine-4.15
EDITOR=$UE4_SOURCE_FOLDER/Engine/Binaries/Mac/UE4Editor.app/Contents/MacOS/UE4Editor
##EDITOR=$UE4_SOURCE_FOLDER/Engine/Binaries/Mac/UE4Editor-Mac-Debug.app//Contents/MacOS/UE4Editor-Mac-Debug


## /Game/ArtContent/Map/stage00_duel01/stage00_duel01_scene

$EDITOR $CUR_FOLDER/$PROJECT.uproject /Game/TestStatusEffect.umap -server -log AbsLog=$CUR_FOLDER/Server.log PORT=7777 ?ZenServerIP=localhost ?SCENEID201