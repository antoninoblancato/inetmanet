/***************************************************************************
*
*    This library is free software, you can redistribute it and/or modify
*    it under  the terms of the GNU Lesser General Public License
*    as published by the Free Software Foundation;
*    either version 2 of the License, or any later version.
*    The library is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*    See the GNU Lesser General Public License for more details.
*
*
***************************************************************************/


#ifndef __MPLSPacket_H
#define __MPLSPacket_H

#include <omnetpp.h>
#include <stack>

using namespace std;

/**
 * Represents a packet with MPLS headers
 */
// FIXME length should be adjusted when length of label stack changes
class MPLSPacket: public cMessage
{
  private:
    typedef stack<int> LabelStack;
    LabelStack labels;

  public:
    /* constructors*/
    MPLSPacket(const char *name=NULL);
    MPLSPacket(const MPLSPacket &p);

    /* assignment operator*/
    virtual MPLSPacket& operator=(const MPLSPacket& p);

    /**
     * cloning function
     */
    virtual cObject *dup() const { return new MPLSPacket(*this); }

    /**
     * Swap Label operation
     */
    inline void swapLabel(int newLabel)  {labels.top()=newLabel;}

    /**
     * Pushes new label on the label stack
     */
    inline void pushLabel(int newLabel)  {labels.push(newLabel);}

    /**
     * Pops the top label
     */
    inline void popLabel()  {labels.pop();}

    /**
     * Returns true if the label stack is empty
     */
    inline bool noLabel()  {return labels.empty(); }

    /**
     * Returns the top label
     */
    inline int getLabel()  {return labels.top();}
};

#endif


