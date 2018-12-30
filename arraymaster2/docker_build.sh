#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/arraymaster2 .
else
	echo Build failed
fi
