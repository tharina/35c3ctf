#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22229:22229" --name "arraymaster2" -it "tharina/arraymaster2"
