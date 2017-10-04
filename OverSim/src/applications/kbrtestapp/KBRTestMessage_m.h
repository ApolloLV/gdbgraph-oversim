//
// Generated file, do not edit! Created by opp_msgc 4.2 from applications/kbrtestapp/KBRTestMessage.msg.
//

#ifndef _KBRTESTMESSAGE_M_H_
#define _KBRTESTMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <OverlayKey.h>
#include <IPvXAddress.h>
#include <CommonMessages_m.h>
// }}



/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet KBRTestMessage
 * {
 *     int id;                 
 *     int seqNum;             
 *     bool measurementPhase;  
 *     IPvXAddress visitedNodes[];
 * }
 * </pre>
 */
class KBRTestMessage : public ::cPacket
{
  protected:
    int id_var;
    int seqNum_var;
    bool measurementPhase_var;
    IPvXAddress *visitedNodes_var; // array ptr
    unsigned int visitedNodes_arraysize;

  private:
    void copy(const KBRTestMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KBRTestMessage&);

  public:
    KBRTestMessage(const char *name=NULL, int kind=0);
    KBRTestMessage(const KBRTestMessage& other);
    virtual ~KBRTestMessage();
    KBRTestMessage& operator=(const KBRTestMessage& other);
    virtual KBRTestMessage *dup() const {return new KBRTestMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getSeqNum() const;
    virtual void setSeqNum(int seqNum);
    virtual bool getMeasurementPhase() const;
    virtual void setMeasurementPhase(bool measurementPhase);
    virtual void setVisitedNodesArraySize(unsigned int size);
    virtual unsigned int getVisitedNodesArraySize() const;
    virtual IPvXAddress& getVisitedNodes(unsigned int k);
    virtual const IPvXAddress& getVisitedNodes(unsigned int k) const {return const_cast<KBRTestMessage*>(this)->getVisitedNodes(k);}
    virtual void setVisitedNodes(unsigned int k, const IPvXAddress& visitedNodes);
};

inline void doPacking(cCommBuffer *b, KBRTestMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, KBRTestMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet KbrTestCall extends BaseCallMessage
 * {
 * }
 * </pre>
 */
class KbrTestCall : public ::BaseCallMessage
{
  protected:

  private:
    void copy(const KbrTestCall& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KbrTestCall&);

  public:
    KbrTestCall(const char *name=NULL, int kind=0);
    KbrTestCall(const KbrTestCall& other);
    virtual ~KbrTestCall();
    KbrTestCall& operator=(const KbrTestCall& other);
    virtual KbrTestCall *dup() const {return new KbrTestCall(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, KbrTestCall& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, KbrTestCall& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet KbrTestResponse extends BaseResponseMessage
 * {
 * }
 * </pre>
 */
class KbrTestResponse : public ::BaseResponseMessage
{
  protected:

  private:
    void copy(const KbrTestResponse& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KbrTestResponse&);

  public:
    KbrTestResponse(const char *name=NULL, int kind=0);
    KbrTestResponse(const KbrTestResponse& other);
    virtual ~KbrTestResponse();
    KbrTestResponse& operator=(const KbrTestResponse& other);
    virtual KbrTestResponse *dup() const {return new KbrTestResponse(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, KbrTestResponse& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, KbrTestResponse& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet UnderlayTestCall extends BaseCallMessage
 * {
 *     simtime_t sendTime;
 * }
 * </pre>
 */
class UnderlayTestCall : public ::BaseCallMessage
{
  protected:
    simtime_t sendTime_var;

  private:
    void copy(const UnderlayTestCall& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UnderlayTestCall&);

  public:
    UnderlayTestCall(const char *name=NULL, int kind=0);
    UnderlayTestCall(const UnderlayTestCall& other);
    virtual ~UnderlayTestCall();
    UnderlayTestCall& operator=(const UnderlayTestCall& other);
    virtual UnderlayTestCall *dup() const {return new UnderlayTestCall(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getSendTime() const;
    virtual void setSendTime(simtime_t sendTime);
};

inline void doPacking(cCommBuffer *b, UnderlayTestCall& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, UnderlayTestCall& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet UnderlayTestResponse extends BaseResponseMessage
 * {
 *     simtime_t oneWayLatency;
 * }
 * </pre>
 */
class UnderlayTestResponse : public ::BaseResponseMessage
{
  protected:
    simtime_t oneWayLatency_var;

  private:
    void copy(const UnderlayTestResponse& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UnderlayTestResponse&);

  public:
    UnderlayTestResponse(const char *name=NULL, int kind=0);
    UnderlayTestResponse(const UnderlayTestResponse& other);
    virtual ~UnderlayTestResponse();
    UnderlayTestResponse& operator=(const UnderlayTestResponse& other);
    virtual UnderlayTestResponse *dup() const {return new UnderlayTestResponse(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getOneWayLatency() const;
    virtual void setOneWayLatency(simtime_t oneWayLatency);
};

inline void doPacking(cCommBuffer *b, UnderlayTestResponse& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, UnderlayTestResponse& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/kbrtestapp/KBRTestMessage.msg</tt> by opp_msgc.
 * <pre>
 * class KbrRpcContext
 * {
 *     OverlayKey destKey = OverlayKey::UNSPECIFIED_KEY; 
 *     TransportAddress destAddr = TransportAddress::UNSPECIFIED_NODE; 
 *     bool measurementPhase;  
 * }
 * </pre>
 */
class KbrRpcContext : public ::cObject
{
  protected:
    OverlayKey destKey_var;
    TransportAddress destAddr_var;
    bool measurementPhase_var;

  private:
    void copy(const KbrRpcContext& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const KbrRpcContext&);

  public:
    KbrRpcContext();
    KbrRpcContext(const KbrRpcContext& other);
    virtual ~KbrRpcContext();
    KbrRpcContext& operator=(const KbrRpcContext& other);
    virtual KbrRpcContext *dup() const {return new KbrRpcContext(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual OverlayKey& getDestKey();
    virtual const OverlayKey& getDestKey() const {return const_cast<KbrRpcContext*>(this)->getDestKey();}
    virtual void setDestKey(const OverlayKey& destKey);
    virtual TransportAddress& getDestAddr();
    virtual const TransportAddress& getDestAddr() const {return const_cast<KbrRpcContext*>(this)->getDestAddr();}
    virtual void setDestAddr(const TransportAddress& destAddr);
    virtual bool getMeasurementPhase() const;
    virtual void setMeasurementPhase(bool measurementPhase);
};

inline void doPacking(cCommBuffer *b, KbrRpcContext& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, KbrRpcContext& obj) {obj.parsimUnpack(b);}


#endif // _KBRTESTMESSAGE_M_H_
