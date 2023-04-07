ALL_C    = $(wildcard *.c)
TEST_C   = $(wildcard *_test.c)
ALL_BIN  = $(subst .c,,$(ALL_C))
TEST_BIN = $(subst .c,,$(TEST_C))

CFLAGS = -Wall -O2
LDFLAGS = -lsodium

all: $(ALL_BIN)

test: $(TEST_BIN)
	@for x in $^; do \
		echo "---- $$x ----"; \
		./$$x; \
	done

clean:
	-rm -f a.out $(ALL_BIN) $(TEST_BIN)

.PHONY: all test clean
