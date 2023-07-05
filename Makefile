ALL_C    = $(wildcard *.c)
TEST_C   = $(wildcard *_test.c)
ALL_BIN  = $(subst .c,,$(ALL_C))
TEST_BIN = $(subst .c,,$(TEST_C))

CFLAGS  = -Wall -O2
LDFLAGS =

all: $(ALL_BIN)

test: $(TEST_BIN)
	@for x in $^; do \
		echo "---- $$x ----"; \
		./$$x; \
	done

switch9_rand_fixed_bug: switch9_rand_fixed_bug.c
	gcc $(CFLAGS) -lsodium -o $@ $<

clean:
	-rm -f a.out $(ALL_BIN) $(TEST_BIN)

.PHONY: all test clean
