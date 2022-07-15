#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

# ENDPOINT=https://pczewaaeh9.execute-api.eu-central-1.amazonaws.com/api
ENDPOINT=http://127.0.0.1:8000

pipenv run http $ENDPOINT/
# pipenv run http --form POST $ENDPOINT/ item=sword item=shield item=potion --debug
# pipenv run http GET $ENDPOINT/users/jacky --debug
# pipenv run http DELETE $ENDPOINT/users/jacky --debug
# pipenv run http GET $ENDPOINT/kv/jacky --debug
# echo '{"level": 10}' | pipenv run http PUT $ENDPOINT/kv/jacky --debug
# pipenv run http GET $ENDPOINT/kv/jacky --debug
# pipenv run http $ENDPOINT/compress --debug
pipenv run http $ENDPOINT/cors