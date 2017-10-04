//
// Generated file, do not edit! Created by opp_msgc 4.2 from overlay/broose/BrooseMessage.msg.
//

#ifndef _BROOSEMESSAGE_M_H_
#define _BROOSEMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <IPvXAddress.h>
#include <NodeHandle.h>
#include <CommonMessages_m.h>
#include <OverlayKey.h>


static const int INDEX_L = 8;
static const int BUCKETTYPE_L = 2;
static const int PROTOSTATE_L = 2;
static const int STEP_L = 8;
static const int RIGHTSHIFTING_L = 1;
static const int NODENUM_L = 8;

#define BUCKETCALL_L(msg) (BASECALL_L(msg) + INDEX_L + BUCKETTYPE_L + PROTOSTATE_L)
#define BUCKETRESPONSE_L(msg) (BASERESPONSE_L(msg) + NODENUM_L \
	                       + msg->getNodesArraySize() * NODEHANDLE_L)
#define BROOSEFINDNODEEXTMESSAGE_L (KEY_L + STEP_L + RIGHTSHIFTING_L + NODEHANDLE_L)
// }}



/**
 * Enum generated from <tt>overlay/broose/BrooseMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum BucketType
 * {
 * 
 *     RIGHT = 0;
 *     LEFT = 1;
 *     BROTHER = 2;
 * }
 * </pre>
 */
enum BucketType {
    RIGHT = 0,
    LEFT = 1,
    BROTHER = 2
};

/**
 * Enum generated from <tt>overlay/broose/BrooseMessage.msg</tt> by opp_msgc.
 * <pre>
 * enum ProState
 * {
 * 
 *     PINIT = 0;
 *     PRSET = 1;
 *     PBSET = 2;
 *     PREADY = 3;
 * }
 * </pre>
 */
enum ProState {
    PINIT = 0,
    PRSET = 1,
    PBSET = 2,
    PREADY = 3
};

/**
 * Class generated from <tt>overlay/broose/BrooseMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet BucketCall extends BaseCallMessage
 * {
 *         int bucketType enum(BucketType);  
 *         int bucketIndex;                  
 *         int proState enum(ProState);      
 * }
 * </pre>
 */
class BucketCall : public ::BaseCallMessage
{
  protected:
    int bucketType_var;
    int bucketIndex_var;
    int proState_var;

  private:
    void copy(const BucketCall& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BucketCall&);

  public:
    BucketCall(const char *name=NULL, int kind=0);
    BucketCall(const BucketCall& other);
    virtual ~BucketCall();
    BucketCall& operator=(const BucketCall& other);
    virtual BucketCall *dup() const {return new BucketCall(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getBucketType() const;
    virtual void setBucketType(int bucketType);
    virtual int getBucketIndex() const;
    virtual void setBucketIndex(int bucketIndex);
    virtual int getProState() const;
    virtual void setProState(int proState);
};

inline void doPacking(cCommBuffer *b, BucketCall& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BucketCall& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/broose/BrooseMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet BucketResponse extends BaseResponseMessage
 * {
 *        NodeHandle nodes[];    
 * }
 * </pre>
 */
class BucketResponse : public ::BaseResponseMessage
{
  protected:
    NodeHandle *nodes_var; // array ptr
    unsigned int nodes_arraysize;

  private:
    void copy(const BucketResponse& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BucketResponse&);

  public:
    BucketResponse(const char *name=NULL, int kind=0);
    BucketResponse(const BucketResponse& other);
    virtual ~BucketResponse();
    BucketResponse& operator=(const BucketResponse& other);
    virtual BucketResponse *dup() const {return new BucketResponse(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setNodesArraySize(unsigned int size);
    virtual unsigned int getNodesArraySize() const;
    virtual NodeHandle& getNodes(unsigned int k);
    virtual const NodeHandle& getNodes(unsigned int k) const {return const_cast<BucketResponse*>(this)->getNodes(k);}
    virtual void setNodes(unsigned int k, const NodeHandle& nodes);
};

inline void doPacking(cCommBuffer *b, BucketResponse& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BucketResponse& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>overlay/broose/BrooseMessage.msg</tt> by opp_msgc.
 * <pre>
 * packet BrooseFindNodeExtMessage
 * {
 *         OverlayKey routeKey;   
 *         int step;              
 *         int maxDistance;       
 *         bool rightShifting;    
 *         NodeHandle lastNode;   
 * }
 * </pre>
 */
class BrooseFindNodeExtMessage : public ::cPacket
{
  protected:
    OverlayKey routeKey_var;
    int step_var;
    int maxDistance_var;
    bool rightShifting_var;
    NodeHandle lastNode_var;

  private:
    void copy(const BrooseFindNodeExtMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BrooseFindNodeExtMessage&);

  public:
    BrooseFindNodeExtMessage(const char *name=NULL, int kind=0);
    BrooseFindNodeExtMessage(const BrooseFindNodeExtMessage& other);
    virtual ~BrooseFindNodeExtMessage();
    BrooseFindNodeExtMessage& operator=(const BrooseFindNodeExtMessage& other);
    virtual BrooseFindNodeExtMessage *dup() const {return new BrooseFindNodeExtMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual OverlayKey& getRouteKey();
    virtual const OverlayKey& getRouteKey() const {return const_cast<BrooseFindNodeExtMessage*>(this)->getRouteKey();}
    virtual void setRouteKey(const OverlayKey& routeKey);
    virtual int getStep() const;
    virtual void setStep(int step);
    virtual int getMaxDistance() const;
    virtual void setMaxDistance(int maxDistance);
    virtual bool getRightShifting() const;
    virtual void setRightShifting(bool rightShifting);
    virtual NodeHandle& getLastNode();
    virtual const NodeHandle& getLastNode() const {return const_cast<BrooseFindNodeExtMessage*>(this)->getLastNode();}
    virtual void setLastNode(const NodeHandle& lastNode);
};

inline void doPacking(cCommBuffer *b, BrooseFindNodeExtMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BrooseFindNodeExtMessage& obj) {obj.parsimUnpack(b);}


#endif // _BROOSEMESSAGE_M_H_