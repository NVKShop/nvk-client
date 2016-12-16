#ifndef USERPROPERTY_H
#define USERPROPERTY_H

#include "backend/Property.h"
#include "backend/Address.h"

class UserProperty : public Property
{
public:
    enum Role {
        ROLE_ADMIN = 0,
        ROLE_USER
    };

    UserProperty() = default;
    void setEmail(const QString& email);
    void setFirstName(const QString& name);
    void setLastName(const QString& name);
    void setAddress(const Address& address);
    void setBanned(const bool banned);
    void setRole(const Role& role);
    void setPhoneNumber(const QString& pnumber);
    void setPassword(const QString& pw);
    UserProperty(const long &id, const QString& firstName, const QString& lastName,
                 const Address &address,
                 const bool banned, Role role, const QString& phoneNumber, const QString &pw);

    QString firstName() const;
    QString lastName() const;
    Address address() const;
    QString email() const;
    bool isBanned() const;
    Role role() const;
    QString phoneNumber() const;
    QString password() const;
private:
    QString m_firstName;
    QString m_lastName;
    Address m_address;
    QString m_email;
    bool m_banned = false;

    Role m_role;

    QString m_phoneNumber;
    QString m_password;
};

#endif // USERPROPERTY_H
