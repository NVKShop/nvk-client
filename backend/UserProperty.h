#ifndef USERPROPERTY_H
#define USERPROPERTY_H

#include "backend/Property.h"
#include "backend/Address.h"

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
    void setAddress(const Address& address);
    void setBanned(const bool banned);
    void setRole(const Role& role);
    void setPhoneNumber(const QString& pnumber);
    UserProperty(const QString& firstName, const QString& lastName,
                 const Address &address,
                 const bool banned, Role role, const QString& phoneNumber);
    UserProperty(const UserProperty& other);

    QString firstName() const;
    QString lastName() const;
    Address address() const;
    QString email() const;
    bool isBanned() const;
    Role role() const;
    QString phoneNumber() const;
private:
    QString m_firstName;
    QString m_lastName;
    Address m_address;
    QString m_email;
    bool m_banned;

    Role m_role;
    QString m_phoneNumber;
};

#endif // USERPROPERTY_H
