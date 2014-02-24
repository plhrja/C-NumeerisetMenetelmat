set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/data0.tmp' title "f(x)" w l lt 3 lw 2, 'data/data1.tmp' title "f'(x)" w l lt 5 lw 2, 'data/data2.tmp' title "g(x)" w l lt 2 lw 2, 'data/data3.tmp'  notitle w l lt 0 lw 3
pause -1
