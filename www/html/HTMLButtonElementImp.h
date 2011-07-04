// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_HTMLBUTTONELEMENTIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_HTMLBUTTONELEMENTIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/HTMLButtonElement.h>
#include "HTMLElementImp.h"

#include <org/w3c/dom/html/HTMLElement.h>
#include <org/w3c/dom/NodeList.h>
#include <org/w3c/dom/html/HTMLFormElement.h>
#include <org/w3c/dom/html/ValidityState.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class HTMLButtonElementImp : public ObjectMixin<HTMLButtonElementImp, HTMLElementImp>
{
public:
    // HTMLButtonElement
    bool getAutofocus() __attribute__((weak));
    void setAutofocus(bool autofocus) __attribute__((weak));
    bool getDisabled() __attribute__((weak));
    void setDisabled(bool disabled) __attribute__((weak));
    html::HTMLFormElement getForm() __attribute__((weak));
    std::u16string getFormAction() __attribute__((weak));
    void setFormAction(std::u16string formAction) __attribute__((weak));
    std::u16string getFormEnctype() __attribute__((weak));
    void setFormEnctype(std::u16string formEnctype) __attribute__((weak));
    std::u16string getFormMethod() __attribute__((weak));
    void setFormMethod(std::u16string formMethod) __attribute__((weak));
    std::u16string getFormNoValidate() __attribute__((weak));
    void setFormNoValidate(std::u16string formNoValidate) __attribute__((weak));
    std::u16string getFormTarget() __attribute__((weak));
    void setFormTarget(std::u16string formTarget) __attribute__((weak));
    std::u16string getName() __attribute__((weak));
    void setName(std::u16string name) __attribute__((weak));
    std::u16string getType() __attribute__((weak));
    void setType(std::u16string type) __attribute__((weak));
    std::u16string getValue() __attribute__((weak));
    void setValue(std::u16string value) __attribute__((weak));
    bool getWillValidate() __attribute__((weak));
    html::ValidityState getValidity() __attribute__((weak));
    std::u16string getValidationMessage() __attribute__((weak));
    bool checkValidity() __attribute__((weak));
    void setCustomValidity(std::u16string error) __attribute__((weak));
    NodeList getLabels() __attribute__((weak));
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::HTMLButtonElement::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::HTMLButtonElement::getMetaData();
    }
    HTMLButtonElementImp(DocumentImp* ownerDocument) :
        ObjectMixin(ownerDocument, u"button") {
    }
    HTMLButtonElementImp(HTMLButtonElementImp* org, bool deep) :
        ObjectMixin(org, deep) {
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_HTMLBUTTONELEMENTIMP_H_INCLUDED