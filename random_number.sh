#!/bin/bash

SUM=0
COUNT=100
SIZE=100

i=0
while [ $i -lt $COUNT ]
do
	j=0
	while [ $j -lt $SIZE ]
	do
		NUM=$RANDOM
		while [[ ${NUMS[@]} =~ $NUM ]]
		do
			NUM=$RANDOM
		done
		NUMS[$j]=$NUM
		j=$(( $j + 1 ))
	done

	ARG="${NUMS[@]}"
	COMMAND_COUNT[$i]=$( ./push_swap $ARG | wc -l | tr -d ' ' )
	SUM=$(( $SUM + ${COMMAND_COUNT[$i]} ))
	RESULT[$i]=$( ./push_swap $ARG | ./checker_linux $ARG )

	if [ "${RESULT[$i]}" = "OK" ]
	then
		echo ${RESULT[$i]} "${COMMAND_COUNT[$i]}"
	else
		echo $ARG
		echo ${RESULT[$i]}
	fi

	i=$(( $i + 1 ))
done

echo Average: $(( $SUM / $COUNT ))