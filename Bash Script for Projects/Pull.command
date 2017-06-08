#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.

GitPull(){
    cd $1
    git stash
    git -c diff.mnemonicprefix=false -c core.quotepath=false fetch origin
    git checkout $2
    git -c diff.mnemonicprefix=false -c core.quotepath=false pull origin $2
}


CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
PROJECT=PrototypeProject

##GitPull $CUR_FOLDER Development
GitPull $CUR_FOLDER/Content/DataTable Development_Taiwan
GitPull $CUR_FOLDER/Content/ArtContent Development_Taiwan
GitPull $CUR_FOLDER/VersionConfig master
