#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

# ENDPOINT=$(pipenv run chalice url --stage dev)
ENDPOINT=$(./get-rest-api-url.sh jacky jacky-chen-chalice-demo)
# ENDPOINT=http://127.0.0.1:8000

pipenv run http $ENDPOINT/env
# pipenv run http $ENDPOINT/
# pipenv run http --form POST $ENDPOINT/ item=sword item=shield item=potion --debug
# pipenv run http GET $ENDPOINT/users/jacky --debug
# pipenv run http DELETE $ENDPOINT/users/jacky --debug
# pipenv run http GET $ENDPOINT/kv/jacky --debug
# echo '{"level": 10}' | pipenv run http PUT $ENDPOINT/kv/jacky --debug
# pipenv run http GET $ENDPOINT/kv/jacky --debug
# pipenv run http $ENDPOINT/compress --debug
# pipenv run http $ENDPOINT/cors
# pipenv run http $ENDPOINT/deps
# pipenv run http $ENDPOINT/auth/coginto
# pipenv run http $ENDPOINT/auth/iam
# pipenv run http $ENDPOINT/auth/custom
# pipenv run http $ENDPOINT/auth/authorizer
pipenv run http -v $ENDPOINT/auth/authorizer 'Authorization: allow'
