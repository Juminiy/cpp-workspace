#pragma once 
#ifndef _5_H
#define _5_H

#include <string.h>

#define NONRET __attribute__((noreturn))
#define UNUSED __attribute__((unused))

char * xstrdup(char * args);

void test_xstrdup() NONRET;

#endif 