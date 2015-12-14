down:
	./Pandoc 1 | ./View > view.csv
	./Pandoc 2 | ./View >> view.csv
	./Pandoc 3 | ./View >> view.csv
	./Pandoc 4 | ./View >> view.csv
	./Pandoc 5 | ./View >> view.csv
	./Pandoc 6 | ./View >> view.csv
	./Pandoc 7 | ./View >> view.csv
view:
	soffice view.csv
tar:
	tar czvf pandoc.tgz Pandoc View view.csv Makefile
copy:
	scp pandoc.tgz jun@soumgw.soum.co.jp:
