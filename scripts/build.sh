#!/bin/sh

green=`tput setaf 2`
reset=`tput sgr0`

cd build
if [[ $(cmake ../) ]]; then
    echo "Configure the project :: ${green}DONE ${reset}"
    if [[ $(cmake --build .) ]]; then
        echo "Build the project :: ${green}DONE ${reset}\n"
        ./effectivec
        cd ..
   fi
fi
