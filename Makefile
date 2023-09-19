.POSIX:

PREFIX = /usr/local

VERSION = laptop
CC = gcc -D$(VERSION)
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
	cp -f dwmblocks $(OUT)/bin/dwmblocks-bin
	chmod 755 $(OUT)/bin/dwmblocks-bin
	# scripts
	mkdir -p $(OUT)/share/dwmblocks
	cp -rf scripts/* $(OUT)/share/dwmblocks
	chmod -R 755 $(OUT)/share/dwmblocks
	# create fake bin that loads share to the path
	echo "#!/bin/sh" > $(OUT)/bin/dwmblocks
	echo "PATH=$PATH:$(OUT)/share/dwmblocks $(OUT)/bin/dwmblocks-bin" >> $(OUT)/bin/dwmblocks
	chmod 755 $(OUT)/bin/dwmblocks
uninstall:
	rm -f $(OUT)/bin/dwmblocks
	rm -f $(OUT)/bin/dwmblocks-bin
	rm -rf $(OUT)/share/dwmblocks

.PHONY: clean install uninstall laptop
