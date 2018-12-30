#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/1996 .
else
	echo Build failed
fi
