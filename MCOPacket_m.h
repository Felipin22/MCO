//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/applications/vehicular/MCOPacket.msg.
//

#ifndef __INET_MCOPACKET_M_H
#define __INET_MCOPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class MCOPacket;

}  // namespace inet

#include "inet/common/geometry/Geometry_m.h" // import inet.common.geometry.Geometry

#include "TrafficPacket_m.h" // import TrafficPacket


namespace inet {

/**
 * Class generated from <tt>inet/applications/vehicular/MCOPacket.msg:21</tt> by opp_msgtool.
 * <pre>
 * class MCOPacket extends TrafficPacket
 * {
 *     int source;
 *     int sequenceNumber;
 *     int channel;
 *     Coord position;
 * }
 * </pre>
 */
class INET_API MCOPacket : public ::inet::TrafficPacket
{
  protected:
    int source = 0;
    int sequenceNumber = 0;
    int channel = 0;
    Coord position;

  private:
    void copy(const MCOPacket& other);

  protected:
    bool operator==(const MCOPacket&) = delete;

  public:
    MCOPacket();
    MCOPacket(const MCOPacket& other);
    virtual ~MCOPacket();
    MCOPacket& operator=(const MCOPacket& other);
    virtual MCOPacket *dup() const override {return new MCOPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getSource() const;
    virtual void setSource(int source);

    virtual int getSequenceNumber() const;
    virtual void setSequenceNumber(int sequenceNumber);

    virtual int getChannel() const;
    virtual void setChannel(int channel);

    virtual const Coord& getPosition() const;
    virtual Coord& getPositionForUpdate() { handleChange();return const_cast<Coord&>(const_cast<MCOPacket*>(this)->getPosition());}
    virtual void setPosition(const Coord& position);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MCOPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MCOPacket& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::MCOPacket *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::MCOPacket*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_MCOPACKET_M_H

