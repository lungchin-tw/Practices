#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
$CUR_FOLDER/Packed/MacNoEditor/PrototypeProject.app/Contents/MacOS/PrototypeProject -WINDOWED ResX=800 ResY=600 -FPS=20 ?DEBUG_UI1 -AbsLog=$CUR_FOLDER/Log/Client.log