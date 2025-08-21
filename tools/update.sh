find  . \( -name 'a.out' -or -name '*~' -or -name '*.pyc' -or -name '__pycache__' -or -name '.~lock.*.csv#' \) -delete -print
git add .
git commit -am "Change and Automatic update: `date`"
git push origin main 

# echo `pwd` 
# bash tool/update