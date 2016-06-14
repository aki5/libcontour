
CFLAGS=-Os -fomit-frame-pointer -W -Wall

LIBCONTOUR_OFILES=\
	contour.o\
	fitpoly.o\

libcontour.a: $(LIBCONTOUR_OFILES)
	$(AR) r $@ $(LIBCONTOUR_OFILES)

clean:
	rm -f libcontour.a *.o
