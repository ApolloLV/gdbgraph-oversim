//
// Generated file, do not edit! Created by opp_msgc 4.2 from overlay/SelfStabilizingGeneralDeBruijnGraph/GeneralDeBruijnMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "GeneralDeBruijnMessage_m.h"

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




Register_Class(GeneralDeBruijnMessage);

GeneralDeBruijnMessage::GeneralDeBruijnMessage(const char *name, int kind) : BaseOverlayMessage(name,kind)
{
    this->command_var = 0;
    this->r_var = 0;
    this->remHops_var = 0;
    this->mode_var = 0;
    this->i_var = 0;
    this->j_var = 0;
    this->dB_var = 0;
}

GeneralDeBruijnMessage::GeneralDeBruijnMessage(const GeneralDeBruijnMessage& other) : BaseOverlayMessage(other)
{
    copy(other);
}

GeneralDeBruijnMessage::~GeneralDeBruijnMessage()
{
}

GeneralDeBruijnMessage& GeneralDeBruijnMessage::operator=(const GeneralDeBruijnMessage& other)
{
    if (this==&other) return *this;
    BaseOverlayMessage::operator=(other);
    copy(other);
    return *this;
}

void GeneralDeBruijnMessage::copy(const GeneralDeBruijnMessage& other)
{
    this->command_var = other.command_var;
    this->t_var = other.t_var;
    this->r_var = other.r_var;
    this->remHops_var = other.remHops_var;
    this->u_var = other.u_var;
    this->qtilde_var = other.qtilde_var;
    this->sender_var = other.sender_var;
    this->result_var = other.result_var;
    this->mode_var = other.mode_var;
    this->i_var = other.i_var;
    this->j_var = other.j_var;
    this->dB_var = other.dB_var;
}

void GeneralDeBruijnMessage::parsimPack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimPack(b);
    doPacking(b,this->command_var);
    doPacking(b,this->t_var);
    doPacking(b,this->r_var);
    doPacking(b,this->remHops_var);
    doPacking(b,this->u_var);
    doPacking(b,this->qtilde_var);
    doPacking(b,this->sender_var);
    doPacking(b,this->result_var);
    doPacking(b,this->mode_var);
    doPacking(b,this->i_var);
    doPacking(b,this->j_var);
    doPacking(b,this->dB_var);
}

void GeneralDeBruijnMessage::parsimUnpack(cCommBuffer *b)
{
    BaseOverlayMessage::parsimUnpack(b);
    doUnpacking(b,this->command_var);
    doUnpacking(b,this->t_var);
    doUnpacking(b,this->r_var);
    doUnpacking(b,this->remHops_var);
    doUnpacking(b,this->u_var);
    doUnpacking(b,this->qtilde_var);
    doUnpacking(b,this->sender_var);
    doUnpacking(b,this->result_var);
    doUnpacking(b,this->mode_var);
    doUnpacking(b,this->i_var);
    doUnpacking(b,this->j_var);
    doUnpacking(b,this->dB_var);
}

int GeneralDeBruijnMessage::getCommand() const
{
    return command_var;
}

void GeneralDeBruijnMessage::setCommand(int command)
{
    this->command_var = command;
}

DeBruijnNodeHandle& GeneralDeBruijnMessage::getT()
{
    return t_var;
}

void GeneralDeBruijnMessage::setT(const DeBruijnNodeHandle& t)
{
    this->t_var = t;
}

double GeneralDeBruijnMessage::getR() const
{
    return r_var;
}

void GeneralDeBruijnMessage::setR(double r)
{
    this->r_var = r;
}

int GeneralDeBruijnMessage::getRemHops() const
{
    return remHops_var;
}

void GeneralDeBruijnMessage::setRemHops(int remHops)
{
    this->remHops_var = remHops;
}

DeBruijnNodeHandle& GeneralDeBruijnMessage::getU()
{
    return u_var;
}

void GeneralDeBruijnMessage::setU(const DeBruijnNodeHandle& u)
{
    this->u_var = u;
}

DeBruijnNodeHandle& GeneralDeBruijnMessage::getQtilde()
{
    return qtilde_var;
}

void GeneralDeBruijnMessage::setQtilde(const DeBruijnNodeHandle& qtilde)
{
    this->qtilde_var = qtilde;
}

DeBruijnNodeHandle& GeneralDeBruijnMessage::getSender()
{
    return sender_var;
}

void GeneralDeBruijnMessage::setSender(const DeBruijnNodeHandle& sender)
{
    this->sender_var = sender;
}

DeBruijnNodeHandle& GeneralDeBruijnMessage::getResult()
{
    return result_var;
}

