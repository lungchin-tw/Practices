#!/bin/sh
## Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
##
## Unreal Engine 4 AutomationTool setup script
##
## This script uses the .command extenion so that is clickable in
## in the OSX Finder.  All it does is call RunUAT.sh which does
## the real work.


CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
$CUR_FOLDER/Packed/MacNoEditor/PrototypeProject.app/Contents/MacOS/PrototypeProject ResX=800 ResY=600 -NoVSync -FPS=20 ?DEBUG_UI1 ?Account=   BD5C2B2AC8462CB32DBDAFA533AE53D2   ?Password=   BD5C2B2AC8462CB32DBDAFA533AE53D2   AbsLog=$CUR_FOLDER/Log/ClientWithAccount.log 
