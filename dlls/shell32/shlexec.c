/*
 * Copyright 2017 André Hentschel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/* NOTE: The guest side uses mingw's headers. The host side uses Wine's headers. */

#include <windows.h>
#include <stdio.h>

#include "windows-user-services.h"
#include "dll_list.h"
#include "qemu_shell32.h"

#ifndef QEMU_DLL_GUEST
#include <wine/debug.h>
WINE_DEFAULT_DEBUG_CHANNEL(qemu_shell32);
#endif


struct qemu_FindExecutableA
{
    struct qemu_syscall super;
    uint64_t lpFile;
    uint64_t lpDirectory;
    uint64_t lpResult;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HINSTANCE WINAPI FindExecutableA(LPCSTR lpFile, LPCSTR lpDirectory, LPSTR lpResult)
{
    struct qemu_FindExecutableA call;
    call.super.id = QEMU_SYSCALL_ID(CALL_FINDEXECUTABLEA);
    call.lpFile = (uint64_t)lpFile;
    call.lpDirectory = (uint64_t)lpDirectory;
    call.lpResult = (uint64_t)lpResult;

    qemu_syscall(&call.super);

    return (HINSTANCE)call.super.iret;
}

#else

void qemu_FindExecutableA(struct qemu_syscall *call)
{
    struct qemu_FindExecutableA *c = (struct qemu_FindExecutableA *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = (uint64_t)FindExecutableA(QEMU_G2H(c->lpFile), QEMU_G2H(c->lpDirectory), QEMU_G2H(c->lpResult));
}

#endif

struct qemu_FindExecutableW
{
    struct qemu_syscall super;
    uint64_t lpFile;
    uint64_t lpDirectory;
    uint64_t lpResult;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HINSTANCE WINAPI FindExecutableW(LPCWSTR lpFile, LPCWSTR lpDirectory, LPWSTR lpResult)
{
    struct qemu_FindExecutableW call;
    call.super.id = QEMU_SYSCALL_ID(CALL_FINDEXECUTABLEW);
    call.lpFile = (uint64_t)lpFile;
    call.lpDirectory = (uint64_t)lpDirectory;
    call.lpResult = (uint64_t)lpResult;

    qemu_syscall(&call.super);

    return (HINSTANCE)call.super.iret;
}

#else

void qemu_FindExecutableW(struct qemu_syscall *call)
{
    struct qemu_FindExecutableW *c = (struct qemu_FindExecutableW *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = (uint64_t)FindExecutableW(QEMU_G2H(c->lpFile), QEMU_G2H(c->lpDirectory), QEMU_G2H(c->lpResult));
}

#endif

struct qemu_ShellExecuteA
{
    struct qemu_syscall super;
    uint64_t hWnd;
    uint64_t lpVerb;
    uint64_t lpFile;
    uint64_t lpParameters;
    uint64_t lpDirectory;
    uint64_t iShowCmd;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HINSTANCE WINAPI ShellExecuteA(HWND hWnd, LPCSTR lpVerb, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT iShowCmd)
{
    struct qemu_ShellExecuteA call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SHELLEXECUTEA);
    call.hWnd = (uint64_t)hWnd;
    call.lpVerb = (uint64_t)lpVerb;
    call.lpFile = (uint64_t)lpFile;
    call.lpParameters = (uint64_t)lpParameters;
    call.lpDirectory = (uint64_t)lpDirectory;
    call.iShowCmd = (uint64_t)iShowCmd;

    qemu_syscall(&call.super);

    return (HINSTANCE)call.super.iret;
}

#else

void qemu_ShellExecuteA(struct qemu_syscall *call)
{
    struct qemu_ShellExecuteA *c = (struct qemu_ShellExecuteA *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = (uint64_t)ShellExecuteA(QEMU_G2H(c->hWnd), QEMU_G2H(c->lpVerb), QEMU_G2H(c->lpFile), QEMU_G2H(c->lpParameters), QEMU_G2H(c->lpDirectory), c->iShowCmd);
}

#endif

struct qemu_ShellExecuteExA
{
    struct qemu_syscall super;
    uint64_t sei;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI ShellExecuteExA (LPSHELLEXECUTEINFOA sei)
{
    struct qemu_ShellExecuteExA call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SHELLEXECUTEEXA);
    call.sei = (uint64_t)sei;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_ShellExecuteExA(struct qemu_syscall *call)
{
    struct qemu_ShellExecuteExA *c = (struct qemu_ShellExecuteExA *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = ShellExecuteExA(QEMU_G2H(c->sei));
}

#endif

struct qemu_ShellExecuteExW
{
    struct qemu_syscall super;
    uint64_t sei;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI ShellExecuteExW (LPSHELLEXECUTEINFOW sei)
{
    struct qemu_ShellExecuteExW call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SHELLEXECUTEEXW);
    call.sei = (uint64_t)sei;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_ShellExecuteExW(struct qemu_syscall *call)
{
    struct qemu_ShellExecuteExW *c = (struct qemu_ShellExecuteExW *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = ShellExecuteExW(QEMU_G2H(c->sei));
}

#endif

struct qemu_ShellExecuteW
{
    struct qemu_syscall super;
    uint64_t hwnd;
    uint64_t lpVerb;
    uint64_t lpFile;
    uint64_t lpParameters;
    uint64_t lpDirectory;
    uint64_t nShowCmd;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HINSTANCE WINAPI ShellExecuteW(HWND hwnd, LPCWSTR lpVerb, LPCWSTR lpFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd)
{
    struct qemu_ShellExecuteW call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SHELLEXECUTEW);
    call.hwnd = (uint64_t)hwnd;
    call.lpVerb = (uint64_t)lpVerb;
    call.lpFile = (uint64_t)lpFile;
    call.lpParameters = (uint64_t)lpParameters;
    call.lpDirectory = (uint64_t)lpDirectory;
    call.nShowCmd = (uint64_t)nShowCmd;

    qemu_syscall(&call.super);

    return (HINSTANCE)call.super.iret;
}

#else

void qemu_ShellExecuteW(struct qemu_syscall *call)
{
    struct qemu_ShellExecuteW *c = (struct qemu_ShellExecuteW *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = (uint64_t)ShellExecuteW(QEMU_G2H(c->hwnd), QEMU_G2H(c->lpVerb), QEMU_G2H(c->lpFile), QEMU_G2H(c->lpParameters), QEMU_G2H(c->lpDirectory), c->nShowCmd);
}

#endif

struct qemu_WOWShellExecute
{
    struct qemu_syscall super;
    uint64_t hWnd;
    uint64_t lpVerb;
    uint64_t lpFile;
    uint64_t lpParameters;
    uint64_t lpDirectory;
    uint64_t iShowCmd;
    uint64_t callback;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HINSTANCE WINAPI WOWShellExecute(HWND hWnd, LPCSTR lpVerb,LPCSTR lpFile, LPCSTR lpParameters,LPCSTR lpDirectory, INT iShowCmd, void *callback)
{
    struct qemu_WOWShellExecute call;
    call.super.id = QEMU_SYSCALL_ID(CALL_WOWSHELLEXECUTE);
    call.hWnd = (uint64_t)hWnd;
    call.lpVerb = (uint64_t)lpVerb;
    call.lpFile = (uint64_t)lpFile;
    call.lpParameters = (uint64_t)lpParameters;
    call.lpDirectory = (uint64_t)lpDirectory;
    call.iShowCmd = (uint64_t)iShowCmd;
    call.callback = (uint64_t)callback;

    qemu_syscall(&call.super);

    return (HINSTANCE)call.super.iret;
}

#else

/* TODO: Add WOWShellExecute to Wine headers? */
extern HINSTANCE WINAPI WOWShellExecute(HWND hWnd, LPCSTR lpVerb,LPCSTR lpFile, LPCSTR lpParameters,LPCSTR lpDirectory, INT iShowCmd, void *callback);
void qemu_WOWShellExecute(struct qemu_syscall *call)
{
    struct qemu_WOWShellExecute *c = (struct qemu_WOWShellExecute *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = (uint64_t)WOWShellExecute(QEMU_G2H(c->hWnd), QEMU_G2H(c->lpVerb), QEMU_G2H(c->lpFile), QEMU_G2H(c->lpParameters), QEMU_G2H(c->lpDirectory), c->iShowCmd, QEMU_G2H(c->callback));
}

#endif

struct qemu_OpenAs_RunDLLA
{
    struct qemu_syscall super;
    uint64_t hwnd;
    uint64_t hinst;
    uint64_t cmdline;
    uint64_t cmdshow;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI void WINAPI OpenAs_RunDLLA(HWND hwnd, HINSTANCE hinst, LPCSTR cmdline, int cmdshow)
{
    struct qemu_OpenAs_RunDLLA call;
    call.super.id = QEMU_SYSCALL_ID(CALL_OPENAS_RUNDLLA);
    call.hwnd = (uint64_t)hwnd;
    call.hinst = (uint64_t)hinst;
    call.cmdline = (uint64_t)cmdline;
    call.cmdshow = (uint64_t)cmdshow;

    qemu_syscall(&call.super);
}

#else

/* TODO: Add OpenAs_RunDLLA to Wine headers? */
extern void WINAPI OpenAs_RunDLLA(HWND hwnd, HINSTANCE hinst, LPCSTR cmdline, int cmdshow);
void qemu_OpenAs_RunDLLA(struct qemu_syscall *call)
{
    struct qemu_OpenAs_RunDLLA *c = (struct qemu_OpenAs_RunDLLA *)call;
    WINE_FIXME("Unverified!\n");
    OpenAs_RunDLLA(QEMU_G2H(c->hwnd), QEMU_G2H(c->hinst), QEMU_G2H(c->cmdline), c->cmdshow);
}

#endif

struct qemu_OpenAs_RunDLLW
{
    struct qemu_syscall super;
    uint64_t hwnd;
    uint64_t hinst;
    uint64_t cmdline;
    uint64_t cmdshow;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI void WINAPI OpenAs_RunDLLW(HWND hwnd, HINSTANCE hinst, LPCWSTR cmdline, int cmdshow)
{
    struct qemu_OpenAs_RunDLLW call;
    call.super.id = QEMU_SYSCALL_ID(CALL_OPENAS_RUNDLLW);
    call.hwnd = (uint64_t)hwnd;
    call.hinst = (uint64_t)hinst;
    call.cmdline = (uint64_t)cmdline;
    call.cmdshow = (uint64_t)cmdshow;

    qemu_syscall(&call.super);
}

#else

/* TODO: Add OpenAs_RunDLLW to Wine headers? */
extern void WINAPI OpenAs_RunDLLW(HWND hwnd, HINSTANCE hinst, LPCWSTR cmdline, int cmdshow);
void qemu_OpenAs_RunDLLW(struct qemu_syscall *call)
{
    struct qemu_OpenAs_RunDLLW *c = (struct qemu_OpenAs_RunDLLW *)call;
    WINE_FIXME("Unverified!\n");
    OpenAs_RunDLLW(QEMU_G2H(c->hwnd), QEMU_G2H(c->hinst), QEMU_G2H(c->cmdline), c->cmdshow);
}

#endif

struct qemu_RegenerateUserEnvironment
{
    struct qemu_syscall super;
    uint64_t wunknown;
    uint64_t bunknown;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI RegenerateUserEnvironment(WCHAR *wunknown, BOOL bunknown)
{
    struct qemu_RegenerateUserEnvironment call;
    call.super.id = QEMU_SYSCALL_ID(CALL_REGENERATEUSERENVIRONMENT);
    call.wunknown = (uint64_t)wunknown;
    call.bunknown = (uint64_t)bunknown;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

/* TODO: Add RegenerateUserEnvironment to Wine headers? */
extern BOOL WINAPI RegenerateUserEnvironment(WCHAR *wunknown, BOOL bunknown);
void qemu_RegenerateUserEnvironment(struct qemu_syscall *call)
{
    struct qemu_RegenerateUserEnvironment *c = (struct qemu_RegenerateUserEnvironment *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = RegenerateUserEnvironment(QEMU_G2H(c->wunknown), c->bunknown);
}

#endif

