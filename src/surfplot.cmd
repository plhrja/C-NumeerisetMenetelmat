set samples 40
set isosamples 40
set hidden3d back offset 1 trianglepattern 3 undefined 1 altdiagonal bentover
set title "Testing mysurf"
splot "data/data0.tmp" with lines notitle, "data/data1.tmp" with lines notitle, "data/data2.tmp" with points notitle
pause -1
