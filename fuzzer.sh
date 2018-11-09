#!/usr/bin/env bash

RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[34m"
MAGENTA="\033[35m"
RESET="\033[0m"

libft=$1

tmp=$(mktemp -d)
current=$(pwd)

make -C $libft

if [ ! -f Fuzzer/libFuzzer.a ]; then
	pushd Fuzzer
	bash build.sh
	popd
fi

fuzz() {
	local name=$1
	local corpus=$current/${name}_crashs

	echo -e "========> ${MAGENTA}${name}${RESET} <========"
	clang -fsanitize-coverage=trace-pc-guard \
		-I$libft -c tests/${name}.fuzz.c \
		-o $tmp/test.o
	clang++ -fsanitize-coverage=trace-pc-guard \
		$tmp/test.o Fuzzer/libFuzzer.a $libft/libft.a \
		-o $tmp/${name}fuzz
	pushd $tmp
	mkdir -p $corpus
	mkdir ${name}_corpus
	./${name}fuzz -max_total_time=5 ${name}_corpus $corpus
	mv crash-* crash 2> /dev/null
	if [[ -f crash ]]; then
		echo -e "${MAGENTA}${name}${RED} crashed ... sorry for you :("
		echo -e "${GREEN}But thank to make my test evolve :)"
		echo -e "${YELLOW}Minimizing output${RESET} ..."

		local last=$(./${name}fuzz crash -minimize_crash=1 -timeout=1 -runs=100 2>&1 | tail -1)
		local file=$(echo $last | cut -c 38- | cut -d ' ' -f 1)
		if [[ $file != crash ]]; then
			mv $file $current/${name}_crashs
		fi
		rm crash
	else
		echo -e "${GREEN}No Crash for ${MAGENTA}${name}${GREEN} ... good :)${RESET}"
	fi
	popd
	sleep 2
}

fuzz ft_memccpy
fuzz ft_memcpy
fuzz ft_strchr
rm -rf $tmp
