DIRS=src app udttransport
TARGETS=all clean install
LIBS=src/libudt.a src/libudt.so udttransport/libudttransport.a udttransport/libudttransport.so
INCLUDES=src/udt.h udttransport/udttransport.h udttransport/transport.h
LIBDIR=lib
INCLUDEDIR=include
INSTALL_LIBDIR=/usr/local/lib
INSTALL_INCLUDEDIR=/usr/local/include

$(TARGETS): %: $(patsubst %, %.%, $(DIRS))

$(foreach TGT, $(TARGETS), $(patsubst %, %.$(TGT), $(DIRS))):
	$(MAKE) -C $(subst ., , $@)

install:
	install -d $(LIBDIR)
	@for b in $(LIBS); do \
		echo "install -m 755 $$b $(LIBDIR)"; \
		install -m 755 $$b $(LIBDIR); \
	done
	install -m 755 $(LIBDIR)/* $(INSTALL_LIBDIR)

	install -d $(INCLUDEDIR)
	@for b in $(INCLUDES); do \
		echo "install -m 755 $$b $(INCLUDEDIR)"; \
		install -m 755 $$b $(INCLUDEDIR); \
	done
	install -m 755 $(INCLUDEDIR)/* $(INSTALL_INCLUDEDIR)


clean:
	rm -rf $(LIBDIR)
	rm -rf $(INCLUDEDIR)
