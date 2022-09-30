#!/bin/bash

set -x

pushd $(dirname $0)

SENDER=2wRQAamqYT3EDk8Gshizv3M1MyJ7aJq5oj5FGp2u9pCd
# SENDERKEYPAIR=prompt://
SENDERKEYPAIR=./sender-keypair.json
RECEIVER=8h6h9Vbj16bw7QcmrtVc7KHhNRsG2PdfwHSUaxqC9p5T

ENDPOINT=https://api.devnet.solana.com

solana balance $SENDER --url $ENDPOINT
echo ""
solana balance $RECEIVER --url $ENDPOINT
echo ""

solana transfer --from $SENDERKEYPAIR $RECEIVER 0.5 \
--allow-unfunded-recipient \
--fee-payer $SENDERKEYPAIR \
--url $ENDPOINT

solana balance $SENDER --url $ENDPOINT
echo ""
solana balance $RECEIVER --url $ENDPOINT

popd