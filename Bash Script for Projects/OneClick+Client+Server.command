#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

## Execute Commands
$CUR_FOLDER/FetchAll.command
$CUR_FOLDER/Pull.command
$CUR_FOLDER/GenerateProject.command
$CUR_FOLDER/BuildAll.command
##$CUR_FOLDER/Cook.command
$CUR_FOLDER/PackMacServer.command
$CUR_FOLDER/PackMacClient.command