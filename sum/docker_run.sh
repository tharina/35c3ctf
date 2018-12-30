#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22226:22226" --name "sum" -it "tharina/sum"
