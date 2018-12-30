#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/stringmaster1 .
else
	echo Build failed
fi
