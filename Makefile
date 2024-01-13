.POSIX:

PREFIX = /usr/local

CC = gcc
OUT = $(DESTDIR)$(PREFIX)

$(info $(CC))

dwmblocks: dwmblocks.o
	$(CC) dwmblocks.o -lX11 -o dwmblocks
dwmblocks.o: dwmblocks.c config.h
	$(CC) -c dwmblocks.c
clean:
	rm -f *.o *.gch dwmblocks
install: dwmblocks
	mkdir -p $(OUT)/bin
	cp -f dwmblocks $(OUT)/bin/dwmblocks
	chmod 755 $(OUT)/bin/dwmblocks
	# scripts
	mkdir -p $(OUT)/share/dwmblocks
	cp -rf scripts/* $(OUT)/share/dwmblocks
	chmod -R 755 $(OUT)/share/dwmblocks
	# create fake bin that loads share to the path
	./create-path-runner $(OUT)/share/dwmblocks $(OUT)/bin/dwmblocks
	cp -f dwmblocks-with-path $(OUT)/bin/dwmblocks-wrapped
	chmod 755 $(OUT)/bin/dwmblocks-wrapped
uninstall:
	rm -f $(OUT)/bin/dwmblocks
	rm -f $(OUT)/bin/dwmblocks-wrapped
	rm -rf $(OUT)/share/dwmblocks

.PHONY: clean install uninstall
