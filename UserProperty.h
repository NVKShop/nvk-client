#ifndef USERPROPERTY_H
#define USERPROPERTY_H

#include "Property.h"

class UserProperty : public Property
{
public:
    QString m_address;
    QString m_firstName;
    QString m_lastName;
    bool m_banned;
    enum Role {
        ROLE_ADMIN,
        ROLE_USER
    };
    Role m_role;
    QString m_phoneNumber;
};

#endif // USERPROPERTY_H
