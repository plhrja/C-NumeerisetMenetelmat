set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/data0.tmp' title "theta_1" w l lt 3 lw 1, 'data/data1.tmp' title "theta_2" w l lt 5 lw 1, 'data/data2.tmp' title "theta_3" w l lt 2 lw 1, 'data/data3.tmp' title "theta_4" w l lt 1 lw 1
pause -1
