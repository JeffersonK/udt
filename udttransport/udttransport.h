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
   Yunhong Gu, last updated 01/02/2011
*****************************************************************************/


#ifndef __UDT_TRANSPORT_H__
#define __UDT_TRANSPORT_H__

#include <transport.h>
#include <udt.h>

//TODO + NOTE: this UDT transport implementation is not fine tuned to any special data center configuration
//In a production system, the UDT performance can be further tuned for better performance
//E.g., MTU can be set to 9000 is jumbo frame is enabled; fixed rate can be used in a bottleneck free data center

namespace sector
{

class UDTTransport: public Transport
{
public:
   UDTTransport();
   virtual ~UDTTransport();

public:
   static void initialize();
   static void release();

   virtual int open(int& port, bool rendezvous = true, bool reuseaddr = false);

   virtual int listen();
   virtual UDTTransport* accept(std::string& ip, int& port);
   virtual int connect(const std::string& ip, int port);
   virtual int close();

   virtual int send(const char* buf, int size);
   virtual int recv(char* buf, int size);
   virtual int64_t sendfile(std::fstream& ifs, int64_t offset, int64_t size);
   virtual int64_t recvfile(std::fstream& ofs, int64_t offset, int64_t size);

   virtual bool isConnected();
   virtual int64_t getRealSndSpeed();
   virtual int getLocalAddr(std::string& ip, int& port);

   int setTimeout(int sndtimeo, int rcvtimeo);

private:
   UDTSOCKET m_Socket;

   int m_iSndTimeO;
   int m_iRcvTimeO;
};

}  // namespace sector

#endif
