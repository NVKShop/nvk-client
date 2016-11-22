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
