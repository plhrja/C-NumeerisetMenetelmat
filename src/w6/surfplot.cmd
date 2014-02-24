set samples 40
set isosamples 40
set xlabel "X" offset -2,-1
set ylabel "Y" offset -2,-1
set zlabel "Z" offset -1
set hidden3d back offset 1 trianglepattern 3 undefined 1 altdiagonal bentover
set pm3d
set style fill transparent solid 0.6
set title "Fitting of temperature-curve"
splot "data/data0.tmp" with lines notitle, "data/data1.tmp" with points notitle
pause -1
