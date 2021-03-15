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
	grep -v ",/hot," a.csv > b.csv
	grep -v ",/ranking," b.csv > view.csv
copy:
	cp view.csv ..
