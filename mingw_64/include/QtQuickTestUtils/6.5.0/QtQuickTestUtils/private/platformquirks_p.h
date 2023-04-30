// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#ifndef PLATFORMQUIRKS_P_H
#define PLATFORMQUIRKS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <private/qglobal_p.h>

#ifdef Q_OS_OSX
#include <Carbon/Carbon.h>
#endif

QT_BEGIN_NAMESPACE

struct PlatformQuirks
{
    static inline bool isClipboardAvailable()
    {
#if !QT_CONFIG(clipboard)
        return false;
#elif defined(Q_OS_OSX)
        PasteboardRef pasteboard;
        OSStatus status = PasteboardCreate(0, &pasteboard);
        if (status == noErr)
            CFRelease(pasteboard);
        return status == noErr;
#else
        return true;
#endif
    }
};

QT_END_NAMESPACE

#endif
