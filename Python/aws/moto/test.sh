#! /bin/zsh

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)


# aws cognito-identity create-identity-pool \
# --identity-pool-name demopool \
# --allow-unauthenticated-identities \
# --profile jacky

aws cognito-identity get-id \
--identity-pool-id eu-central-1:fd0fa689-2b3f-45a4-9dba-0ea4160c9cef \
--profile jacky