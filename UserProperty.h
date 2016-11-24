#ifndef USERPROPERTY_H
#define USERPROPERTY_H

#include "Property.h"

class UserProperty : public Property
{
public:
    enum Role {
        ROLE_ADMIN,
        ROLE_USER
    };

    UserProperty() = default;
    void setFirstName(const QString& name);
    void setLastName(const QString& name);
    void setAddress(const QString& address);
    void setBanned(const bool banned);
    void setRole(const Role& role);
    void setPhoneNumber(const QString& pnumber);
    UserProperty(const QString& firstName, const QString& lastName,
                 const QString& address,
                 const bool banned, Role role, const QString& phoneNumber);
    UserProperty(const UserProperty& other);
    QString m_firstName;
    QString m_lastName;
    QString m_address;

    bool m_banned;

    Role m_role;
    QString m_phoneNumber;
};

#endif // USERPROPERTY_H
