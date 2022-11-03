#!/bin/bash

set -x

ENDPOINT=https://api.devnet.solana.com

solana validators -v --url $ENDPOINT
