/*
    SPDX-FileCopyrightText: 2015 Martin Gräßlin <mgraesslin@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/
#pragma once

#include <QMarginsF>
#include <QObject>

#include <KWaylandServer/kwaylandserver_export.h>

struct wl_resource;

namespace KWaylandServer
{
class ClientBuffer;
class Display;
class ShadowManagerInterfacePrivate;
class ShadowInterfacePrivate;

class KWAYLANDSERVER_EXPORT ShadowManagerInterface : public QObject
{
    Q_OBJECT

public:
    explicit ShadowManagerInterface(Display *display, QObject *parent = nullptr);
    ~ShadowManagerInterface() override;

    Display *display() const;

private:
    QScopedPointer<ShadowManagerInterfacePrivate> d;
};

class KWAYLANDSERVER_EXPORT ShadowInterface : public QObject
{
    Q_OBJECT
public:
    ~ShadowInterface() override;

    ClientBuffer *left() const;
    ClientBuffer *topLeft() const;
    ClientBuffer *top() const;
    ClientBuffer *topRight() const;
    ClientBuffer *right() const;
    ClientBuffer *bottomRight() const;
    ClientBuffer *bottom() const;
    ClientBuffer *bottomLeft() const;

    QMarginsF offset() const;

private:
    explicit ShadowInterface(ShadowManagerInterface *manager, wl_resource *resource);
    friend class ShadowManagerInterfacePrivate;

    QScopedPointer<ShadowInterfacePrivate> d;
};

}
