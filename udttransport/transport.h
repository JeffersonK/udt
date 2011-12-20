/*****************************************************************************
Copyright 2005 - 2011 The Board of Trustees of the University of Illinois.

Licensed under the Apache License, Version 2.0 (the "License"); you may not
use this file except in compliance with the License. You may obtain a copy of
the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
License for the specific language governing permissions and limitations under
the License.
*****************************************************************************/

/*****************************************************************************
written by
   Yunhong Gu, last updated 01/02/2010
*****************************************************************************/


#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__

#include <string>
#include <udt.h>

namespace sector
{

struct TransOption
{
   // TODO: put rendzevous, reuseaddr, timeout, etc in this structure.
};

class Transport
{
public:
   virtual ~Transport() {};

public:
   virtual int open(int& port, bool rendezvous, bool reuseaddr) = 0;

   virtual int listen() = 0;
   virtual Transport* accept(std::string& ip, int& port) = 0;
   virtual int connect(const std::string& ip, int port) = 0;
   virtual int close() = 0;

   virtual int send(const char* buf, int size) = 0;
   virtual int recv(char* buf, int size) = 0;
   virtual int64_t sendfile(std::fstream& ifs, int64_t offset, int64_t size) = 0;
   virtual int64_t recvfile(std::fstream& ofs, int64_t offset, int64_t size) = 0;

   virtual bool isConnected() = 0;
   virtual int64_t getRealSndSpeed() = 0;
   virtual int getLocalAddr(std::string& ip, int& port) = 0;

   //virtual int setOption(const TransOption& opt) { return 0; }
};

}  // namespace sector

#endif
