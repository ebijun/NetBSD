view.csv:
	./togetterview.rb 1 |fgrep -vf Pattern >  a.csv
	./togetterview.rb 2 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 3 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 4 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 5 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 6 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 7 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 8 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 9 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 10 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 11 |fgrep -vf Pattern >> a.csv
	./togetterview.rb 12 |fgrep -vf Pattern >> a.csv
	mv a.csv view.csv
	tail -3 view.csv

copy:
	cp view.csv ..
