#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

Delete(){
  echo “Delete $1”
  cd $1
  git stash
  git branch | grep -v “*” | xargs git branch -D
}

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT=PrototypeProject


## Delete
Delete /Users/$USER/Documents/JavaWorkspace/PrototypeServerDevelop
Delete $CUR_FOLDER
Delete $CUR_FOLDER/Content/DataTable
Delete $CUR_FOLDER/Content/ArtContent
Delete $CUR_FOLDER/PrototypeProjectVersionConfig