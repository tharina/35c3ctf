#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/sum .
else
	echo Build failed
fi
