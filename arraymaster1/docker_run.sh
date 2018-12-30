#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22228:22228" --name "arraymaster1" -it "tharina/arraymaster1"
