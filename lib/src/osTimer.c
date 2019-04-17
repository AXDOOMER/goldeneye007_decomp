#include "libultra_internal.h"

OSTimer aTimer;

// This timer is the first node in a circular doubly-linked list of timers
OSTimer *firstTimer = &aTimer;

OSTime _osCurrentTime;


// Count at last VI manager loop
u32 lastViCount;
/* 
 * Global variable  for the count reigster value from last retrace 
 * interrupt
 */
//u32	__osBaseCounter;

// This variable is set to 0 here, incremented in viMgrMain, but never read from.
// Looks useless.
//u32 D_80365DAC;
u32	__osViIntrCount;	/* # of  VI interrupts */

//Its nice to see these files coming out more or less exactly as source is written.
//now just need to refactor variable names to original


// Count at last interrupt
u32 lastIntCount;

void __osTimerServicesInit()
{
    _osCurrentTime = 0;
    lastViCount = 0;
    __osViIntrCount = 0;

    // Init the Circular Linked List
    firstTimer->prev = firstTimer;
    firstTimer->next = firstTimer->prev;

    // Init the first element of this list
    firstTimer->remaining = 0;
    firstTimer->interval = firstTimer->remaining;
    firstTimer->mq = NULL;
    firstTimer->msg = NULL;
}

void __osTimerInterrupt()
{
    // Pointer used to iterate on the list of timers
    OSTimer *node;
    u32 newCount;

    // Difference between the new count and the count from the last call to
    // osGetCount() in __osSetTimerIntr(u64 a0)
    u32 diff;

    // The list of timers is empty
    if (firstTimer->next == firstTimer)
        return;

    while (1)
    {
        node = firstTimer->next;
        if (node == firstTimer)
        {
            __osSetCompare(0);
            lastIntCount = 0;
            break;
        }

        // Get the count register of CPU with osGetCount()
        newCount = osGetCount();
        diff = newCount - lastIntCount;
        lastIntCount = newCount;

        if (diff < node->remaining)
        {
            node->remaining -= diff;
            __osSetTimerIntr(node->remaining);
            return;
        }
        else
        {
            // Unlink this timer from the list
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = NULL;
            node->prev = NULL;

            // Copy the timer's message to the message queue
            if (node->mq != NULL)
            {
                osSendMesg(node->mq, node->msg, OS_MESG_NOBLOCK);
            }

            // Reinsert into the linked list if it's an interval timer
            if (node->interval != 0)
            {
                node->remaining = node->interval;
                __osInsertTimer(node);
            }
        }
    }
}

void __osSetTimerIntr(u64 remaining)
{
    u64 tmp;
    s32 saveMask = __osDisableInt();

    // http://n64devkit.square7.ch/n64man/os/osGetCount.htm
    lastIntCount = osGetCount();

    // Interesting because a timer cannot be set to trigger on a more than 92 seconds interval
    tmp = remaining + lastIntCount;

    // Note that __osSetCompare takes a u32, not a u64, as a parameter.
    __osSetCompare(tmp);
    __osRestoreInt(saveMask);
}

u64 __osInsertTimer(OSTimer *newTimer)
{
    // Used to iterate over the timers
    OSTimer *node;

    u64 newRemainer;

    // The interrupt's mask.
    s32 saveMask;

    // Low priority interrupts are masked, this is how they are disabled.
    // We are entering a critical section because shared ressources are accessed.
    saveMask = __osDisableInt();

    // Iterate over the timers. If the remaining time of the new timer
    // is bigger than the remaining time of the iterated node, then decrease
    // the remaining time of the new timer.
    node = firstTimer->next;
    newRemainer = newTimer->remaining;

    while (node != firstTimer && newRemainer > node->remaining)
    {
        newRemainer -= node->remaining;

        // move forward in list
        node = node->next;
    }

    newTimer->remaining = newRemainer;

    // Decrase the remaining time of the last iterated node by the same amount
    // as the remaining time of the new timer
    if (node != firstTimer)
    {
        node->remaining -= newRemainer;
    }

    // Insert the timer in the linked list, before the last iterated node
    newTimer->next = node;
    newTimer->prev = node->prev;
    node->prev->next = newTimer;
    node->prev = newTimer;

    // Restore the interrupts with the mask
    __osRestoreInt(saveMask);
    return newRemainer;
}
