set timestamp
set grid
plot 'mnmx.dat' notitle w dots, 'data/hp.mat' notitle w p lt 3 pt 1 ps 1,'data/mp.mat' notitle w p lt 1 pt 1 ps 1,'data/f1.mat' notitle w l lt 0 lw 5,'data/f2.mat' notitle w l lt 0 lw 5
pause -1
