set title "Verification of Hadamards theorem with histograms"
set xrange [0:2001]
set yrange [0:18]
unset xtic
set style fill solid noborder
plot 'data/hist.dat' w boxes notitle, 'data/bound.dat' w dots notitle 
pause -1
