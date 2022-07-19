#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws route53 create-hosted-zone \
--name jacky-chen-chalice-demo.com \
--caller-reference 1234 \
| tee hosted-zone.log