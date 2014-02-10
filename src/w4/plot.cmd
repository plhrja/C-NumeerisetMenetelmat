set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/fpoints.dat' notitle w l lt 1 lw 2,'data/datapoints.dat' notitle w p lt 0 pt 1 ps 1
pause -1
