#include "backend/UserProperty.h"

UserProperty::UserProperty(const long& id, const QString &firstName,
                           const QString &lastName,
                           const Address &address,
                           const bool banned,
                           UserProperty::Role role,
                           const QString &phoneNumber, const QString& pw): Property(id,firstName),
    m_firstName(firstName), m_lastName(lastName), m_address(address), m_banned(banned), m_role(role),
    m_phoneNumber(phoneNumber), m_password(pw)
{
}

void UserProperty::setAddress(const Address &address)
{
    m_address = address;
}

void UserProperty::setBanned(const bool banned)
{
    m_banned = banned;
}

void UserProperty::setEmail(const QString &email)
{
    m_email = email;
}

void UserProperty::setFirstName(const QString &name)
{
    m_firstName = name;
}

void UserProperty::setLastName(const QString &name)
{
    m_lastName = name;
}

void UserProperty::setPhoneNumber(const QString &pnumber)
{
    m_phoneNumber = pnumber;
}

void UserProperty::setPassword(const QString &pw)
{
    m_password = pw;
}

void UserProperty::setRole(const UserProperty::Role &role)
{
    m_role = role;
}

QString UserProperty::firstName() const
{
    return m_firstName;
}

QString UserProperty::lastName() const
{
    return m_lastName;
}

Address UserProperty::address() const
{
    return m_address;
}

QString UserProperty::phoneNumber() const
{
    return m_phoneNumber;
}

QString UserProperty::password() const
{
    return m_password;
}

QString UserProperty::email() const
{
    return m_email;
}

UserProperty::Role UserProperty::role() const
{
    return m_role;
}

bool UserProperty::isBanned() const
{
    return m_banned;
}


