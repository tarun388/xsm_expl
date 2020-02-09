#!/bin/bash/

cur=$(pwd)
cd  ~/xsm_expl/STG$1/Task1/
yacc -d ast.y
echo "yacc done"
lex ast.l
echo "lex done"
gcc lex.yy.c y.tab.c -o ast.exe
echo "compile done"
./ast.exe input.txt
echo "run"
g++ translator.cpp -o translator.exe
echo "compiled translator"
./translator.exe xsm1.xsm xsm2.xsm
echo "translated"
cd  $curr
