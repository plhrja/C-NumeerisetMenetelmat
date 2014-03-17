set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/data0.tmp'  notitle w l lt 5 lw 1, 'data/data1.tmp'  notitle w p lt 0 pt 7 ps 1
pause -1
