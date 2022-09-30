#!/bin/bash

set -x

ENDPOINT=https://api.devnet.solana.com

solana cluster-version --url $ENDPOINT
