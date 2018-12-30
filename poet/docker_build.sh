#!/bin/bash

if [[ $? = 0 ]]; then
	docker build -t tharina/poet .
else
	echo Build failed
fi
