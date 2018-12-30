#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22224:22224" --name "stringmaster1" -it "tharina/stringmaster1"
