#
# Unix/Linux GCC Makefile for Levenberg - Marquardt minimization
# Under windows, use Makefile.vc for MSVC
#

CC=gcc
LAPACKFLAG=-DHAVE_LAPACK # COMMENT THIS LINE IF YOU DO NOT HAVE LAPACK
CFLAGS=$(LAPACKFLAG) -O3 -funroll-loops -Wall #-pg
LAPACKLIBS_PATH=/usr/local/lib # WHEN USING LAPACK, CHANGE THIS TO WHERE YOUR COMPILED LIBS ARE!
LDFLAGS=-L$(LAPACKLIBS_PATH) -L.
LIBOBJS=lm.o Axb.o misc.o lmlec.o lmbc.o 
LIBSRCS=lm.c Axb.c misc.c lmlec.c lmbc.c
DEMOBJS=lmdemo.o
DEMOSRCS=lmdemo.c
AR=ar
RANLIB=ranlib
LAPACKLIBS=-llapack -lblas -lg2c # comment this line if you are not using LAPACK.
                                 # On systems with a FORTRAN (not f2c'ed) version of LAPACK, -lf2c is
                                 # not necessary; on others, -lf2c is equivalent to -lF77 -lI77

# The following works with the ATLAS updated lapack and Linux_P4SSE2 from http://www.netlib.org/atlas/archives/linux/
#LAPACKLIBS=-L/usr/local/atlas/lib -llapack -lcblas -lf77blas -latlas -lf2c

LIBS=$(LAPACKLIBS)

all: liblevmar.a lmdemo

liblevmar.a: $(LIBOBJS)
	$(AR) crv liblevmar.a $(LIBOBJS)
	$(RANLIB) liblevmar.a

lmdemo: $(DEMOBJS) liblevmar.a
	$(CC) $(LDFLAGS) $(DEMOBJS) -o lmdemo $(LIBS) -llevmar -lm

lm.o: lm.c lm_core.c lm.h misc.h
Axb.o: Axb.c Axb_core.c lm.h misc.h
misc.o: misc.c misc_core.c lm.h misc.h
lmlec.o: lmlec.c lmlec_core.c lm.h misc.h
lmbc.o: lmbc.c lmbc_core.c lm.h misc.h

lmdemo.o: lm.h

clean:
	@rm -f $(LIBOBJS) $(DEMOBJS)

depend:
	makedepend -f Makefile $(LIBSRCS) $(DEMOSRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