void GeneralDeBruijnMessage::setResult(const DeBruijnNodeHandle& result)
{
    this->result_var = result;
}

const char * GeneralDeBruijnMessage::getMode() const
{
    return mode_var.c_str();
}

void GeneralDeBruijnMessage::setMode(const char * mode)
{
    this->mode_var = mode;
}

int GeneralDeBruijnMessage::getI() const
{
    return i_var;
}

void GeneralDeBruijnMessage::setI(int i)
{
    this->i_var = i;
}

int GeneralDeBruijnMessage::getJ() const
{
    return j_var;
}

void GeneralDeBruijnMessage::setJ(int j)
{
    this->j_var = j;
}

bool GeneralDeBruijnMessage::getDB() const
{
    return dB_var;
}

void GeneralDeBruijnMessage::setDB(bool dB)
{
    this->dB_var = dB;
}

class GeneralDeBruijnMessageDescriptor : public cClassDescriptor
{
  public:
    GeneralDeBruijnMessageDescriptor();
    virtual ~GeneralDeBruijnMessageDescriptor();

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

Register_ClassDescriptor(GeneralDeBruijnMessageDescriptor);

GeneralDeBruijnMessageDescriptor::GeneralDeBruijnMessageDescriptor() : cClassDescriptor("GeneralDeBruijnMessage", "BaseOverlayMessage")
{
}

GeneralDeBruijnMessageDescriptor::~GeneralDeBruijnMessageDescriptor()
{
}

bool GeneralDeBruijnMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<GeneralDeBruijnMessage *>(obj)!=NULL;
}

const char *GeneralDeBruijnMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int GeneralDeBruijnMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int GeneralDeBruijnMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *GeneralDeBruijnMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "command",
        "t",
        "r",
        "remHops",
        "u",
        "qtilde",
        "sender",
        "result",
        "mode",
        "i",
        "j",
        "dB",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int GeneralDeBruijnMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "t")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "r")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remHops")==0) return base+3;
    if (fieldName[0]=='u' && strcmp(fieldName, "u")==0) return base+4;
    if (fieldName[0]=='q' && strcmp(fieldName, "qtilde")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "result")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "mode")==0) return base+8;
    if (fieldName[0]=='i' && strcmp(fieldName, "i")==0) return base+9;
    if (fieldName[0]=='j' && strcmp(fieldName, "j")==0) return base+10;
    if (fieldName[0]=='d' && strcmp(fieldName, "dB")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *GeneralDeBruijnMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "DeBruijnNodeHandle",
        "double",
        "int",
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        "string",
        "int",
        "int",
        "bool",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *GeneralDeBruijnMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int GeneralDeBruijnMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    GeneralDeBruijnMessage *pp = (GeneralDeBruijnMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string GeneralDeBruijnMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    GeneralDeBruijnMessage *pp = (GeneralDeBruijnMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCommand());
        case 1: {std::stringstream out; out << pp->getT(); return out.str();}
        case 2: return double2string(pp->getR());
        case 3: return long2string(pp->getRemHops());
        case 4: {std::stringstream out; out << pp->getU(); return out.str();}
        case 5: {std::stringstream out; out << pp->getQtilde(); return out.str();}
        case 6: {std::stringstream out; out << pp->getSender(); return out.str();}
        case 7: {std::stringstream out; out << pp->getResult(); return out.str();}
        case 8: return oppstring2string(pp->getMode());
        case 9: return long2string(pp->getI());
        case 10: return long2string(pp->getJ());
        case 11: return bool2string(pp->getDB());
        default: return "";
    }
}

bool GeneralDeBruijnMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    GeneralDeBruijnMessage *pp = (GeneralDeBruijnMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand(string2long(value)); return true;
        case 2: pp->setR(string2double(value)); return true;
        case 3: pp->setRemHops(string2long(value)); return true;
        case 8: pp->setMode((value)); return true;
        case 9: pp->setI(string2long(value)); return true;
        case 10: pp->setJ(string2long(value)); return true;
        case 11: pp->setDB(string2bool(value)); return true;
        default: return false;
    }
}

const char *GeneralDeBruijnMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "DeBruijnNodeHandle",
        NULL,
        NULL,
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        "DeBruijnNodeHandle",
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<12) ? fieldStructNames[field] : NULL;
}

void *GeneralDeBruijnMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    GeneralDeBruijnMessage *pp = (GeneralDeBruijnMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getT()); break;
        case 4: return (void *)(&pp->getU()); break;
        case 5: return (void *)(&pp->getQtilde()); break;
        case 6: return (void *)(&pp->getSender()); break;
        case 7: return (void *)(&pp->getResult()); break;
        default: return NULL;
    }
}


