// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#include "io/io_adapter.h"

struct c_reader : public VW::io::reader
{
  c_reader(void* context, read_func* read, reset_func* reset, cleanup_func* cleanup)
      : VW::io::reader(reset != nullptr /*is_resettable*/)
      , _context(context)
      , _read_func(read)
      , _reset_func(reset)
      , _cleanup_func(cleanup)
  {
  }

  ~c_reader() override
  {
    if (_cleanup_func != nullptr)
    {
      _cleanup_func(_context);
    }
  }

  virtual ssize_t read(char* buffer, size_t num_bytes) override
  {
    if (_read_func == nullptr)
    {
      THROW("Read not implemented. Should not be possible.")
    }

    ssize_t bytes_read = 0;
    auto result = _read_func(_context, buffer, num_bytes, &bytes_read);
    if (result != vw_success)
    {
      THROW("Read failed with code: " << result);
    }
    return bytes_read;
  }

  void reset() override
  {
    if (_reset_func == nullptr)
    {
      THROW("Reset not supported for this io_adapter");
    }

    auto result = _reset_func(_context);
    if (result != vw_success)
    {
      THROW("Reset failed with code: " << result);
    }
  }

private:
  void* _context = nullptr;
  read_func* _read_func = nullptr;
  reset_func* _reset_func = nullptr;
  cleanup_func* _cleanup_func = nullptr;
};

struct c_writer : public VW::io::writer
{
  c_writer(void* context, write_func* write, flush_func* flush, cleanup_func* cleanup)
      : _context(context), _write_func(write), _flush_func(flush), _cleanup_func(cleanup)
  {
  }

  ~c_writer() override
  {
    if (_cleanup_func != nullptr)
    {
      _cleanup_func(_context);
    }
  }

  ssize_t write(const char* buffer, size_t num_bytes) override
  {
    if (_write_func == nullptr)
    {
      THROW("Write not implemented. Should not be possible.")
    }
    ssize_t bytes_written = 0;
    auto result = _write_func(_context, buffer, num_bytes, &bytes_written);
    if (result != vw_success)
    {
      THROW("Write failed with code: " << result);
    }
    return bytes_written;
  }

  void flush() override
  {
    if (_flush_func != nullptr)
    {
      auto result = _flush_func(_context);
      if (result != vw_success)
      {
        THROW("Flush failed with code: " << result);
      }
    }
  }

private:
  void* _context = nullptr;
  write_func* _write_func = nullptr;
  flush_func* _flush_func = nullptr;
  cleanup_func* _cleanup_func = nullptr;
};
