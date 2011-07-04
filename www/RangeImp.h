// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_RANGEIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_RANGEIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/ranges/Range.h>

#include <org/w3c/dom/views/ClientRectList.h>
#include <org/w3c/dom/views/ClientRect.h>
#include <org/w3c/dom/ranges/RangeException.h>
#include <org/w3c/dom/ranges/Range.h>
#include <org/w3c/dom/DOMException.h>
#include <org/w3c/dom/Node.h>
#include <org/w3c/dom/DocumentFragment.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class RangeImp : public ObjectMixin<RangeImp>
{
public:
    // Range
    Node getStartContainer() throw(DOMException) __attribute__((weak));
    int getStartOffset() throw(DOMException) __attribute__((weak));
    Node getEndContainer() throw(DOMException) __attribute__((weak));
    int getEndOffset() throw(DOMException) __attribute__((weak));
    bool getCollapsed() throw(DOMException) __attribute__((weak));
    Node getCommonAncestorContainer() throw(DOMException) __attribute__((weak));
    void setStart(Node refNode, int offset) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void setEnd(Node refNode, int offset) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void setStartBefore(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void setStartAfter(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void setEndBefore(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void setEndAfter(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void collapse(bool toStart) throw(DOMException) __attribute__((weak));
    void selectNode(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    void selectNodeContents(Node refNode) throw(ranges::RangeException, DOMException) __attribute__((weak));
    short compareBoundaryPoints(unsigned short how, ranges::Range sourceRange) throw(DOMException) __attribute__((weak));
    void deleteContents() throw(DOMException) __attribute__((weak));
    DocumentFragment extractContents() throw(DOMException) __attribute__((weak));
    DocumentFragment cloneContents() throw(DOMException) __attribute__((weak));
    void insertNode(Node newNode) throw(DOMException, ranges::RangeException) __attribute__((weak));
    void surroundContents(Node newParent) throw(DOMException, ranges::RangeException) __attribute__((weak));
    ranges::Range cloneRange() throw(DOMException) __attribute__((weak));
    std::u16string toString() throw(DOMException) __attribute__((weak));
    void detach() throw(DOMException) __attribute__((weak));
    // Range-41
    views::ClientRectList getClientRects() __attribute__((weak));
    views::ClientRect getBoundingClientRect() __attribute__((weak));
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return ranges::Range::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return ranges::Range::getMetaData();
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_RANGEIMP_H_INCLUDED