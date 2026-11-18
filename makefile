CC = cc
target = project.o remove_comments.o macro_replace.o header_file.o
my_preprocessor : $(target)
	$(CC) $(target) -o srinath_preprocessor

project.o : project.c
	$(CC) -c project.c
remove_comment.o : remove_comments.c
	$(CC) -c remove_comment.c
macro_replace.o : macro_replace.c
	$(CC) -c macro_replace.c
header_file.o : header_file.c
	$(CC) -c header_file.c

clear:
	@echo "cleaning up..."
	@rm -v *.o

