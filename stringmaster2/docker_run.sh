#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22225:22225" --name "stringmaster2" -it "tharina/stringmaster2"
