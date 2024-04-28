
# bash run_tex.sh exam.tex
# bash run_tex.sh solution.tex
# bash run_tex.sh midterm_exam.tex
# bash run_tex.sh slide_modeling1.tex 


#export INPUT_TEX_FILE=solution
#export INPUT_TEX_FILE=exam
#echo   'sh run_tex.sh exams'
#xelatex -interaction=nonstopmode -synctex=-1 $1.t
#xelatex -interaction=nonstopmode -synctex=-1 $1.tex

INPUT_TEX_FILE=${1::-4}
echo $INPUT_TEX_FILE
#exit

xelatex -interaction=nonstopmode -synctex=-1 $INPUT_TEX_FILE.tex
bibtex $INPUT_TEX_FILE.aux
#evince $INPUT_TEX_FILE.pdf
atril $INPUT_TEX_FILE.pdf
#rm  $INPUT_TEX_FILE.pdf 
rm  $INPUT_TEX_FILE.aux
rm  $INPUT_TEX_FILE.log
rm  $INPUT_TEX_FILE.synctex
rm  $INPUT_TEX_FILE.bbl
rm  $INPUT_TEX_FILE.blg
rm  $INPUT_TEX_FILE.nav
rm  $INPUT_TEX_FILE.toc
rm  $INPUT_TEX_FILE.snm
rm  $INPUT_TEX_FILE.out
