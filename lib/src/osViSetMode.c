#include "libultra_internal.h"
extern OSViContext *__osViNext;
void osViSetMode(OSViMode *mode)
{
    register u32 int_disabled = __osDisableInt();
    __osViNext->unk08 = mode;
    __osViNext->unk00 = 1;
    __osViNext->features = __osViNext->unk08->comRegs.ctrl;
    __osRestoreInt(int_disabled);
}


/* Original file

/*====================================================================
 * visetmode.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *==================================================================== /

/**************************************************************************
 *
 *  $Revision: 1.3 $
 *  $Date: 1995/09/22 04:48:36 $
 *  $Source: /mdev2/PR/libultra/io/RCS/visetmode.c,v $
 *
 ************************************************************************** /


#include "osint.h"
#include "rcp.h"
#include "viint.h"
#include "assert.h"


/*
 * Name:   osViSetMode
 *
 * Description:
 *	Set the next VI mode (see os.h for the possible 28 modes)
 *
 * Globals Referenced: 
 *	__osViNext
 /
void
osViSetMode(OSViMode *modep)
{
    register u32 saveMask;
    
#ifdef _DEBUG
    /* Check that VI manager is running /
    if (!__osViDevMgr.active) {
	__osError(ERR_OSVISETMODE, 0);
	return;
    }
    /* Check for NULL pointer /
    assert(modep != NULL);
#endif

    /*
     * Set mode pointer and reset state variable 
     * In addition, all scaling factors are reset
     /
    saveMask = __osDisableInt();

    __osViNext->modep	= modep;
    __osViNext->state 	= (VI_STATE_NORMAL | VI_STATE_MODE);
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    
    __osRestoreInt(saveMask);

}  /* osViSetMode /

/*
