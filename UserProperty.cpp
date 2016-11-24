#include "UserProperty.h"

UserProperty::UserProperty(const QString &firstName,
                           const QString &lastName,
                           const QString &address,
                           const bool banned,
                           UserProperty::Role role,
                           const QString &phoneNumber): Property(firstName),
    m_firstName(firstName), m_lastName(lastName), m_address(address), m_banned(banned), m_role(role),
    m_phoneNumber(phoneNumber)
{
}

UserProperty::UserProperty(const UserProperty &other)
{
    UserProperty(other.m_firstName, other.m_lastName, other.m_address, other.m_banned, other.m_role, other.m_phoneNumber);
}

void UserProperty::setAddress(const QString &address)
{
    m_address = address;
}

void UserProperty::setBanned(const bool banned)
{
    m_banned = banned;
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
