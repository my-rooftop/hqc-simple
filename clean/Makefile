# This Makefile can be used with GNU Make or BSD Make
COMMON_PATH = /home/boochoo/hqc/CortexM4-Implementation/PQClean
LIB=libhqc-128_clean.a
HEADERS=api.h code.h domains.h fft.h gf.h gf2x.h hqc.h parameters.h parsing.h reed_muller.h reed_solomon.h shake_ds.h shake_prng.h vector.h 
OBJECTS=code.o fft.o gf.o gf2x.o hqc.o kem.o parsing.o reed_muller.o reed_solomon.o shake_ds.o shake_prng.o vector.o 
COMMON_SOURCES=$(COMMON_PATH)/common/randombytes.c $(COMMON_PATH)/common/fips202.c $(COMMON_PATH)/common/sha2.c
COMMON_HEADERS=-I$(COMMON_PATH)/crypto_kem/hqc-128/clean -I$(COMMON_PATH)/common

CFLAGS=-O0 -Wall -Wextra -Wpedantic -Wshadow -Wvla -Werror -Wredundant-decls -Wmissing-prototypes -std=c99 -I../../../common $(EXTRAFLAGS) -g

all: main

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

main: main.o $(OBJECTS)
	$(CC) -o $@ main.o $(OBJECTS) $(COMMON_SOURCES) $(COMMON_HEADERS)

clean:
	$(RM) $(OBJECTS) main.o
	$(RM) $(LIB) main
