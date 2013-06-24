/*
    Copyright 2013 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "networkmodelitem.h"

#include <KLocale>

NetworkModelItem::NetworkModelItem(NetworkModelItem::NetworkType type, const QString & path, QObject* parent):
    QObject(parent),
    m_type(type),
    m_path(path)
{
}

NetworkModelItem::~NetworkModelItem()
{
}

NetworkModelItem::NetworkType NetworkModelItem::type() const
{
    return m_type;
}

void NetworkModelItem::setType(NetworkModelItem::NetworkType type)
{
    m_type = type;
}

QString NetworkModelItem::path() const
{
    return m_path;
}

void NetworkModelItem::setPath(const QString & path)
{
    m_path = path;
}

QString NetworkModelItem::name() const
{
    if (m_type == NetworkModelItem::Bridge) {
        return i18n("Bridge");
    } else if (m_type == NetworkModelItem::Bond) {
        return i18n("Bond");
    } else if (m_type == NetworkModelItem::Ethernet) {
        return i18n("Ethernet");
    } else if (m_type == NetworkModelItem::Vlan) {
        return i18n("Vlan");
    } else if (m_type == NetworkModelItem::Vpn) {
        return i18n("Vpn");
    } else if (m_type == NetworkModelItem::Wifi) {
        return i18n("Wifi");
    }

    return i18n("Unknown");
}

QString NetworkModelItem::svgIcon() const
{
    if (m_type == NetworkModelItem::Bridge) {
        // TODO: missing Bridge icon
        return "network-wired-activated";
    } else if (m_type == NetworkModelItem::Bond) {
        // TODO: missing Bond icon
        return "network-wired-activated";
    } else if (m_type == NetworkModelItem::Ethernet) {
        return "network-wired-activated";
    } else if (m_type == NetworkModelItem::Vlan) {
        // TODO: missing Vlan icon
        return "network-wired-activated";
    } else if (m_type == NetworkModelItem::Vpn) {
        // TODO: missing VPN icon
        return "network-wired";
    } else if (m_type == NetworkModelItem::Wifi) {
        return "network-wireless-100";
    }

    return "network-wired";
}

QString NetworkModelItem::icon() const
{
    if (m_type == NetworkModelItem::Bridge) {
        // TODO: missing Bridge icon
        return "network-wired";
    } else if (m_type == NetworkModelItem::Bond) {
        // TODO: missing Bond icon
        return "network-wired";
    } else if (m_type == NetworkModelItem::Ethernet) {
        return "network-wired";
    } else if (m_type == NetworkModelItem::Vlan) {
        // TODO: missing Vlan icon
        return "network-wired";
    } else if (m_type == NetworkModelItem::Vpn) {
        return "secure-card";
    } else if (m_type == NetworkModelItem::Wifi) {
        return "network-wireless";
    }

    return "network-wired";
}

bool NetworkModelItem::isRemovable() const
{
    if (m_type == NetworkModelItem::Wifi || m_type == NetworkModelItem::Ethernet) {
        return false;
    }

    return true;
}
