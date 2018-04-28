all:report plot analyse runtest App

report : report.tex app log.txt analyse.txt plot1 plot2 plot3 plot4
	latex report.tex
	dvipdfm report.dvi
	touch report

plot : plot1 plot2 plot3 plot4

plot1: analyse.txt step4_type_a.p
	chmod +x step4_type_a.sh
	./step4_type_a.sh
	touch plot1
plot2: analyse.txt step4_type_b.p
	gnuplot step4_type_b.p
	touch plot2
plot3: analyse.txt step4_type_c.p
	gnuplot step4_type_c.p
	touch plot3
plot4: analyse.txt step4_type_d.p
	gnuplot step4_type_d.p
	touch plot4

analyse : analyse.txt
analyse.txt:log.txt step3_analyse.sh generate_avg_for_thread.sh generate_speed_up.sh generate_speed_up_var.sh
	chmod +x generate_avg_for_thread.sh
	chmod +x generate_speed_up.sh
	chmod +x generate_speed_up_var.sh
	chmod +x step3_analyse.sh
	./step3_analyse.sh
	touch analyse.txt

runtest:log.txt
log.txt: params.txt threads.txt step2_runtest.sh log_for_each_file.sh
	chmod +x log_for_each_file.sh
	chmod +x step2_runtest.sh
	./step2_runtest.sh
	touch log.txt

App: app
app:thread_function.o prog.o
	gcc -o app thread_function.o prog.o -lm -lpthread
prog.o: prog.c common.h
	gcc -I . -c prog.c
thread_function.o: thread_function.c common.h
	gcc -I . -c  thread_function.c


.Phony : clean all


clean:
	rm -rf graphs inputfiles logfiles prog app report.dvi report.pdf log.txt analyse.txt report.aux report.log
	rm -rf plot1 plot2 plot3 plot4 report
	rm -rf *.o
