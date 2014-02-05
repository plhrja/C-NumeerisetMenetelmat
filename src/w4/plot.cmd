set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/fpoints0.dat' notitle w l lt 5 lw 2,'data/fpoints1.dat' notitle w l lt 5 lw 2,'data/fpoints2.dat' notitle w l lt 5 lw 2,'data/fpoints3.dat' notitle w l lt 5 lw 2,'data/xpoints' notitle w p lt 0 pt 1 ps 3
pause -1
