set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data.tmp' notitle w p lt 0 pt 1 ps 1,'fitted.tmp' notitle w l lt 1 lw 1
pause -1
