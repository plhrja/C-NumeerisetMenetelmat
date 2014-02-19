set contour
set hidden3d
set parametric
set samples 2
set isosamples 2
splot "z.tmp" title 'f(x,y)' with lines
pause -1 "Press enter "
set terminal postscript
set output "gnusurf.ps"
 replot
exit