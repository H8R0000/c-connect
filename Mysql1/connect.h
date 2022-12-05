#pragma once

#include <iostream>
#include <mysqlx/xdevapi.h>

using ::std::cout;
using ::std::endl;
using namespace ::mysqlx;


void add_st();
void add_t();
void add_group();
void add_lab();

void fetchAll_st();
void fetchAll_teachers();
void fetchAll_labs();
void fetchAll_groups();

void delete_lab();
void delete_st();
void delete_t();
void delete_group();
