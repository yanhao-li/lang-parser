#!/bin/bash

make \
&& ./lang-parser \
&& echo -e "\n\ncleanning fiels..." \
&& make clean