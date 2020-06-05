// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "io/io_adapter.h"
#include "vw/experimental/types.h"

struct c_reader : public VW::io::reader
{
  c_reader(void* context, read_func* read);
  virtual ssize_t read(char* buffer, size_t num_bytes) override;

private:
  void* _context = nullptr;
  read_func* _read_func = nullptr;
};

struct c_writer : public VW::io::writer
{
  c_writer(void* context, write_func* write);
  ssize_t write(const char* buffer, size_t num_bytes) override;

private:
  void* _context = nullptr;
  write_func* _write_func = nullptr;
};
