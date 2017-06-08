#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.


Fetch(){
  echo “Fetch $1”
  cd $1
  git fetch --prune origin 
}

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT=PrototypeProject

## Fetch
Fetch /Users/$USER/Documents/JavaWorkspace/ProjectOneZenServer
Fetch $CUR_FOLDER
Fetch $CUR_FOLDER/Content/DataTable
Fetch $CUR_FOLDER/Content/ArtContent
Fetch $CUR_FOLDER/VersionConfig

