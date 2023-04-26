#!/bin/bash
#export INPUT_TEX_FILE=exam
#xelatex -interaction=nonstopmode -synctex=-1 $1.t
echo  'sh run_tex.sh exams (delete file type, .tex)'
#xelatex -interaction=nonstopmode -synctex=-1 $1.tex
#xelatex -interaction=nonstopmode -synctex=-1 $INPUT_TEX_FILE.tex
# latex $1.tex  # create dvi file
pdflatex $1.tex # create pdf file
bibtex $1.aux
#evince $1.pdf
atril $1.pdf
rm -r $1.pdf
rm -r $1.aux
rm -r $1.log
rm -r $1.synctex
rm -r $1.bbl
rm -r $1.blg
rm -r $1.out
rm    "#"$1*"#"
