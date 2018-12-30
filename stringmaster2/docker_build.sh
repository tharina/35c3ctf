#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/stringmaster2 .
else
	echo Build failed
fi
