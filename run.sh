#!/bin/bash
make \
&& echo -e "\n\nLang parsed successfully!\n\n" \
&& ./lang-parser \
&& echo -e "\n\ncleanning fiels..." \
&& make clean &>/dev/null