set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/data0.tmp' title "function" w l lt 3 lw 2, 'data/data1.tmp' title "derivative" w l lt 5 lw 2, 'data/data2.tmp' title "integral" w l lt 2 lw 2
pause -1
