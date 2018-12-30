#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/arraymaster1 .
else
	echo Build failed
fi
