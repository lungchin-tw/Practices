#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

GC(){
  echo “GC $1”
  cd $1
  git stash
  git gc
}

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT=PrototypeProject

## GC
GC /Users/$(whoami)/Documents/JavaWorkspace/ProjectOneZenServer
GC $CUR_FOLDER/VersionConfig
GC $CUR_FOLDER/../ProjectUtility
GC $CUR_FOLDER
GC $CUR_FOLDER/Content/DataTable
GC $CUR_FOLDER/Content/ArtContent
