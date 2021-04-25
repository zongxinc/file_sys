override CFLAGS := -Wall -Werror -std=gnu99 -pedantic -O0 -g -pthread $(CFLAGS)
override LDLIBS := -pthread $(LDLIBS)

# Build the threads.o file
disk.o: disk.c disk.h 
fs.o: fs.c fs.h

# Automatically discover all test files
test_c_files=$(shell find tests -not -path '*/\.*' -type f -name '*.c')
test_o_files=$(test_c_files:.c=.o)
test_files=$(test_c_files:.c=)

# The intermediate test .o files shouldn't be auto-deleted in test runs; they
# may be useful for incremental builds while fixing fs.c bugs.
.SECONDARY: $(test_o_files)

.PHONY: clean check checkprogs

# Rules to build each individual test
tests/%: tests/%.o fs.o disk.o
	$(CC) $(LDFLAGS) $+ $(LOADLIBES) $(LDLIBS) -o $@

static_analysis:
	@echo "===== Running a static analyzer ====="
	# Analyze with clang-tidy. Ignore warnings about language extensions.
	# We use embedded assembly in a header file. An alternative is to build
	# from separate .s files and link those functions in.
	clang-tidy --checks=-clang-diagnostic-language-extension-token fs.c $(test_files) -- $(CFLAGS)
	@echo ""
	@echo "===== Running another static analyzer ====="
	cppcheck fs.c $(test_files)

# Build all of the test programs
checkprogs: $(test_files)

# Run the test programs
check: checkprogs
	tests/run_tests.sh $(test_files)

clean:
	rm -f *.o $(test_files) $(test_o_files)
