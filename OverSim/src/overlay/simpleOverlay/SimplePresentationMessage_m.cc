//
// Generated file, do not edit! Created by opp_msgc 4.2 from overlay/simpleOverlay/SimplePresentationMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SimplePresentationMessage_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(SimplePresentationMessage);

SimplePresentationMessage::SimplePresentationMessage(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
}

SimplePresentationMessage::SimplePresentationMessage(const SimplePresentationMessage& other) : BaseOverlayMessage(other)
{
    copy(other);
}

SimplePresentationMessage::~SimplePresentationMessage()
{
}

SimplePresentationMessage& SimplePresentationMessage::operator=(const SimplePresentationMessage& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    copy(other);
    return *this;
}

void SimplePresentationMessage::copy(const SimplePresentationMessage& other)
{
    this->content_var = other.content_var;
}

void SimplePresentationMessage::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
    doPacking(b,this->content_var);
}

void SimplePresentationMessage::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
    doUnpacking(b,this->content_var);
}

NodeHandle& SimplePresentationMessage::getContent()
{
    return content_var;
}

void SimplePresentationMessage::setContent(const NodeHandle& content)
{
    this->content_var = content;
}

class SimplePresentationMessageDescriptor : public cClassDescriptor
{
  public:
    SimplePresentationMessageDescriptor();
    virtual ~SimplePresentationMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SimplePresentationMessageDescriptor);

SimplePresentationMessageDescriptor::SimplePresentationMessageDescriptor() : cClassDescriptor("SimplePresentationMessage", "BaseOverlayMessage")
{
}

SimplePresentationMessageDescriptor::~SimplePresentationMessageDescriptor()
{
}

bool SimplePresentationMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SimplePresentationMessage *>(obj)!=NULL;
}

const char *SimplePresentationMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SimplePresentationMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SimplePresentationMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *SimplePresentationMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "content",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SimplePresentationMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "content")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SimplePresentationMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "NodeHandle",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SimplePresentationMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SimplePresentationMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SimplePresentationMessage *pp = (SimplePresentationMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SimplePresentationMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SimplePresentationMessage *pp = (SimplePresentationMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getContent(); return out.str();}
        default: return "";
    }
}

bool SimplePresentationMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SimplePresentationMessage *pp = (SimplePresentationMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SimplePresentationMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "NodeHandle",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *SimplePresentationMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SimplePresentationMessage *pp = (SimplePresentationMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getContent()); break;
        default: return NULL;
    }
}


