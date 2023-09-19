.POSIX:

PREFIX = /usr/local
SCRIPTS_PREFIX = /opt

VERSION=laptop
CC = gcc -D$(VERSION)

$(info $(CC))

dwmblocks: dwmblocks.o
	$(CC) dwmblocks.o -lX11 -o dwmblocks
dwmblocks.o: dwmblocks.c config.h
	$(CC) -c dwmblocks.c
clean:
	rm -f *.o *.gch dwmblocks
install: dwmblocks
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks-raw
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dwmblocks-raw
	# scripts
	mkdir -p $(DESTDIR)$(SCRIPTS_PREFIX)/dwmblocks
	cp -rf scripts/* $(DESTDIR)$(SCRIPTS_PREFIX)/dwmblocks/
	chmod -R 755 $(DESTDIR)$(SCRIPTS_PREFIX)/dwmblocks
	# load path when launched
	echo "#!/bin/sh" > $(DESTDIR)$(PREFIX)/bin/dwmblocks
	echo "PATH=\$PATH:$(DESTDIR)$(SCRIPTS_PREFIX) $(DESTDIR)$(PREFIX)/bin/dwmblocks-raw" >> $(DESTDIR)$(PREFIX)/bin/dwmblocks
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dwmblocks
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks
	rm -rf $(DESTDIR)$(SCRIPTS_PREFIX)/dwmblocks

.PHONY: clean install uninstall laptop
