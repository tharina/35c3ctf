#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:22223:22223" --name "poet" -it "tharina/poet"
