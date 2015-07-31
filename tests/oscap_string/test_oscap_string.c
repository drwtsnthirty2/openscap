#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/oscap_string.h"

int test_append_char(void);
int test_append_string(void);

int test_append_char()
{
	const unsigned int limit = 1000;
	int retval = 0;
	struct oscap_string *s = oscap_string_new();
	for (unsigned int i = 0; i < limit; i++) {
		oscap_string_append_char(s, 'a');
	}
	if (strlen(oscap_string_get_cstr(s)) != limit) {
		fprintf(stderr, "Length of result does not match the required length.\n");
		retval = 1;
	}
	oscap_string_free(s);
	return retval;
}

int test_append_string()
{
	const int count_of_strings = 7;
	const char *strings[] = {
		"",
		"A",
		"ABCD",
		"ABCDEFGH",
		"012345678901234567890123456789012345678901234567890123456789012",
		"0123456789012345678901234567890123456789012345678901234567890123",
		"01234567890123456789012345678901234567890123456789012345678901234"
	};
	unsigned int length = 0;
	int retval = 0;
	struct oscap_string *s = oscap_string_new();
	for (int i = 0; i < count_of_strings; i++) {
		oscap_string_append_string(s, strings[i]);
		length += strlen(strings[i]);
	}
	if (strlen(oscap_string_get_cstr(s)) != length) {
		fprintf(stderr, "Length of result does not match the required length.\n");
		retval = 1;
	}
	oscap_string_free(s);
	return retval;
}

int main (int argc, char *argv[])
{
	int retval = 0;
	if ((retval = test_append_char()) != 0 ) {
		return retval;
	}

	if ((retval = test_append_string()) != 0 ) {
		return retval;
	}
	return retval;
}

