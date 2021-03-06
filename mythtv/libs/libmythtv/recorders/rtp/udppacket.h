/* -*- Mode: c++ -*-
 * Copyright (c) 2012 Digital Nirvana, Inc.
 * Distributed as part of MythTV under GPL v2 and later.
 */

#ifndef _UDP_PACKET_H_
#define _UDP_PACKET_H_

#include <cinttypes>

#include <QByteArray>

/** UDP Packet
 *
 *  The data is stored in a QByteArray which is a reference counted
 *  shared data container, so an UDPPacket can be assigned to a
 *  subclass efficiently.
 *
 */
class UDPPacket
{
  public:
    UDPPacket(const UDPPacket &o)  = default;
    explicit UDPPacket(uint64_t key) : m_key(key) { }
    UDPPacket(void) = default;
    virtual ~UDPPacket() = default;

    UDPPacket& operator=(const UDPPacket &rhs) = default;

    /// IsValid() must return true before any data access methods are called,
    /// other than GetDataReference() and GetData()
    virtual bool IsValid(void) const { return true; }

    uint64_t GetKey(void) const { return m_key; }

    QByteArray &GetDataReference(void) { return m_data; }
    QByteArray GetData(void) const { return m_data; }

  protected:
    /// Key used to ensure we avoid extra memory allocation in m_data QByteArray
    uint64_t   m_key  { 0ULL };
    QByteArray m_data;
};

#endif // _UDP_PACKET_H_
